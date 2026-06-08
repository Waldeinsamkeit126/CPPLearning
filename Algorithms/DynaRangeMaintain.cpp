#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct FenwickMax {
    int n;
    vector<long long> bit;

    FenwickMax(int n = 0) : n(n), bit(n + 1, -1) {}

    void update(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] = max(bit[idx], val);
    }

    long long query(int idx) {
        long long res = -1;
        for (; idx > 0; idx -= idx & -idx)
            res = max(res, bit[idx]);
        return res;
    }
};

int main() {

    int N;
    long long D;
    cin >> N >> D;

    if (D == 0) {
        cout << 0 << '\n';
        return 0;
    }
    vector<pair<long long, long long>> p(N);
    vector<long long> ys;
    for (int i = 0; i < N; i++) {
        long long x, y;
        cin >> x >> y;
        p[i] = { x, y };
        ys.push_back(y);
    }
    sort(p.begin(), p.end()); // sort看pair的第一个元素；
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int M = ys.size();
    FenwickMax pref(M), suff(M);
    auto getId = [&](long long y) {
        return int(lower_bound(ys.begin(), ys.end(), y) - ys.begin()) + 1;
        };
    long long ans = (long long)4e18;
    for (auto& [x, y] : p) {
        // y' <= y - D
        long long bestX = -1;
        int pos1 = upper_bound(ys.begin(), ys.end(), y - D) - ys.begin();
        if (pos1 > 0) {
            bestX = max(bestX, pref.query(pos1));
        }
        // y' >= y + D
        int pos2 = lower_bound(ys.begin(), ys.end(), y + D) - ys.begin() + 1;
        if (pos2 <= M) {
            int revPos = M - pos2 + 1;
            bestX = max(bestX, suff.query(revPos + 1));
        }
        if (bestX != -1) {
            ans = min(ans, x - bestX);
        }
        int id = getId(y);
        pref.update(id, x);
        int rid = M - id + 1;
        suff.update(rid, x);
    }
    if (ans == (long long)4e18) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}
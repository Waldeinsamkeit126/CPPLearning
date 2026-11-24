#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int N;
    long long M;

    cin >> N >> M;

    vector<long long> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int mid = N / 2;
    vector<long long> leftSum;
    vector<long long> rightSum;

    for (int mask = 0; mask < (1 << mid); mask++) {
        long long sum = 0;

        for (int i = 0; i < mid; i++) {
            if (mask & (1 << i)) {
                sum += a[i];
            }
        }

        if (sum <= M) {
            leftSum.push_back(sum);
        }
    }

    int len = N - mid;
    for (int mask = 0; mask < (1 << len); mask++) {
        long long sum = 0;
        for (int i = 0; i < len; i++) {
            if (mask & (1 << i)) {
                sum += a[mid + i];
            }
        }
        if (sum <= M) {
            rightSum.push_back(sum);
        }
    }
    sort(rightSum.begin(), rightSum.end());
    long long ans = 0;
    for (long long x : leftSum) {
        long long remain = M - x;
        ans += upper_bound(rightSum.begin(), rightSum.end(), remain) - rightSum.begin();
    }
    cout << ans << endl;
    return 0;
}
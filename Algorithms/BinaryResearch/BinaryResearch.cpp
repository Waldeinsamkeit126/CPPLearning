#include <iostream>
#include <vector>

using namespace std;


int main() {
	long long L;
	int N, M;
	cin >> L >> N >> M;
	vector<long long > rocks(N + 2);
	rocks[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> rocks[i];
	}
	rocks[N + 1] = L;
	long long l = 0;
	long long r = L;
	long long ans = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;
		int cnt = 0;
		long long last = rocks[0];
		for (int i = 1; i <= N + 1; i++) {
			if (rocks[i] - last < mid) {
				cnt++;
			}
			else {
				last = rocks[i];
			}
		}
		if (cnt <= M) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
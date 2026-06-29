#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int boulder(const vector< int>& m) {
	int n = m.size();
	vector<vector<int>> dp(n, vector<int>(n, 19530615));
	for (int i = 0; i < n; i++) {
		dp[i][i] = m[i];
	}
	for (int left = 0; left < n - 1; left++) {
		for (int right = left; right < n; right++) {
			for (int pos = left; pos < right; pos++) {
				dp[left][right] = min(dp[left][pos] + dp[pos + 1][right], dp[left][right]);
			}
		}
	}
	return 2 * dp[0][n - 1];
}

int main() {
	vector<int> A = { 2,5,3,1 };
	cout << boulder(A);
}
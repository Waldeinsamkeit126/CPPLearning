#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int exhibition(vector<int>& A) {
	int n = A.size();
	int m = 0;
	for (int i : A) {
		m = max(m, i);
	}
	int l = 0;
	vector<int> cnt(m + 1, 0);
	int covered = 0;
	int minlen = 1000000;
	for (int r = 0; r < n; r++) {
		cnt[A[r]]++;
		if (cnt[A[r]] == 1) {
			covered++;
		}
		if (covered == m) {
			while (cnt[A[l]] != 1) {
				cnt[A[l]]--;
				l++;
			}
			minlen = min(minlen, r - l + 1);
		}
	}
	return minlen;
}

int main() {
	vector<int> A = { 1, 2, 1, 3, 2 };
	cout << exhibition(A);
}
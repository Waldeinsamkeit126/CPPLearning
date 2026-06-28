#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int flipZero(const vector<int>& A, int k) {
	int n = A.size();
	int l = 0;
	int r = 0;
	int maxOne = 0;
	for (int r = 0; r < n; r++) {
		if (A[r] == 0) {
			k--;
		}
		while (k < 0) {
			if (A[l] == 0) {
				k++;
			}
			l++;
		}
		int currentLen = r - l + 1;
		maxOne = max(maxOne, currentLen);
	}
	return maxOne;
}

int main() {
	vector<int> A = { 1,0,1,1,0,0,0,0,1,0,1,0,0,1,0,0,1 };
	cout << flipZero(A, 4);
}
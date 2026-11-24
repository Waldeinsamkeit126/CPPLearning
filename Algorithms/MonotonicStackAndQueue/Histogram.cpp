#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int histogram(const vector<int>& A) {
	vector<int>B = A;
	B.push_back(0);
	int n = B.size();
	deque<int> dq;
	int maxrec = 0;
	for (int i = 0; i < n; i++) {
		while (!dq.empty() && B[i] < B[dq.back()]) {
			int height = B[dq.back()];
			dq.pop_back();
			int l;
			if (!dq.empty()) {
				l = dq.back() + 1;
			}
			else {
				l = 0;
			}
			int vol = (i - l) * height;
			maxrec = max(maxrec, vol);
		}
		dq.push_back(i);
	}
	return maxrec;
}

int main() {
	vector<int> A = { 2,1,5,6,2,3 };
	cout << histogram(A);
}
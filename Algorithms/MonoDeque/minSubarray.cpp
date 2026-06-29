#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int minSubarray(const vector<int>& A, int T) {
	int n = A.size();
	deque<int> dq;
	vector<int> prefix(n);
	int minlen = 19530615;
	prefix[0] = A[0];
	for (int i = 1; i < n; i++) {
		prefix[i] = prefix[i - 1] + A[i];
	}
	for (int i = 0; i < n; i++) {
		while (!dq.empty() && prefix[i] - prefix[dq.front()] >= T) {
			minlen = min(minlen, i - dq.front());
			dq.pop_front();
		}
		while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
			dq.pop_back();
		}
		dq.push_back(i);
	}
	if (minlen == 19530615) {
		minlen = -1;
	}
	return minlen;
}

int main() {
	vector<int> A = { 1,-100,2,3,4,-7,10 };
	cout << minSubarray(A, 12);
}
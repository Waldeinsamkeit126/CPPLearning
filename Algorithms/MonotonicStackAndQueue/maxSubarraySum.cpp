#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int maxSubarraySum(const vector<int>& P, int m) {
	int n = P.size();
	deque<int> dq;
	vector<int> prefix(n);
	prefix[0] = P[0];
	int maxsum = 0;
	for (int i = 1; i < n; i++) {
		prefix[i] = prefix[i - 1] + P[i];
	}
	for (int i = 0; i < n; i++) {
		while (!dq.empty() && i - dq.front() >= m) {
			maxsum = max(maxsum, prefix[dq.back()] - prefix[dq.front()]);
			dq.pop_front();
		}
		while (!dq.empty() && prefix[i] < prefix[dq.back()]) {
			int r = dq.back();
			dq.pop_back();
			if (!dq.empty()) {
				maxsum = max(maxsum, prefix[r - dq.front()]);
			}
			else {
				maxsum = max(maxsum, prefix[r]);
			}
		}
		dq.push_back(i);
	}
	return maxsum;
}

int main() {
	vector<int> A = { 2,-1,2,3,-1,-2,4,-1 };
	cout << maxSubarraySum(A, 3);
}
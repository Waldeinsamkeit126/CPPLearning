#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

vector<int> nextGreater(const vector<int>& A) {
	int n = A.size();
	vector<int> ans(n,-1);
	deque<int> dq;
	for (int i = n - 1; i >= 0; i--) {
		while (!dq.empty() && dq.back() < A[i]) {
			dq.pop_back();
		}
		if (!dq.empty()) {
			ans[i]=dq.back();
		}
		dq.push_back(A[i]);
	}
	return ans;
}

int main() {
	vector<int>A = { 4, 5, 2, 25 };
	for (int i : nextGreater(A)) {
		cout << i<<" ";
	}
}
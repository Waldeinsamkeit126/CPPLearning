#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;

bool find132pattern(const vector<int>& A) {
	int n = A.size();
	deque <int> dq;
	for (int i = 0; i < n; i++) {
		if (!dq.empty() && A[dq.back()] > A[i]) {
			while (!dq.empty() && A[dq.back()] > A[i]) {
				dq.pop_back();
			}
			if (!dq.empty()) {
				return true;
			}
		}
		dq.push_back(i);
	}
	return false;
}


int main() {
	vector<int> num = { -1,3,2,0 };
	cout << find132pattern(num);
}
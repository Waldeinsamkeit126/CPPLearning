#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> tail;
	tail.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		auto it = upper_bound(tail.begin(), tail.end(), a[i]);
		if (it == tail.end()) {
			tail.push_back(a[i]);
		}
		else {
			tail[it - tail.begin()] = a[i];
		}
	}
	for (int i : tail) {
		cout << i << endl;
	}
	return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

void reclistPossiblePayments(int total, int k, vector<vector<int>>& ans, vector<int>& path, int pos) {
	if (pos == k ) {
		if (total == 0) {
			ans.push_back(path);
			return;
		}
		else {
			return;
		}
	}
	for (int i = 0; i <= total; i++) {
		path.push_back(i);
		reclistPossiblePayments(total - i, k, ans, path, pos + 1);
		path.pop_back();
	}
}


void listPossiblePayments(int total, const set<string>& people) {
	int k = 0;
	for (auto i : people) {
		k++;
	}
	vector<string> p(k);
	int cnt = 0;
	for (auto i = people.begin(); i != people.end(); i++) {
		p[cnt] = *i;
		cnt++;
	}
	vector<vector<int>> ans;
	vector<int> path;
	reclistPossiblePayments(total, k, ans, path, 0);

	for (auto i : ans) {
		for (int j = 0; j < k; j++) {
			cout << p[j] << ":" << i[j] << ",";
		}
		cout << endl;
	}
}


int main() {
	set<string> people = { "A","B","C" };
	listPossiblePayments(4, people);
}
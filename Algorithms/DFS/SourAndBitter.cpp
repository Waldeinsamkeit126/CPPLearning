#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;

void SourAndBitter(vector<int> s, vector<int> b, int& scur,int& bcur,int& anscur,int start,bool hasSelected) {
	int n = s.size();
	if (hasSelected) {
		anscur = min(anscur, abs(scur - bcur));
	}
	if (start >= n) {
		return;
	}
		int mans = min(anscur, abs(scur * s[start] - bcur + b[start]));
		int mscur = scur * s[start];
		int mbcur = bcur + b[start];
		SourAndBitter(s, b, mscur, mbcur, anscur, start + 1,true);
		SourAndBitter(s, b, scur , bcur , anscur, start + 1,hasSelected);
}

int main() {
	int n;
	cin >> n;
	vector<int> s(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> b[i];
	}
	int anscur = 19530615;
	int a = 1, c = 0;
	SourAndBitter(s, b, a, c, anscur, 0,false);
	cout << anscur;
}
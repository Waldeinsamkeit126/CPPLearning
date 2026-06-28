#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

string subsequence(const string& s) 
{
	int n = s.size();
	vector<int> cnt(26,0);
	int l = 0;
	int len = 0;
	int maxlen = 0;

	string res;
	for (int r = 0; r < n; r++) {
		cnt[s[r] - 'a']++;
		len++;
		while (cnt[s[r] - 'a'] > 1) {
			cnt[s[l] - 'a']--;
			l++;
			len--;
		}
		if (maxlen < len) {
			maxlen = len;
			res = s.substr(l, r - l + 1);
		}
	}
	return res;
}

int main() {
	cout << subsequence("abcabcbb");
}
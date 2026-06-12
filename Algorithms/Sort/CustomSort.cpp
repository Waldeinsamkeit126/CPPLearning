#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct strIn
{
	string content;
	int id;
};

bool comp(strIn A, strIn B) {
	int len = A.content.size();
	if (A.content.size() != B.content.size()) {
		return A.content.size() > B.content.size();
	}
	for (int i = 0; i < len; i++) {
		if ((A.content[i] - '0') != (B.content[i] - '0')) {
			return (A.content[i] - '0') > (B.content[i] - '0');
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<strIn> str(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> str[i].content;
		str[i].id = i;
	}
	sort(str.begin()+1, str.end(), comp);
	cout << str[1].id << endl << str[1].content;
	return 0;
}
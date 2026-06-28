#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string expansion(const int& n) {
	string res = "";
	if (n == 2) {
		res += "2";
		return res;
	}
	if (n == 1) {
		res += "2(0)";
		return res;

	}
	if (n == 0) {
		res += '0';
		return res;
	}
	int exp = 0;
	while (pow(2, exp) <= n) {
		exp++;
	}
	exp--;
	res += "2(" + expansion(exp) + ")";
	if (pow(2, exp) == n) {
		return res;
	}
	int remainder = n - pow(2, exp);
	res += "+"+expansion(remainder);
	return res;
}

int main() {
	cout << expansion(1315);
}
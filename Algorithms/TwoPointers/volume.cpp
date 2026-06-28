#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int volume(const vector<int>& height) {
	int len = height.size();
	int l = 0;
	int r = len-1;
	int maxvol = 0;
	while (l != r) {
		int vol = min(height[l], height[r]) * (r - l);
		maxvol = max(maxvol, vol);
		if (height[l] >= height[r]) {
			r--;
		}
		else {
			l++;
		}
	}
	return maxvol;
}

int main() {
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	vector<long long> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	unordered_set <long long> chosen;
	int ans = 0;
	for (long long num : nums) {
		if (num % k == 0 && chosen.count(num / k)) {
			continue;
		}
		chosen.insert(num);
		ans++;
	}
	cout << ans;
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n,sum=0;
	cin >> n;
	vector<int> nums(n+1);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if (nums[j] > nums[i])
				++sum;
	cout << sum;
	return 0;
}
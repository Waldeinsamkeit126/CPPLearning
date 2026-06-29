#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;

void findCombinationsHelper(const vector<int>& nums, int target, int start,
    vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    if (target < 0) {
        return;
    }
    int n = nums.size();
    for (int i = start; i < n; i++) {
        current.push_back(nums[i]);
        findCombinationsHelper(nums, target - nums[i], start + 1, current, result);
        current.pop_back();
    }
}

int main() {
    vector<int> nums = { 2,3,6,7 }, current;
    vector<vector<int>> result;
    findCombinationsHelper(nums, 8, 0, current, result);
    for (auto i : result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
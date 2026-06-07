#include <iostream>
#include <vector>

using namespace std;

long long mergeSort(int l, int r,vector<long long>& nums,vector<long long>& temp) {
    if (l >= r) {
        return 0;
    }
    long long ans = 0;
    int mid = (l + r ) / 2;
    ans+=mergeSort(l, mid,nums,temp);
    ans+=mergeSort(mid + 1, r,nums,temp);
    int i = l;
    int j = mid + 1;
    int k = i;
    while (i <= mid && j <= r) {
        if (nums[i] > nums[j]) {
            ans += mid - i + 1;
            temp[k++] = nums[j++];
        }
        else {
            temp[k++] = nums[i++];
        }
    }
    while (i <= mid){
        temp[k++] = nums[i++];
    }
    while (j <= r){
        temp[k++] = nums[j++];
    }
    for (int p = l; p <= r; p++) {
        nums[p] = temp[p];
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n+1);
    vector<long long> temp(n+1);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout<<mergeSort(0,n-1,nums,temp);
    return 0;
}
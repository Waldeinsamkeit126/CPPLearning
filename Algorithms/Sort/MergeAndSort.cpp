#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int mergeSort(vector<int>& A, vector<int>& sortedA, int l, int r) {
    if (l >= r) {
        return 0;
    }
    int ans = 0;
    int mid = l + (r - l) / 2;
    ans+=mergeSort(A, sortedA, l, mid);
    ans+=mergeSort(A, sortedA, mid + 1, r);
    int lpointer = l;
    int rpointer = mid + 1;
    int k = lpointer;
    while (lpointer <= mid && rpointer <= r) {
        if (A[lpointer] >= A[rpointer]) {
            ans += mid - lpointer + 1;
            sortedA[k++] = A[rpointer++];
        }
        else {
            sortedA[k++] = A[lpointer++];
        }
    }
    while (lpointer <= mid) {
        sortedA[k++] = A[lpointer++];
    }
    while (rpointer <= r) {
        sortedA[k++] = A[rpointer++];
    }
    for (int p = l; p <= r; p++) {
        A[p] = sortedA[p];
    }
    return ans;
}

int main() {
    vector<int> A = { 5,4,2,6,3,1 }, sortedA(7);
    cout << mergeSort(A, sortedA, 0, 5);
    return 0;
}
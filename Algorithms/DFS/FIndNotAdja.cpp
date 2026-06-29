#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;

void recfindNonAdjacentCombinations(const vector<int>& A,vector<int> path,int k,int start) {
	if (k == 0) {
		for(int i : path) {
			cout << i << " ";
		}
		cout << endl;
		return;
	}
	int n = A.size();
	int need = k - path.size();
	if (start >= n || n - start < need) {
		return;
	}
	path.push_back(A[start]);
	recfindNonAdjacentCombinations(A, path, k - 1, start + 2);
	path.pop_back();
	recfindNonAdjacentCombinations(A, path, k , start + 1);

}


void findNonAdjacentCombinations(const vector<int>& A,int k) {
	vector<int> path;
	recfindNonAdjacentCombinations(A, path, k, 0);
}


int main() {
	vector<int> A = { 1,2,3,4,5 };
	findNonAdjacentCombinations(A, 2);
}
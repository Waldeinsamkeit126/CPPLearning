#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int knapsack(int W, const vector<int>& w, const vector<int>& v) {
    int n = w.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W1 = 5;
    vector<int> w1 = { 2, 3, 4 };
    vector<int> v1 = { 3, 4, 5 };
    cout << knapsack(W1, w1, v1);
}
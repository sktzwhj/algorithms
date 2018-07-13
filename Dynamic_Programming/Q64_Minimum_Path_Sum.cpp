//
// Created by wu061 on 13/07/18.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT32_MAX));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) dp[i][j] = grid[0][0];
                else {
                    if (i > 0) dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i][j]);
                    if (j > 0) dp[i][j] = min(dp[i][j - 1] + grid[i][j], dp[i][j]);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> input = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution s = Solution();
    cout<<s.minPathSum(input);
}
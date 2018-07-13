//
// Created by wu061 on 13/07/18.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector <vector<int>> &obstacleGrid) {
        //finally, we need to go down by m - 1 steps and go right by n - 1 steps.
        //if there are no obstacles, the number of unique is actually the num of combinations of
        //vectors containing m - 1 1s and n - 1 0s. 1 -> down 0 -> right
        //when there is an obstacle, no path can reach that postition, so we just set the num of path to it to 0.
        //dp[i][j] is the num of different path reaching position (i, j)
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector <vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //no path can reach position (i, j)
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if (i == 0 && j == 0) dp[i][j] = 1;
                else {
                    if (i > 0) dp[i][j] += dp[i - 1][j];
                    if (j > 0) dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    vector <vector<int>> input = {{0, 0, 0},
                                  {0, 1, 0},
                                  {0, 0, 0}};
    Solution s = Solution();
    cout << s.uniquePathsWithObstacles(input);
}
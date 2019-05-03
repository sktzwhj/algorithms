//
// Created by wu061 on 3/05/19.
//

#include "headers.h"

//This problem naturally reduces to a LCS problem which has a typical dp solution.
class Solution {
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B) {
        int m = A.size(), n = B.size();
        vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    vector<int> A = {2, 5, 1, 2, 5}, B = {10, 5, 2, 1, 5, 2};
    Solution s = Solution();
    cout<<s.maxUncrossedLines(A, B);
}
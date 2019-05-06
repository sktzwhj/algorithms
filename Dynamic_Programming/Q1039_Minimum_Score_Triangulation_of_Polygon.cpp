//
// Created by wu061 on 6/05/19.
//

#include "headers.h"

// This is a tricky dp problem. The way of splitting sub-problems is to

class Solution {
public:
    int minScoreTriangulation(vector<int> &A) {
        int N = A.size();
        dp = vector<vector<int>>(N, vector<int>(N, INT32_MAX));
        minScore(A, 0, N - 1);
        return dp[0][N - 1];
    }

private:
    vector<vector<int>> dp;
    //minScore(A, i, j) is the smallest area for the polygon  (i, j)
    int minScore(vector<int> &A, int i, int j) {
        if (j - i < 2) return 0;
        if (dp[i][j] != INT32_MAX) return dp[i][j];
        int N = A.size();
        for (int k = i + 1; k < j; ++k) {
            dp[i][j] = min(dp[i][j], minScore(A, i, k) + A[i] * A[j] * A[k] + minScore(A, k, j));
        }
        return dp[i][j];
    }
};


int main() {
    vector<int> tri = {1, 3, 1, 4, 1, 5};
    Solution s = Solution();
    cout << s.minScoreTriangulation(tri) << endl;
}
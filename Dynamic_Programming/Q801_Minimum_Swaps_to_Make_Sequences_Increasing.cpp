//
// Created by wu061 on 18/10/18.
//

#include "headers.h"

class Solution {
public:
    int minSwap(vector<int> &A, vector<int> &B) {
        int vec_len = A.size();
        /*dp[i][0]: the cost if do not exchange at position i. dp[i][1]: the cost of changing at position i*/
        vector <vector<int>> dp = vector < vector < int >> (vec_len, vector<int>(2, INT32_MAX));
        dp[0][0] = 0;
        dp[0][1] = 1;
        for (int i = 1; i < vec_len; ++i) {
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                /*condition already satisfied, no change. if last position has changed,
                 the current one needs to change to keep ascending order*/
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1] + 1;
            }
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                /*if change is not harmful, you can either change the last position or not */
                dp[i][0] = min(dp[i][0], dp[i - 1][1]);
                dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
            }
        }

        return min(dp[vec_len - 1][0], dp[vec_len - 1][1]);
    }
};

int main() {
    Solution s = Solution();
    vector<int> A = {0, 4, 4, 5, 9}, B = {0, 1, 6, 8, 10};
    cout << s.minSwap(A, B) << endl;
}
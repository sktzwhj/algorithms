//
// Created by wu061 on 4/06/19.
//

#include "headers.h"

class Solution {
public:
    int maxSumAfterPartitioning(vector<int> &A, int K) {
        //dp[i] is the result for sub-vector A[0:i] where i is not included
        vector<int> dp(A.size() + 1, 0);
        for (int i = 1; i <= A.size(); ++i) {
            //k is the size of a partition
            int curr_max = 0;
            for (int k = 1; (k <= K) && (i - k >= 0); ++k) {
                curr_max = max(curr_max, A[i - k]);
                dp[i] = max(dp[i], dp[i - k] + curr_max * k);
            }
        }
        return dp[A.size()];
    }

};

int main() {
    vector<int> input = {1, 15, 7, 9, 2, 5, 10};
    Solution s = Solution();
    cout << s.maxSumAfterPartitioning(input, 3);
}
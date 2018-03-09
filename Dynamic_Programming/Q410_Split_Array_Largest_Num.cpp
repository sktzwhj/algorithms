//
// Created by wu061 on 9/03/18.
//

#include <vector>
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

/*
 * looks quite a dp problem, so the task is how to design the sub problem.
 * let's use dp[i][j] to denote the max sum when splitting j parts for array[0:i]
 * so if we have already had j - 1 parts splitted and the last split point is k, for a new split decision,
 * dp[i][j] = max(dp[k - 1][j - 1], sum_new) where sum_new = sum(array[k:i])
 */

class Solution {
public:
    int splitArray(vector<int> &nums, int m) {
        int INT_MAX = numeric_limits<int>::max();
        int num_size = nums.size();
        //we first compute the sum first to avoid redundant computation
        vector<int> sum(num_size, 0);
        for (int i = 0; i < num_size; i++) sum[i] = (i == 0) ? nums[0] : (sum[i - 1] + nums[i]);
        //then we initialize the dp vector
        vector <vector<int>> dp(num_size, vector<int>(m + 1, INT_MAX));
        for (int i = 0; i < num_size; i++) {
            int max_split_point = min(m, i + 1);
            for (int j = 1; j <= max_split_point; j++) {
                if (j == 1) {
                    dp[i][j] = sum[i];
                    continue;
                }
                for (int k = i; k >= j - 1; k--) {
                    int new_part = sum[i] - sum[k] + nums[k];
                    if (new_part > dp[i][j]) break;
                    dp[i][j] = min(dp[i][j], max(new_part, dp[k - 1][j - 1]));
                }

            }
        }
        return dp[nums.size() - 1][m];
    }

};


int main() {
    int a[] = {7, 2, 4, 10, 6};
    vector<int> input(a, a + 5);
    Solution s = Solution();
    cout << s.splitArray(input, 2);

}
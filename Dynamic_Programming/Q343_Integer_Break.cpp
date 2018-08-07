//
// Created by wu061 on 7/08/18.
//

#include "headers.h"

//typical dp. but the trick is how to deal with 1 and 2.
//when dp[i] is used to form the answer for dp[k] where k > i, you need to either use i or dp[i] depending on which is bigger

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 2) return 1;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i - 1; j++) {
                dp[i] = max(max(dp[j], j) * max(dp[i - j], i - j), dp[i]);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s = Solution();
    cout << s.integerBreak(5);
}
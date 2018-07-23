//
// Created by wu061 on 23/07/18.
//

#include "headers.h"

class Solution {
public:
    //this is a typical dynamic programming. the solution is to reverse the string then it transforms to
    //longest common subsequence problem.
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;
        string s_reverse(s.rbegin(), s.rend());
        return longestCommonSubseq(s, s_reverse);
    }

    int longestCommonSubseq(string l, string r) {
        vector <vector<int>> dp(l.size() + 1, vector<int>(r.size() + 1, 0));
        for (int i = 1; i <= l.size(); i++) {
            for (int j = 1; j <= r.size(); j++) {
                if (l[i - 1] == r[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[l.size()][r.size()];
    }
};

int main() {
    string input = "bbbab";
    Solution s = Solution();
    cout << s.longestPalindromeSubseq(input);
}
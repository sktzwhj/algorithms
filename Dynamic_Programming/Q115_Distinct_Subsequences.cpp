//
// Created by wu061 on 27/02/18.
//

#include <string>
#include <bitset>
#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

/*
 * Given a string S and a string T, count the number of distinct subsequences of S which equals T.
 * This is again, a dynamic programming problem.
 */

/*
 * firstly a memorization based top down solution, get TLE. did not use vector<bool> due to its performance issues.
 */

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> mask(s.size());
        for(int i = 0; i < s.size(); i++) mask[i] = 1;
        helper(s,t, mask);
        return total;
    }

    void helper(string s, string t, vector<int> mask){
        if(masks.count(mask) > 0) {
            return;
        }
        masks.insert(mask);
        if(t.size() > s.size()){
            return;
        }
        if(s == t){
            total++;
            return;
        }
        for(int i = 0; i < s.size(); i++){
            string tmp = s;
            vector<int> tmp_mask = mask;
            tmp.erase(tmp.begin() + i);
            int cnt = 0;
            for(int j = 0; j < tmp_mask.size(); j++){
                if(tmp_mask[j]) {
                    if(cnt == i){
                        tmp_mask[j] = 0;
                        break;
                    }
                    cnt++;
                }

            }
            helper(tmp,t,tmp_mask);
        }
    }

private:
    int total = 0;
    set<vector<int>> masks;
};

/*
 * then a down-top dynamic programming solution
 */


class Solution {
public:
    int numDistinct(string S, string T) {
        int dp[T.size() + 1][S.size() + 1];
        for (int i = 0; i <= S.size(); ++i) dp[0][i] = 1;
        for (int i = 1; i <= T.size(); ++i) dp[i][0] = 0;
        for (int i = 1; i <= T.size(); ++i) {
            for (int j = 1; j <= S.size(); ++j) {
                dp[i][j] = dp[i][j - 1] + (T[i - 1] == S[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }
        return dp[T.size()][S.size()];
    }
};


int main()
{
    string a = "rabbbit", b = "rabbit";
    Solution s = Solution();
    cout<<s.numDistinct(a,b);
}
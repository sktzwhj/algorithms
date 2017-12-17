//
// Created by wuhuijun on 12/17/17.
//

#include<string>
#include<vector>
#include<iostream>
#include<set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() + 1,0);
        dp[0] = 1;
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && wordSet.find(s.substr(j,i-j))!=wordSet.end()){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main()
{
    vector<string> wordDict = {"leet","code"};
    Solution s = Solution();
    cout<<s.wordBreak("leetcode",wordDict);
}
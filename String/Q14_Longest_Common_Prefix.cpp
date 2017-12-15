//
// Created by wuhuijun on 12/15/17.
//

#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return string();
        vector<pair<char, int>> prefixCnt = vector<pair<char, int>>();
        int maxPossibleLen = prefixCnt.size();
        for (char c:strs[0])prefixCnt.push_back({c, 1});
        for (int i = 1; i < strs.size(); i++)
            for (int j = 0; j < maxPossibleLen; j++) {
                if (strs[i][j] == prefixCnt[j].first) {
                    prefixCnt[j].second++;
                } else {
                    maxPossibleLen = j;
                    break;
                }
            }
        return string(strs[0].substr(0,maxPossibleLen));
    }

};
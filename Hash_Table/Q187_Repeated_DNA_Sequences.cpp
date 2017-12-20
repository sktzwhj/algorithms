//
// Created by wuhuijun on 12/19/17.
//
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    vector <string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> strIndexMap;
        vector <string> retVec;
        set <string> ret;

        int start = 0, end = 9;
        while (end < s.size()) {
            //cout<<s.substr(start,10)<<endl;
            if (strIndexMap.find(s.substr(start, 10)) != strIndexMap.end()) {
                ret.insert(s.substr(start, 10));
            } else {
                strIndexMap[s.substr(start, 10)] = start;
            }
            start++;
            end++;
        }
        for (string s:ret)
            retVec.push_back(s);
        return retVec;
    }
};

int main() {
    Solution s = Solution();
    vector <string> result = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (auto str:result)
        cout << str << endl;
}


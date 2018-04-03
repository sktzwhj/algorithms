//
// Created by wu061 on 3/04/18.
//

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        map<string, int> charFreqMap;
        string ret = "";
        for (auto c:S) charFreqMap[string(1, c)]++;
        vector<pair<string, int>> charFreq(charFreqMap.begin(), charFreqMap.end());
        sort(charFreq.begin(), charFreq.end(),
             [](pair<string, int> a, pair<string, int> b) { return a.second > b.second; });
        int maxFreq = (*(charFreq.begin())).second;
        //cout << maxFreq << endl;
        if ((maxFreq * 2 - 1) > S.size()) return ret;
        vector<string> substring(maxFreq);
        int cnt = 0;
        for (auto it = charFreq.begin(); it != charFreq.end(); it++) {
            string tmp = (*it).first;
            int tmp_cnt = (*it).second;
            for (int i = tmp_cnt; i > 0; i--) {
                substring[(cnt++) % maxFreq] += tmp;
            }
        }
        for (int j = 0; j < maxFreq; j++) ret += substring[j];
        return ret;
    }
};

int main() {
    string S = "aab";
    Solution s = Solution();
    cout << s.reorganizeString(S);
}
//
// Created by wu061 on 25/07/18.
//

#include "headers.h"

class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, vector<int>> appear_pos;
        for (int i = 0; i < S.size(); i++) {
            appear_pos[S[i]].push_back(i);
        }
        vector<int> res;
        int curr = 0;
        while (curr < S.size()) {
            vector<int> pos = appear_pos[S[curr]];
            int last_pos = pos[pos.size() - 1];
            for (int i = curr; i < last_pos; i++) {
                if (appear_pos[S[i]][appear_pos[S[i]].size() - 1] > last_pos) {
                    last_pos = appear_pos[S[i]][appear_pos[S[i]].size() - 1];
                }
            }
            res.push_back(last_pos + 1 - curr);
            curr = last_pos + 1;
        }
        return res;
    }
};

int main() {
    string input = "ababcbacadefegdehijhklij";
    Solution s = Solution();
    for (auto val : s.partitionLabels(input)) {
        cout << val << endl;
    }
}
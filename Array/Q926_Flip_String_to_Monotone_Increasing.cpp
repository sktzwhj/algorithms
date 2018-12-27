//
// Created by wu061 on 27/12/18.
//

#include "headers.h"

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        vector<int> one_cnt(S.size(), 0), zero_cnt(S.size(), 0);
        int zeros = 0, ones = 0;
        int min_flip = INT32_MAX;
        for (int i = 0; i < S.size(); ++i) {
            one_cnt[i] = ones;
            if (S[i] == '1') {
                ones++;
            }
        }

        for (int j = S.size() - 1; j >=0; --j) {
            zero_cnt[j] = zeros;
            if (S[j] == '0') {
                zeros++;
            }
        }

        for (int k = 0; k < S.size(); ++k) {
            min_flip = min(min_flip, one_cnt[k] + zero_cnt[k]);
        }
        return min_flip;
    }
};

int main() {
    string input = "0101100011";
    Solution s = Solution();
    cout<<s.minFlipsMonoIncr(input);
}
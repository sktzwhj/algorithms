//
// Created by wuhuijun on 1/7/19.
//

#include "headers.h"

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;
        int val_buf = 0;
        int start = (N == 1) ? 0 : 1;
        for (int i = start; i <= 9; ++i) {
            dfs(i, i, N - 1, K, res);
        }
        set<int> dedup(res.begin(), res.end());
        return vector<int>(dedup.begin(), dedup.end());
    }

private:
    void dfs(int val_buf, int curr_digit, int N, int K, vector<int> &res) {
        if (N == 0) {
            res.push_back(val_buf);
            return;
        }
        if (curr_digit + K <= 9) dfs(val_buf * 10 + curr_digit + K, curr_digit + K, N - 1, K, res);
        if (curr_digit - K >= 0) dfs(val_buf * 10 + curr_digit - K, curr_digit - K, N - 1, K, res);
    }
};

int main() {
    Solution s = Solution();
    vector<int> res = s.numsSameConsecDiff(2, 1);
    for (auto val : res) {
        cout << val << endl;
    }
}
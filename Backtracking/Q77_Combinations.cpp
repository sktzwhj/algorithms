//
// Created by wuhuijun on 7/2/18.
//

#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> selected;
        helper(n, k, selected, 1);
        return vector<vector<int>>(res.begin(), res.end());
    }

private:
    vector<vector<int>> res;

    void helper(int n, int k, vector<int> &selected, int start) {
        if (k == 0) {
            res.push_back(selected);
        } else {
            for (int i = start; i <= n; i++) {
                selected.push_back(i);
                helper(n, k - 1, selected, i + 1);
                selected.pop_back();
            }
        }
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> ret = s.combine(4, 2);
    for (auto vec:ret) {
        for (auto val:vec) {
            cout << val;
        }
        cout << endl;
    }
}

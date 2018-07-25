//
// Created by wu061 on 24/07/18.
//

#include "headers.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        helper(0, nums, curr, res);
        set<vector<int>> s(res.begin(), res.end());
        res.assign(s.begin(), s.end());
        return res;
    }

private:
    void helper(int idx, vector<int> &nums, vector<int> &curr, vector<vector<int>> &res) {
        //two choices, add nums[idx] or not
        if (idx == nums.size()) {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        helper(idx + 1, nums, curr, res);
        curr.pop_back();
        helper(idx + 1, nums, curr, res);
    }
};

int main() {
    vector<int> input = {4, 3, 1, 2, 2};
    Solution s = Solution();
    vector<vector<int>> res = s.subsetsWithDup(input);
    for (auto vec : res) {
        for (auto ele : vec) {
            cout << ele << " ";
        }
        cout << endl;
    }
}
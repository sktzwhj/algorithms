//
// Created by wu061 on 30/06/18.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while (next_permutation(nums.begin(), nums.end())) {
            res.push_back(nums);
        }
        return res;
    }
};

int main() {
    vector<int> input = {-1, 0, 1};
    Solution s = Solution();
    for (auto vec:s.permute(input)) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}
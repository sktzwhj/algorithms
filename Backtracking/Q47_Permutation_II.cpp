//
// Created by wu061 on 30/06/18.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        set<vector<int>> res_set;
        sort(nums.begin(), nums.end());
        res_set.insert(nums);
        while (next_permutation(nums.begin(), nums.end())) {
            res_set.insert(nums);
        }
        return vector<vector<int>>(res_set.begin(), res_set.end());
    }
};

int main() {
    vector<int> input = {-1, 0, 1};
    Solution s = Solution();
    for (auto vec:s.permuteUnique(input)) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}
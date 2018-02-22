//
// Created by wuhuijun on 1/7/18.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//a simple problem. binary search.

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> ret;
        if (nums.size() > 0) {
            auto lowerBound = lower_bound(nums.begin(), nums.end(), target);
            auto upperBound = upper_bound(nums.begin(), nums.end(), target);
            int start = lowerBound - nums.begin();
            int end = upperBound - nums.begin();
            if (start < nums.size() && end > 0 && nums[start] == target) {
                ret.push_back(start);
                ret.push_back(end - 1);
                return ret;
            }
        }
        ret.push_back(-1);
        ret.push_back(-1);
        return ret;
    }
};

int main() {
    int a[] = {2, 2};
    Solution s = Solution();
    vector<int> input(a, a + 2);
    for (auto i:s.searchRange(input, 3)) {
        cout << i << endl;
    }
}

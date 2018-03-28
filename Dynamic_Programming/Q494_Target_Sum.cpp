//
// Created by wu061 on 28/03/18.
//

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * dp seems to be a typical solution to solve this.
 * Let N(start, end, target) denote the num of solutions which achieves target by adding symbols between [start:end]
 * then we have N(start, end, target) = N(start, end - 1, target - nums[end]) + N(start, end - 1, target + nums[end])
 */

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        return helper(nums, nums.size() - 1, S);
    }

private:
    int helper(vector<int> &nums, int end, int target) {
        if (end == 0) {
            return ((nums[end] == target) ? 1 : 0) + ((-nums[end] == target) ? 1 : 0);
        }
        return helper(nums, end - 1, target - nums[end]) + helper(nums, end - 1, target + nums[end]);
    }
};

int main() {
    int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 1};
    vector<int> input(a, a + 9);
    Solution s = Solution();
    cout << s.findTargetSumWays(input, 1);
}
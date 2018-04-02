//
// Created by wu061 on 2/04/18.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ret;
        if (nums.size() < 3) return ret;
        sort(nums.begin(), nums.end());
        int target = 0, start = 0, end = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            target = 0 - nums[i];
            start = i + 1;
            end = nums.size() - 1;
            while (start < end) {
                int tmp_sum = nums[start] + nums[end];
                if (tmp_sum == target) {
                    ret.push_back({nums[i], nums[start], nums[end]});
                    while (start < (nums.size() - 1) && nums[start] == nums[start + 1]) start++;
                    while (end > 0 && nums[end] == nums[end - 1]) end--;
                    start++;
                    end--;
                } else if (tmp_sum < target) {
                    start++;
                } else {
                    end--;
                }
            }
        }
        return ret;
    }
};


int main() {
    int a[] = {-1, 0, 1, 2, -1, -4};
    vector<int> input(a, a + 6);
    Solution s = Solution();
    s.threeSum(input);
}
//
// Created by WuHuijun on 29/8/18.
//

#include "headers.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> pre_sum;
        int curr_sum = 0;
        int res = 0;
        pre_sum[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            curr_sum += nums[i];
            if (pre_sum.find(curr_sum - k) != pre_sum.end()) {
                res += pre_sum[curr_sum - k];
            }
            pre_sum[curr_sum] += 1;
        }
        return res;
    }
};

int main() {
    vector<int> input = {1, 1, 1};
    Solution s = Solution();
    cout<<s.subarraySum(input, 2);
}
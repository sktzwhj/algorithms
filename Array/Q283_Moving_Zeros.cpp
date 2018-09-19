//
// Created by wuhuijun on 9/19/18.
//

#include "headers.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_cnt = 0, i = 0;
        while(i < nums.size()) {
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i);
                ++zero_cnt;
                continue;
            } else {
                ++i;
            }
        }
        while(zero_cnt > 0) {
            nums.push_back(0);
            --zero_cnt;
        }
    }
};
//
// Created by wuhuijun on 10/10/17.
//

#include<vector>
#include<iostream>
#include<limits>

using namespace std;


class Solution {
public:
    int imin = std::numeric_limits<int>::min();

    //int imax = std::numeric_limits<int>::max();
    int findPeakElement(vector<int> &nums) {
        int start = -1, end = nums.size(), left, end, potentialPeakIdx ;
        if (nums.size() == 1)
            return 0;

        bool findFlag = 0;
        while (1) {
            potentialPeakIdx = (start + end) / 2;

            if (potentialPeakIdx > 0)
                left = nums[potentialPeakIdx - 1];
            else
                left = imin;

            if (potentialPeakIdx < nums.size() - 1)
                right = nums[potentialPeakIdx + 1];
            else
                right = imin;

            if (nums[potentialPeakIdx] > left && nums[potentialPeakIdx] > right)
                return potentialPeakIdx;
            else {
                if (nums[potentialPeakIdx] < right)
                    start = potentialPeakIdx;
                else
                    end = potentialPeakIdx;
            }

        }

    }
};

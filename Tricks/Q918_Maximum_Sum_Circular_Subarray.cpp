//
// Created by wu061 on 4/11/18.
//

#include "headers.h"

class Solution {
public:
    int maxSubarraySumCircular(vector<int> &A) {
        //the idea is ans = max subarray (continous) or 1 - min(continous)
        int cur_max = 0, cur_min = 0, total = 0;
        int max_sum = INT32_MIN, min_sum = INT32_MAX;
        int ans = INT32_MIN;
        int individual_max = *max_element(A.begin(), A.end());
        bool all_neg = true;
        for (int val : A) {
            if (val >= 0) all_neg = false;
            //if curr_max + val < val then the sequence should cut here
            cur_max = max(cur_max + val, val);
            max_sum = max(max_sum, cur_max);
            cur_min = min(cur_min + val, val);
            min_sum = min(min_sum, cur_min);
            total += val;
        }
        if (all_neg) return individual_max;
        return max(total - min_sum, max_sum);
    }

};

int main() {
    Solution s = Solution();
    vector<int> input({-2, -3, -1});
    cout<<s.maxSubarraySumCircular(input);
}
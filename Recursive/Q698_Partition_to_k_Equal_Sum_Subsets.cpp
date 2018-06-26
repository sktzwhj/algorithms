//
// Created by wuhuijun on 6/27/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int nums_size = nums.size();
        int bucket_target_sum = accumulate(nums.begin(), nums.end(), 0) / k;
        vector<int> bucket_sum(k, 0);
        //sorting helps us to fail earlier
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        return dfs(bucket_sum, 0, nums, bucket_target_sum);
    }

    bool dfs(vector<int> &bucket_sum, int idx, vector<int> &nums, int bucket_target_sum) {
        if (idx == nums.size()) return true;
        if (nums[idx] > bucket_target_sum) return false;
        for (int i = 0; i < bucket_sum.size(); i++) {
            if (bucket_sum[i] + nums[idx] <= bucket_target_sum) {
                bucket_sum[i] += nums[idx];
                if (dfs(bucket_sum, idx + 1, nums, bucket_target_sum)) return true;
                bucket_sum[i] -= nums[idx];
            }
        }
        return false;
    }
};


int main() {
    vector<int> input = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    Solution s = Solution();
    cout << s.canPartitionKSubsets(input, 5) << endl;
}
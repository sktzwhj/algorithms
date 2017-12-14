//
// Created by wu061 on 15/12/17.
//

#include<vector>
#include<iostream>
using namespace std;


/*
 * an implementation of the greedy algorithm in the following reference.
 * https://www.cs.princeton.edu/courses/archive/spring13/cos423/lectures/LongestIncreasingSubsequence.pdf
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> dp = vector<int>();
        dp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            bool flag = false;
            for(int j = 0; j < dp.size(); j++){
                if(nums[i] <= dp[j]){
                    dp[j] = nums[i];
                    flag = true;
                    break;
                }
            }
            if(!flag)dp.push_back(nums[i]);
        }
        return dp.size();
    }
};

int main()
{
    int a[] = {2,2,};
    vector<int> input = vector<int>(a,a+2);
    Solution s = Solution();
    cout<<s.lengthOfLIS(input);
}
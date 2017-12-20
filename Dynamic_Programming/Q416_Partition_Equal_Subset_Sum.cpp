''//
// Created by wu061 on 20/12/17.
//
#include<vector>
#include<iostream>
using namespace std;

/*
 * this problem is essentially about whether you can select some numbers in the array where their sum is N/2, very similar
 * to 0/1 knapsack problem. so we use dynamic programming. It is weird that my vanilla dp implementation of 0/1 knapsack
 * implementation get TLE. awkward...
 * another dp solution
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i:nums) sum += i;
        if(sum %2 == 1) return false;
        vector<vector<bool>> dp = std::vector<vector<bool>>(nums.size(), vector<bool>(sum/2, false));
        for(int i = 0; i < nums.size(); i++) dp[i][0] = true;
        for(int j = 1; j <= sum/2; j++) dp[0][j] = false;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 1; j <= sum/2; j++){
                dp[i][j] = dp[i-1][j];
                if(j >= nums[i])
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
            }
        }
        return dp[nums.size()-1][sum/2];
    }

};
int main() {
    vector<int> input({67,95,58,76,19,60,20,17,23,23,67,85,8,67,81,65,73,92,59,97,45,94,26,90,70,45,24,52,25,43,2,83,15,25,66,87,77,11,46,75,46,59,17,84,11,64,9,74,65,78,85,3,87,81,67,37,79,50,14,88,55,45,58,31,75,74,13,2,60,51,94,82,63,90,25,60,86,12,42,78,33,8,50,84,86,71,46,47,15,86,56,64,8,26,34,21,21,24,49,16});
    Solution s = Solution();
    cout << s.canPartition(input);
}


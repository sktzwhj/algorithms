//
// Created by wu061 on 22/09/17.
//

#include<vector>
#include<iostream>
using namespace std;

/*
 * seems this is a typical dynamic programming problem.
 * the spirit of dynamic programming is to use some space to store the partial results which might be recomputed for several times.
 */

class Solution {
public:
    int maxCoins(vector<int>& nums)
    {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return maxCoinsIter(nums);
    }

    int maxCoinsIter(vector<int>& nums) {
        int tmp_max = 0;
        if(nums.size()==2)
            return 0;
        if(nums.size() == 3)
            return nums[1];
        else
        {
            int choiceCoins[nums.size()];
            for(int k = 0; k < nums.size(); k++)
                choiceCoins[k] = 0;

            for(int i = 1; i < nums.size() - 1; i++)
            {
                int coinCurBalloon = nums[i];
                int coinThisRound = nums[i-1]*nums[i]*nums[i+1];
                vector<int> tmp_input = nums;
                tmp_input.erase(tmp_input.begin()+i);
                int coinsRestBallon = maxCoinsIter(tmp_input);
                choiceCoins[i] = coinThisRound + coinsRestBallon;
            }

            for(int j = 1; j < nums.size() - 1; j++){
                if(choiceCoins[j] > tmp_max){
                    tmp_max = choiceCoins[j];
                }
            }


        }
        return tmp_max;

    }
};


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size() , 0));
        return burst(nums, dp, 1 , n);
    }
    int burst(vector<int> &nums, vector<vector<int> > &dp, int left, int right) {
        if (left > right) return 0;
        if (dp[left][right] > 0) return dp[left][right];
        int res = 0;
        for (int k = left; k <= right; ++k) {
            res = max(res, nums[left - 1] * nums[k] * nums[right + 1] + burst(nums, dp, left, k - 1) + burst(nums, dp, k + 1, right));
        }
        dp[left][right] = res;
        return res;
    }
};

int main(){
    int a[] = {7,9,8,3};
    vector<int> input(a,a+4);
    Solution s = Solution();
    cout<<s.maxCoins(input);

}
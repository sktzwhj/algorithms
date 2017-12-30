//
// Created by wuhuijun on 12/30/17.
//
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount + 1, amount + 1);
        res[0] = 0;
        for(int p = 1; p <= amount; p++){
            for(int q = 0; q < coins.size(); q++)
                if(p >= coins[q])res[p] = min(res[p], res[p - coins[q]] + 1);
        }
        return (res[amount] > amount)?-1:res[amount];
    }
};

int main()
{
    int coins[1] = {2147483647};
    vector<int> input = vector<int>(coins, coins + 1);
    Solution s = Solution();
    cout<<s.coinChange(input,2);

}


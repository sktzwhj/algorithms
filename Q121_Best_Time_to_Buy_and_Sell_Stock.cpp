//
// Created by wu061 on 22/09/17.
//
/*
 * Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */

#include<vector>
using namespace std;
#include<iostream>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        vector<int> min_price(prices.size(),-1);
        min_price[0] = prices[0];
        int max_profit = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i]<min_price[i-1])
                min_price[i] = prices[i];
            else
                min_price[i] = min_price[i-1];
            if(prices[i] > min_price[i-1])
            {
                int tmp_profit = prices[i]-min_price[i-1];
                max_profit = (max_profit>tmp_profit)?max_profit:(tmp_profit);
            }
        }
        return max_profit;
    }
};

int main()
{
    Solution s = Solution();
    int n[] = {1,2};
    vector<int> input(n, n+2);
    cout<<s.maxProfit(input);
}
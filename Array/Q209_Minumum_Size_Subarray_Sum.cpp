//
// Created by wuhuijun on 11/21/17.
//
#include<vector>
#include<limits>
#include<iostream>

using namespace std;

//use two pointers to solve the problem

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int p1 = 0, p2 = 0;
        int curSum = 0;
        int len = nums.size();
        int minLen = numeric_limits<int>::max();
        while (p1 < len) {

            while (p2 < len) {
                //cout<<"p1:"<<p1<<" "<<"p2:"<<p2<<endl;
                //cout<<curSum<<endl;
                if (curSum < s) {
                    curSum += nums[p2];
                    p2++;
                }
                else
                    break;
            }
            if (curSum >= s&&(p2 - p1) < minLen)
                minLen = p2 - p1;
            //p2 does not need to start from new p1, just deduct nums[p1] from the old curSum value
            curSum -= nums[p1];
            p1++;
        }
        return (minLen < numeric_limits<int>::max())?minLen:0;

    }
};


int main() {
    int a[] = {2, 3, 1, 2, 4, 3};
    vector<int> input = vector<int>(a, a + 6);
    Solution s = Solution();
    cout << s.minSubArrayLen(7, input);

}

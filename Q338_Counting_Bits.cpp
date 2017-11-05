//
// Created by wuhuijun on 11/5/17.
//
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret = vector<int>();
        for(int i = 0; i <= num; i++)
        {
            ret.push_back(getNumOfOne(i));
        }
        return ret;

    }
private:
    int getNumOfOne(int num)
    {
        int oneCnt = 0;
        while(1)
        {
            if(num%2 == 1)
            {
                oneCnt++;
            }
            if(num/2 == 0)
                break;
            num /= 2;
        }
        return oneCnt;
    }
};

int main()
{
    Solution s = Solution();
    for(auto e:s.countBits(5))
        cout<<e;

}

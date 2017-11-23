//
// Created by wuhuijun on 11/16/17.
//
/*
 * requires debugging
 */
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal <= maxChoosableInteger)
            return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
            return false;
        int remain = desiredTotal;
        int mask = 0;
        //let player 1 to play first

        return oneStep(remain, mask, maxChoosableInteger);


    }
    bool oneStep(int remain, int mask, int maxChoosableInteger)
    {
        if(history.find(mask) != history.end())
            return history[mask];
        for(int i = 0; i < maxChoosableInteger; i++){
            int curr = (1<<i);
            if((curr&mask)==0){
                /*
                 * made a stupid mistake here ealier. remain and mask are still used in later loops so that we cannot
                 * change them.
                 */
                if(remain <= (i+1) || !oneStep(remain - (i+1), mask|curr, maxChoosableInteger)){
                    history[mask] = true;
                    return true;
                }
            }
        }
        history[mask] = false;
        return false;
    }

private:
    unordered_map<int,bool> history = unordered_map<int,bool>();
};

int main()
{
    Solution s = Solution();
    cout << s.canIWin(10,11);
}

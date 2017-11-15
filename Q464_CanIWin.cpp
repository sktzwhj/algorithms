//
// Created by wuhuijun on 11/16/17.
//
/*
 * requires debugging
 */
#include<unordered_map>
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
        int run = 0;
        //let player 1 to play first

        return oneStep(remain, mask, maxChoosableInteger, run);


    }
    bool oneStep(int remain, int mask, int maxChoosableInteger, int run)
    {
        if(history.find(mask) != history.end())
            return history[mask];
        for(int i = 1; i <= maxChoosableInteger; i++){
            if((1 << i)&mask==0){
                if(remain <= i){
                    mask |=(1<<i);
                    return true;
                }
                else{
                    mask = mask|(1<<i);
                    remain -= i;
                    history[mask] = oneStep(remain, mask, maxChoosableInteger, run);
                    if(history[mask]==1){
                        return false;
                    }
                    else
                        return true;
                }

            }
        }
        return false;
    }

private:
    unordered_map<int,bool> history = unordered_map<int,bool>();
};
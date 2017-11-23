//
// Created by wu061 on 23/09/17.
//

#include<vector>
#include<stdlib.h>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> numsPtr;
    Solution(vector<int> nums) {
        numsPtr = nums;
    }

    int pick(int target) {
        int retIndex = -1;
        int findCnt = 0;
        for(int j = 0; j < numsPtr.size(); j++)
        {
            cout<<numsPtr[j]<<" "<<target<<endl;
            if(numsPtr[j]==target)
            {
                findCnt++;

                int randnum = rand()%(findCnt);
                if(randnum == 0)
                    retIndex = j;
            }
        }
        return retIndex;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
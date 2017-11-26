//
// Created by wu061 on 22/09/17.
//

#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int last_num = 0;
        for(vector<int>::iterator it = nums.begin();it!=nums.end();it++)
        {
            if(*it==last_num)
                return last_num;
            else
                last_num = *it;
        }

    }
};
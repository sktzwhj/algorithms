//
// Created by wu061 on 13/12/17.
//

#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> res = vector<int>(nums.size(), 0);
        res[0] = nums[0];
        res[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            res[i] = max(res[i- 2] + nums[i], res[i-1]);
        }
        return res[nums.size()-1];
    }
};
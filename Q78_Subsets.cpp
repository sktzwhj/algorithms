//
// Created by wuhuijun on 10/9/17.
//

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void generate(vector<vector<int>> &res, vector<int>& nums, int pos, vector<int> vec)
    {
        res.push_back(vec);
        for(int i = pos; i < nums.size(); i++)
        {
            vec.push_back(nums[i]);
            generate(res, nums, i+1, vec);
            vec.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        sort(nums.begin(),nums.end());
        generate(res, nums, 0, out);
        return res;
    }
};
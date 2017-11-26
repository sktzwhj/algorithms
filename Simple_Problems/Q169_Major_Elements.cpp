//
// Created by wu061 on 25/11/17.
//
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> numCntMap = unordered_map<int,int>();
        for(int i = 0; i < nums.size(); i++){
            if(numCntMap.find(nums[i])!=numCntMap.end()){
                numCntMap[nums[i]]++;
            }
            else{
                numCntMap[nums[i]] = 1;
            }
            if(numCntMap[nums[i]] > nums.size()/2) return nums[i];
        }

    }
};

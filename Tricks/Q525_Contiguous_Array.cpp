//
// Created by wu061 on 13/12/17.
//

#include<vector>
#include<unordered_map>
using namespace std;

//accumulator is a good thing to solve this kind of problems

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //this hashmap maintains the index between sum and indices in the vec
        unordered_map<int,int> sumIndexMap = unordered_map<int,int>();
        int accu = 0, maxLen = 0;
        sumIndexMap[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]) accu += 1;
            else accu -= 1;
            if(sumIndexMap.find(accu) == sumIndexMap.end())
                sumIndexMap[accu] = i;
            else{
                int tmpLen = i - sumIndexMap[accu];
                maxLen = max(tmpLen, maxLen);
            }
        }
        return maxLen;
    }
};
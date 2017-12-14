//
// Created by wu061 on 14/12/17.
//

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> appearCnt = vector<int>(*max_element(nums.begin(), nums.end()) + 1,0);
        for(auto num:nums)
            appearCnt[num]++;
        vector<int> res = vector<int>(*max_element(nums.begin(), nums.end()) + 1, 0);
        res[0] = appearCnt[0];
        res[1] = max(appearCnt[0], appearCnt[1]);
        for(int i = 2; i <= *max_element(nums.begin(), nums.end()); i++){
            //note the second element in the max func. after the elements around i are removed, you can finally get all the
            //score from i
            res[i] = max(res[i- 2] + i*appearCnt[i], res[i-1]);
        }
        return res[*max_element(nums.begin(), nums.end())];
    }
};

int main()
{
    int a[] = {3,4,2};
    vector<int> input(a,a+3);
    Solution s = Solution();
    cout<<s.deleteAndEarn(input);

}

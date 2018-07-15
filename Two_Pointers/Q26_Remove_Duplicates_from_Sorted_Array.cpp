//
// Created by wu061 on 14/07/18.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int last = nums[0];
        int curr_idx = 1;
        while(curr_idx < nums.size()) {
            //cout<<"curr_index = "<<curr_idx<<endl;
            if(nums[curr_idx] == last) {
                //cout<<"erase "<<nums[curr_idx];
                nums.erase(nums.begin() + curr_idx);
            } else {
                last = nums[curr_idx];
                curr_idx++;
            }
        }
        return nums.size();
    }
};

int main() {
    vector<int> input = {1, 2, 3};
    Solution s = Solution();
    s.removeDuplicates(input);
    for(auto ele:input) {
        cout<<ele<<endl;
    }
}
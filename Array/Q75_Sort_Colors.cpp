//
// Created by wu061 on 28/09/17.
//

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_index = 0, two_index = nums.size() - 1;
        int i = 0;
        //if all 2s are already on the right, the iteration can end
        while(i < two_index + 1)
        {
            if (nums[i] == 0) {
                swap(nums[i], nums[zero_index]);
                zero_index++;
                i++;
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[two_index]);
                two_index--;
            }
            else
                i++;


        }
    }
};

int main()
{
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(0);
    Solution s = Solution();
    s.sortColors(input);
    for(int i = 0; i < input.size(); i++)
        cout<<input[i];
}
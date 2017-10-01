//
// Created by wuhuijun on 10/1/17.
//
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        int start = 0, end = nums.size() - 1;
        while(start +1 < end) {
            int mid = (end + start) / 2;
            if (nums[mid] == target)
                return mid;

            //if the left part is sorted
            if (nums[start] < nums[mid]) {
                //and target falls into this part
                if (target >= nums[start] && target <= nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;

            } else {//if the right part is sorted
                //and the target falls into this part
                if (nums[mid] <= target && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;

            }
        }
        if(target == nums[end])
            return end;
        else if(target == nums[start])
            return start;
        return -1;
    }


};

int main()
{
    int a[] = {1,3,5};
    vector<int> input(a,a+3);
    Solution s = Solution();
    cout<<s.search(input, 1);
}

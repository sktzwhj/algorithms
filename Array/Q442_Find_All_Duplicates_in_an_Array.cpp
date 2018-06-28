//
// Created by wuhuijun on 6/28/18.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//was thinking about using bucket sort but it requires extra memory. just put a[i] to the a[i] th place, if the value
//in that place is equal to a[i], then it is a duplicate.

//saw some AC code actually states a return vector, not sure if it can be called no extra space.

class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        int i = 1;
        while (i <= nums.size()) {
            while (nums[nums[i - 1] - 1] != nums[i - 1] && nums[i - 1] != i) {
                iter_swap(nums.begin() + nums[i - 1] - 1, nums.begin() + i - 1);
            }
            i++;
        }
        int real_idx = 1, curr_idx = 0;
        int max_idx = nums.size();
        while (real_idx <= max_idx) {
            if (nums[curr_idx] == real_idx) {
                nums.erase(nums.begin() + curr_idx);
            } else {
                curr_idx++;
            }
            real_idx++;
        }
        return nums;
    }
};

int main() {
    vector<int> input = {4, 3, 2, 7, 8, 2, 3, 1};
    Solution s = Solution();
    vector<int> duplicates = s.findDuplicates(input);
    for (auto e:duplicates) {
        cout << e << " ";
    }
    cout << endl;
}
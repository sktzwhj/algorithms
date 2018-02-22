//
// Created by wu061 on 22/02/18.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//find the first missing positive integer for an unsorted integer array in O(n) time and constant space.
//a natural idea is trying to use the space of the original array, make sure that nums[i] = i+1
//this problem has many corner cases which need to be aware of

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int ret = 0;
        if (nums.size() == 0)
            return 1;
        int i = 0;
        while (i < nums.size()) {
            //still need to continue swapping if the position does not satisfy the condition after swapping
            while ((nums[i] != i + 1) && nums[i] <= nums.size() && nums[i] > 0 && nums[nums[i] - 1] != nums[i]) {
                iter_swap(nums.begin() + i, nums.begin() + nums[i] - 1);
            }
            i++;
        }
        for (int j = 0; j < nums.size(); j++) {
            ret = j;
            if (nums[j] != j + 1)
                break;
        }

        if (ret == nums.size() - 1 && nums[ret] == ret + 1)
            ret += 1;
        return ret + 1;
    }
};

int main() {
    int a[] = {1, 1};
    Solution s = Solution();
    vector<int> input = vector<int>(a, a + 2);
    cout << "first missing positive = " << s.firstMissingPositive(input);
}
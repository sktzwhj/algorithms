//
// Created by wu061 on 14/07/18.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        int last = nums[0], last_cnt = 1;
        int curr_idx = 1;
        while (curr_idx < nums.size()) {
            if (nums[curr_idx] == last) {
                if (last_cnt == 1) {
                    last_cnt++;
                    curr_idx++;
                } else if (last_cnt == 2) {
                    nums.erase(nums.begin() + curr_idx);
                }

            } else {
                last = nums[curr_idx];
                last_cnt = 1;
                curr_idx++;
            }
        }
        return nums.size();
    }
};

int main() {
    vector<int> input = {1, 1, 1, 2, 2, 3};
    Solution s = Solution();
    s.removeDuplicates(input);
    for (auto ele:input) {
        cout << ele << endl;
    }
}
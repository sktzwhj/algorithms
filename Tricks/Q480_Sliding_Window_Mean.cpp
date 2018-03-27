//
// Created by wu061 on 27/03/18.
//

#include <vector>
#include <set>
#include <iostream>

using namespace std;

/*
 * a use case for multiset, note that the set/multiset in c++ are implemented via red-black tree so that the values are
 * sorted.
 */

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        vector<double> ret;
        int num_size = nums.size();
        multiset<double> window(nums.begin(), nums.begin() + k);
        auto median_iter = next(window.begin(), k / 2);
        for (int j = k; j <= num_size; j++) {
            ret.push_back((*median_iter + *prev(median_iter, 1 - k % 2)) / 2);
            if(j == num_size) return ret;
            window.insert(nums[j]);
            if (nums[j] < *median_iter) median_iter--;
            if (nums[j - k] <= *median_iter) median_iter++;
            window.erase(window.lower_bound(nums[j - k]));
        }
    }
};

int main() {
    int input[] = {1, 3, -1, -3, 5, 3, 6, 7};
    Solution s = Solution();
    vector<int> input_v(input, input + 8);
    vector<double> ret = s.medianSlidingWindow(input_v, 3);
    for (auto ele:ret) cout << ele << endl;
}

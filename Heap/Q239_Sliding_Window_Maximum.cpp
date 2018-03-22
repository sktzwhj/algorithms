//
// Created by wu061 on 22/03/18.
//

#include <vector>
#include <limits>
#include <iostream>
#include <queue>

using namespace std;

//this is something that is suitable to use deque.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> sliding_max;
        deque<int> Q;
        if (nums.size() < k || k == 0) return sliding_max;
        for (int i = 0; i < k; i++) {
            while (!Q.empty() && nums[i] > nums[Q.back()]) Q.pop_back();
            Q.push_back(i);
        }
        for (int j = k; j < nums.size(); j++) {
            sliding_max.push_back(nums[Q.front()]);
            while (!Q.empty() && (nums[j] >= nums[Q.back()])) Q.pop_back();
            while (!Q.empty() && Q.front() <= (j - k)) Q.pop_front();
            Q.push_back(j);
        }
        sliding_max.push_back(nums[Q.front()]);
        return sliding_max;
    }
};

int main() {
    int a[] = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> input(a, a + 8);
    Solution s = Solution();
    vector<int> sliding_max = s.maxSlidingWindow(input, 3);
    for (auto ele:sliding_max) cout << ele << " ";
}
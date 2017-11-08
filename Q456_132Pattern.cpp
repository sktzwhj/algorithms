//
// Created by wuhuijun on 11/8/17.
//
#include<vector>
#include<stack>
#include<limits>
#include<iostream>

using namespace std;
/*
 * When it comes to reversed order, thinking about stack is normally the right thing you should do.
 */
class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        stack<int> patternStack = stack<int>();
        int flag = numeric_limits<int>::min();
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < flag)
                return 1;
            if (patternStack.empty() || nums[i] <= patternStack.top())
                patternStack.push(nums[i]);
            else {
                while (!patternStack.empty() && patternStack.top() < nums[i]) {
                    if (patternStack.top() > flag)
                        flag = patternStack.top();
                    patternStack.pop();
                }
                patternStack.push(nums[i]);
            }
        }
        return 0;
    }

};

int main() {
    Solution s = Solution();
    int a[] = {10, 12, 6, 8, 3, 11};
    vector<int> input = vector<int>(a, a + 6);
    cout << s.find132pattern(input);

}

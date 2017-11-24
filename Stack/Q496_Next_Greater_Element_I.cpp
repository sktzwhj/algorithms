//
// Created by wu061 on 24/11/17.
//

#include<vector>
#include<stack>
#include<iostream>
#include<unordered_map>

using namespace std;

//it is not quite necessary to use stack for this problem, but still let's make a stack solution since the tag is

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums) {
        //we pre-process the nums vector by mapping each number with its next greater in the hashmap.
        unordered_map<int, int> nextGreater = unordered_map<int, int>();
        stack<int> passStack = stack<int>();
        for (int i = 0; i < nums.size(); i++) {
            while (!passStack.empty() && passStack.top() < nums[i]) {
                nextGreater[passStack.top()] = nums[i];
                passStack.pop();
            }
            passStack.push(nums[i]);
        }
        while (!passStack.empty()) {
            nextGreater[passStack.top()] = -1;
            passStack.pop();
        }
        vector<int> ret;
        for (int j = 0; j < findNums.size(); j++) {
            ret.push_back(nextGreater[findNums[j]]);
        }
        return ret;
    }
};

int main() {
    int a[] = {4, 1, 2};
    int b[] = {1, 3, 4, 2};
    vector<int> findNums = vector<int>(a, a + 3);
    vector<int> nums = vector<int>(b, b + 4);
    Solution s = Solution();
    for (auto e:s.nextGreaterElement(findNums, nums))
        cout << e << endl;
}
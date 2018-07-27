//
// Created by wuhuijun on 7/26/18.
//

#include "headers.h"

/*
 * there are still some redundant computation in the following solution.
 * i.e., the same sub problem might be solved for more than 1 time.
 * an optimization can be using memorizing.
 */
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res, left, right;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                left = diffWaysToCompute(input.substr(0, i));
                right = diffWaysToCompute(input.substr(i + 1));
            }
            for (auto left_val : left) {
                for (auto right_val : right) {
                    if (input[i] == '+') res.push_back(left_val + right_val);
                    if (input[i] == '*') res.push_back(left_val * right_val);
                    if (input[i] == '-') res.push_back(left_val - right_val);
                }
            }
        }
        if (res.empty()) {
            //no +/*/-
            res.push_back(stoi(input));
        }
        return res;
    }
};

int main() {
    string input = "2*3-4*5";
    Solution s = Solution();
    vector<int> res = s.diffWaysToCompute(input);
    for (auto val : res) cout << val << endl;
}
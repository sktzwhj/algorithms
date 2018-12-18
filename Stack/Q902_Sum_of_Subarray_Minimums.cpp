//
// Created by wu061 on 18/12/18.
//

#include "headers.h"

class Solution {
public:
    int sumSubarrayMins(vector<int> &A) {
        stack<int> monotonous_stack;
        vector<int> next_less(A.size(), A.size()), previous_less(A.size(), -1);
        monotonous_stack.push(0);
        for (int i = 1; i < A.size(); ++i) {
            while (!monotonous_stack.empty()) {
                if (A[i] >= A[monotonous_stack.top()]) {
                    previous_less[i] = monotonous_stack.top();
                    break;
                } else {
                    monotonous_stack.pop();
                }
            }
            monotonous_stack.push(i);
        }
        monotonous_stack = stack<int>();
        monotonous_stack.push(static_cast<int>(A.size()) - 1);
        for (int j = static_cast<int>(A.size()) - 2; j >= 0; --j) {
            while (!monotonous_stack.empty()) {
                //the tricky part of this problem is that you need to be very careful while dealing with conditions
                //you cannot use equal for both next_less and previous_less since you may end up calculating the duplicates
                //twice.
                if (A[j] > A[monotonous_stack.top()]) {
                    next_less[j] = monotonous_stack.top();
                    break;
                } else {
                    monotonous_stack.pop();
                }
            }
            monotonous_stack.push(j);
        }
        long res = 0;
        for (int k = 0; k < A.size(); ++k) {
            res += A[k] * (k - previous_less[k]) * (next_less[k] - k);
        }
        return static_cast<int>(res % ((long) pow(10, 9) + 7));
    }
};

int main() {
    Solution s = Solution();
    vector<int> input = {71, 55, 82, 55};
    cout << s.sumSubarrayMins(input) << endl;
}
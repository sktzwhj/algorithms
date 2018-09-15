//
// Created by wu061 on 15/09/18.
//

#include "headers.h"

class Solution {
public:
    int reachNumber(int target) {
        //as target \in [-10^9, 10^9], it seems infeasible to do naive recursive, some tricks?
        //first do binary search to find the smallest k which satisfies 1 + 2 + ... + k >= abs(target), abs is used
        //as the problem is symmetric
        target = abs(target);
        long start = 0, end = target;
        while (start <= end) {
            long k = (start + end) / 2;
            long sum = k * (k + 1) / 2;
            if (sum > target) end = k - 1;
            else if (sum == target) return k;
            else start = k + 1;
        }
        long sum = start * (start + 1) / 2;
        //then try to find the smallest k which satisfies (sum - target)%2 == 0. the reason is that if this can be satisfied,
        //we can then find a n < k and sum - 2*n = 0. this equals to make the nth step from right to left.
        while ((sum - target) % 2 != 0) {
            start++;
            sum += start;
        }
        return start;
    }
};

int main() {
    Solution s = Solution();
    cout << s.reachNumber(8);
}
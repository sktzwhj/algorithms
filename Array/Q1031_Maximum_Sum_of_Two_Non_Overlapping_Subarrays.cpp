//
// Created by wuhuijun on 4/23/19.
//
#include "headers.h"


class Solution {
public:
    int maxSumTwoNoOverlap(vector<int> &A, int L, int M) {
        vector<int> sum_l(A.size() - L + 1, 0), sum_m(A.size() - M + 1, 0);
        sum_l[0] = accumulate(A.begin(), A.begin() + L, 0);
        sum_m[0] = accumulate(A.begin(), A.begin() + M, 0);
        for (int i = 1; i <= A.size() - L; ++i)
            sum_l[i] = sum_l[i - 1] - A[i - 1] + A[i + L - 1];
        for (int i = 1; i <= A.size() - M; ++i)
            sum_m[i] = sum_m[i - 1] - A[i - 1] + A[i + M - 1];
        int max_sum_res = sum_l[0];
        for (int i = 0; i < sum_l.size(); ++i) {
            if (i >= M) {
                int max_left = *max_element(sum_m.begin(), sum_m.begin() + i - M + 1);
                max_sum_res = max(max_sum_res, sum_l[i] + max_left);
            }
            if (i + L - 1 < sum_m.size() - 1) {
                int max_right = *max_element(sum_m.begin() + i + L, sum_m.end());
                max_sum_res = max(max_sum_res, sum_l[i] + max_right);
            }
        }
        return max_sum_res;
    }
};

int main() {
    vector<int> input = {2, 1, 5, 6, 0, 9, 5, 0, 3, 8};
    int L = 4, M = 3;
    Solution s = Solution();
    cout << s.maxSumTwoNoOverlap(input, L, M);
}

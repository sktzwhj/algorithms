//
// Created by wu061 on 8/03/19.
//

#include "headers.h"

class Solution {
public:

    //vanilla brute-force implementation
    int maxTurbulenceSize(vector<int> &A) {
        if (A.size() <= 2) return A.size();
        vector<int> diff(A.size(), 0);
        diff[0] = (A[1] - A[0] != 0) ? ((A[1] > A[0]) ? 1 : 0) : -1;
        int cut_point = 0;
        int len = (diff[0] == -1) ? 1 : 2, max_len = 1;
        for (int i = 1; i < A.size() - 1; ++i) {
            if (A[i + 1] != A[i]) {
                diff[i] = (A[i + 1] - A[i] > 0) ? 1 : 0;
                if (diff[i] == diff[i - 1]) {
                    if (diff[i] != -1) {
                        max_len = max(max_len, len);
                        len = 2;
                    } else {
                        len = 1;
                    }
                } else {
                    len += 1;
                }
            }
            else {
                diff[i] = -1;
                max_len = max(max_len, len);
                len = 1;
            }
        }
        return max(max_len, len);
    }
};

//simplified
class Solution {
public:
    int maxTurbulenceSize(vector<int> &A) {
        if (A.size() <= 2) return A.size();
        int cut_point = 0, max_len = 1;
        long next_c = A[1] - A[0];
        for (int i = 1; i <= A.size() - 1; ++i) {
            long c = next_c;
            if (i < A.size() - 1) next_c = A[i + 1] - A[i];
            if (c == 0) cut_point = i;
            else if (i == A.size() - 1 || c * next_c >= 0) {
                max_len = max(max_len, i - cut_point + 1);
                cut_point = i;
            }
        }
        return max_len;
    }
};


int main() {
    Solution s = Solution();
    vector<int> input = {100, 100, 100};
    cout << s.maxTurbulenceSize(input);
}
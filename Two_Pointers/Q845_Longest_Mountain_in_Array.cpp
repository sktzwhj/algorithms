//
// Created by wu061 on 5/08/18.
//

#include "headers.h"

class Solution {
public:
    int longestMountain(vector<int> &A) {
        // a mountain must start from the end of the last mountain
        int size = A.size();
        if (size < 3) return 0;
        int start = 0, end = 0, max_len = 0;
        while (start <= size - 1) {
            end = start + 1;
            bool exist_peak = false;
            while (end <= size - 1) {
                if (!exist_peak) {
                    if (A[end - 1] < A[end]) {
                        if (end < size - 1 && A[end] > A[end + 1]) exist_peak = true;
                        ++end;
                        continue;
                    }
                } else if (A[end] < A[end - 1]) {
                    end++;
                    continue;
                }
                break;
            }
            if (exist_peak) {
                max_len = max(max_len, end - start);
                start = end - 1;
                continue;
            }
            start = end;
        }
        return max_len;
    }
};

int main() {
    vector<int> input;
    for (int i = 0; i < 10000; i++)input.push_back(i);
    Solution s = Solution();
    cout << s.longestMountain(input);
}
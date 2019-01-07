//
// Created by wu061 on 3/12/18.
//

#include "headers.h"

class Solution {
public:
    int minIncrementForUnique(vector<int> &A) {
        sort(A.begin(), A.end());
        int step = 0;
        int slot_req = 0;
        queue<int> duplicates;
        int used[40001] = {0};
        int last = -1;
        for (int i = 0; i < A.size(); ++i) {
            int usable_slots = A[i] - last - 1;
            if (usable_slots && duplicates.size() > 0) {
                //we have slots to deal with collisions
                int j = last + 1;
                while (usable_slots > 0 && !duplicates.empty()) {
                    int duplicate = duplicates.front();
                    duplicates.pop();
                    step += (j++ - duplicate);
                    usable_slots--;
                }
            }
            if (used[A[i]] == 0) {
                used[A[i]] = 1;
            } else {
                duplicates.push(A[i]);
                ++slot_req;
            }
            last = A[i];
            if (i == A.size() - 1) {
                int j = last + 1;
                while (!duplicates.empty()) {
                    int duplicate = duplicates.front();
                    duplicates.pop();
                    step += (j++ - duplicate);
                    usable_slots--;
                }
            }
        }
        return step;
    }
};

class Solution {
public:
    int minIncrementForUnique(vector<int> &a) {
        sort(a.begin(), a.end());
        int result = 0;
        for (int i = 1; i < a.size(); ++i) {
            if (a[i] <= a[i - 1]) {
                result += a[i - 1] - a[i] + 1;
                a[i] = a[i - 1] + 1;
            }
        }
        return result;
    }
};

int main() {
    vector<int> input = {1, 2, 2};
    Solution s = Solution();
    cout << s.minIncrementForUnique(input) << endl;
}
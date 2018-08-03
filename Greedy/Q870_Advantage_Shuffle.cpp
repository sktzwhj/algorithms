//
// Created by wu061 on 3/08/18.
//

#include "headers.h"

class Solution {
public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B) {
        vector<int> res;
        sort(A.begin(), A.end());
        vector<int>::iterator it;
        for (auto val : B) {
            it = lower_bound(A.begin(), A.end(), val + 1);
            if (it == A.end()) {
                it = A.begin();
            }
            res.push_back(*it);
            A.erase(it);
        }
        return res;
    }
};

int main() {
    vector<int> A = {2, 0, 4, 1, 2};
    vector<int> B = {1, 3, 0, 0, 2};
    Solution s = Solution();
    for (auto val : s.advantageCount(A, B)) {
        cout << val << endl;
    }
}
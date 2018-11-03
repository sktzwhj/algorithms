//
// Created by wu061 on 3/11/18.
//

#include "headers.h"

void print_vec(vector<int> vec) {
    for (auto val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> beautifulArray(int N) {
        //idea: all odd one side and even on the other side.
        vector<int> ret;

        if (N == 1) {
            ret.push_back(1);
            return ret;
        }
        vector<int> left = beautifulArray((N + 1) / 2);
        vector<int> right = beautifulArray(N / 2);
        for (int i = 0; i < left.size(); i++) ret.push_back(2 * left[i] - 1);
        for (int j = 0; j < right.size(); j++) ret.push_back(2 * right[j]);
        return ret;
    }
};


int main() {
    Solution s = Solution();
    vector<int> beautiful_array = s.beautifulArray(4);
    print_vec(beautiful_array);
}
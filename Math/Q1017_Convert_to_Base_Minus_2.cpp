//
// Created by wu061 on 12/04/19.
//

#include "headers.h"


class Solution {
public:
    string baseNeg2(int N) {
        string s = "";
        while(N) {
            int a = abs(N%(-2));
            s = (a == 0 ? '0' : '1') + s;
            //minus a and divide -2 guarantees that you are always dealing with the last digit of N.
            N = (N-a)/(-2);
        }
        return s == "" ? "0" : s;
    }
};

int main() {
    Solution s = Solution();
    cout<<s.baseNeg2(4);
}
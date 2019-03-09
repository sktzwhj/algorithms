//
// Created by wu061 on 9/03/19.
//

#include "headers.h"

class Solution {
public:
    int brokenCalc(int X, int Y) {
        //in order to go X from Y, we want to go faster. obviously, multiply 2 is faster than minus 1
        //therefore, it is a greedy alg where divide 2 when you can otherwise minus 1.

        int res = 0;
        while (Y > X) {
            //because ( y + 1 + 1) / 2 = y/2 + 1)
            if (Y % 2 == 0) Y /= 2;
            else Y += 1;
            res ++;
        }
        return X - Y + res;
    }

};

int main() {
    Solution s = Solution();
    cout<<s.brokenCalc(2, 3);
}
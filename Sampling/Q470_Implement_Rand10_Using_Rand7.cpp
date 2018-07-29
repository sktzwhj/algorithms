//
// Created by WuHuijun on 28/7/18.
//

#include "headers.h"

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

//an example of rejection sampling

int rand7() {
    return rand() % 7 + 1;
}

class Solution {
public:
    int rand10() {
        //run rand7() for two times can generate uniform numbers within [1, 49]
        int a = rand7(), b = rand7();
        int idx = (a - 1) * 7 + b;
        if (idx <= 40) return idx % 10 + 1;
        idx -= 40;
        int c = rand7();
        idx = (idx - 1) + c;
        if (idx <= 60) return idx % 10 + 1;
        else return rand10();
    }
};

int main() {
    Solution s = Solution();

}
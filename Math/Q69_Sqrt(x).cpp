//
// Created by wuhuijun on 9/19/18.
//

#include "headers.h"

class Solution {
public:
    int mySqrt(int x) {
        long start = 0, end = x;
        while(start <= end) {
            long mid = (start + end)/2;
            long tmp = mid * mid;
            if (tmp > x) end = mid - 1;
            else if (tmp == x) return mid;
            else start = mid + 1;
        }
        return start - 1;
    }
};

int main() {
    Solution s = Solution();
    cout<<s.mySqrt(15);
}
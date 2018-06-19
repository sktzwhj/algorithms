//
// Created by wuhuijun on 6/19/18.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

#define INT_MAX numeric_limits<int>::max()


class Solution {
public:
    int numSquares(int n) {
        if (n < 0) return 0;
        vector<int> num_square_vec(n + 1, INT_MAX);
        num_square_vec[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                num_square_vec[i] = min(num_square_vec[i], 1 + num_square_vec[i - j * j]);
            }
        }
        return num_square_vec[n];
    }
};

int main() {
    Solution s = Solution();
    cout << s.numSquares(6);
}
//
// Created by wu061 on 4/04/18.
//

#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

/*
 * A brute-force algorithm will have the complexity of O((mn)^2).To improve the efficiency, a
 * relevant algorithm: Kadane's Algorithm which finds the largest sum of a subarray for an array.
 */

class Solution {
public:
    int maxSumSubmatrix(vector <vector<int>> &matrix, int k) {
        int rowNum = matrix.size(), colNum = matrix[0].size();
        int retSum = numeric_limits<int>::min();
        for (int left = 0; left < colNum; left++) {
            vector<int> sums(rowNum, 0);
            for (int right = left; right < colNum; right++) {
                for (int row = 0; row < rowNum; row++) {
                    sums[row] += matrix[row][right];
                }
                retSum = max(retSum, sumArrayLessThanK(sums, k));
            }
        }
        return retSum;
    }

private:
    int sumArrayLessThanK(vector<int> &array, int k) {
        //implement kadane's algorithm here.
        int accu = 0, maxSum = numeric_limits<int>::min();
        //use set because it is sorted
        set<int> accuSet;
        accuSet.insert(0);
        for (int j = 0; j < array.size(); j++) {
            accu += array[j];
            //as you want accu[j] - accu[i] to be closer to k, you actually are looking for a i which is closer to
            //accu[j] - k. Note that lower_bound is needed due to the dual problem we are solving
            auto it = accuSet.lower_bound(accu - k);
            if (it != accuSet.end()) maxSum = max(maxSum, accu - *it);
            accuSet.insert(accu);
        }
        return maxSum;
    }
};

int main() {
    int a[3] = {2, 2, -1};
    int b[3] = {0, -2, 3};
    vector<int> input1(a, a + 3);
    vector<int> input2(b, b + 3);
    vector <vector<int>> input;
    input.push_back(input1);
    //input.push_back(input2);
    Solution s = Solution();
    cout << s.maxSumSubmatrix(input, 3);
}
//
// Created by wu061 on 15/12/17.
//

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

/*
 * dynamic programming and greedy are sometimes hard to differentiate. For greedy, we first need to know whether it
 * satisfy the optimal substructure. For this problem, at each stage, the solution must contain the pairs which have
 * the smallest second value to ensure that we have more flexibility while choosing the following pairs.
 */

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        //first sort according to the second value
        sort(pairs.begin(), pairs.end(), [](auto &left, auto &right) {
            return left[1] < right[1];
        });
        int lastEnd = pairs[0][1];
        int len = 1;
        for(int i = 1; i < pairs.size(); i++){
            if(pairs[i][0] > lastEnd){
                len++;
                lastEnd = pairs[i][1];
            }
        }
        return len;
    }
};

/*
 * This problem is similar to Q300 - Longest Increasing Subsequence. That problem uses greedy algorithm as well.
 */
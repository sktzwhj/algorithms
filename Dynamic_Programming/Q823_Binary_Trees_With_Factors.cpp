//
// Created by WuHuijun on 15/8/18.
//

#include "headers.h"

//I initially came up with the idea like the followings. but the problem is that we did not guarantee that
//poss..[A[i]] and poss...[A[j]] would not be updated after updating poss[A[i] * A[j]]
//the correct solution is typical dp.
class Solution {
public:
    int numFactoredBinaryTrees(vector<int> &A) {
        sort(A.begin(), A.end());
        unordered_map<int, int> possible_subtree_count;
        for (auto val : A) possible_subtree_count[val] = 1;
        for (int i = 0; i < A.size(); i++) {
            for (int j = i; j < A.size(); j++) {
                if (possible_subtree_count.find(A[i] * A[j]) != possible_subtree_count.end()) {
                    possible_subtree_count[A[i] * A[j]] += (i == j) ? (possible_subtree_count[A[i]] *
                                                                       possible_subtree_count[A[j]]) : (2 *
                                                                                                        possible_subtree_count[A[i]] *
                                                                                                        possible_subtree_count[A[j]]);
                }
            }
        }
        long res = 0;
        for (auto pair:possible_subtree_count) res += pair.second;
        return (int) (res % ((int) pow(10, 9) + 7));
    }
};


class Solution {
public:
    int numFactoredBinaryTrees(vector<int> &A) {
        sort(A.begin(), A.end());
        long res = 0;
        long mod = pow(10, 9) + 7;
        unordered_map<int, long> subtree_cnt;
        for (auto val : A) subtree_cnt[val] = 1;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (A[i] % A[j] == 0 && subtree_cnt.find(A[i] / A[j]) != subtree_cnt.end()) {
                    subtree_cnt[A[i]] = (subtree_cnt[A[i]] + subtree_cnt[A[j]] * subtree_cnt[A[i] / A[j]]) % mod;
                }
            }
        }
        for (auto pair:subtree_cnt) res = (res + pair.second) % mod;
        return res;
    }
};

int main() {
    vector<int> input = {2, 4, 5, 10};
    Solution s = Solution();
    cout << s.numFactoredBinaryTrees(input);
}
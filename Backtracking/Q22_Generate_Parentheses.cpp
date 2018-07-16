//
// Created by wu061 on 16/07/18.
//

#include "hearders.h"

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<int> parentheses_left(n - 1, 0), parentheses_right(n - 1, 1);
        parentheses_left.insert(parentheses_left.end(), parentheses_right.begin(), parentheses_right.end());
        vector<string> ret;
        do {
            string res = "(";
            int left_cnt = 1, right_cnt = 0;
            bool non_legitimate = false;
            for (auto val:parentheses_left) {
                res += (val == 0) ? "(" : ")";
                if (val == 0) left_cnt++;
                else right_cnt++;
                if (left_cnt < right_cnt) {
                    non_legitimate = true;
                    break;
                }
            }
            if (!non_legitimate) {
                res += ")";
                ret.push_back(res);
            }
        } while (next_permutation(parentheses_left.begin(), parentheses_left.end()));
        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<string> ret = s.generateParenthesis(3);
    for (auto comb:ret) {
        for (auto p:comb) {
            cout << p;
        }
        cout << endl;
    }
}
//
// Created by wuhuijun on 11/6/17.
//

/*
 * Seems to be a dp problem
 */
#include<unordered_map>
#include<iostream>

using namespace std;

class Solution {
public:
    int integerReplacement(long n) {
        dp_table[1] = 0;
        return intReplacement(n);
    }

private:
    unordered_map<long, int> dp_table = unordered_map<long, int>();

    int intReplacement(long n) {
        if (dp_table.find(n) != dp_table.end())
            return dp_table[n];
        if (n % 2 == 0)
            dp_table[n] = 1 + intReplacement(n / 2);
        else {
            dp_table[n] = min(1 + (1 + intReplacement((n + 1) / 2)), 1 + (1 + intReplacement((n - 1) / 2)));
        }
        return dp_table[n];

    }
};

int main() {
    Solution s = Solution();
    cout << s.integerReplacement(8);
}
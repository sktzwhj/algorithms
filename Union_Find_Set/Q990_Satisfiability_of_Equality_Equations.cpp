//
// Created by wuhuijun on 3/12/19.
//

#include "headers.h"


class Union_Find_Set {
public:
    Union_Find_Set(int size) {
        for (char i = 'a'; i <= 'z'; ++i) {
            parents[i] = i;
        }
    }

    void Union(char a, char b) {
        parents[find(a)] = find(b);
    }

    char find(char index) {
        if (parents[index] != index) {
            parents[index] = find(parents[index]);
        }
        return parents[index];
    }

    bool co_exist(char x, char y) {
        return find(x) == find(y);
    }

private:
    unordered_map<char, char> parents;
};

class Solution {
public:
    bool equationsPossible(vector<string> &equations) {
        int eq_size = equations.size();
        string eq = equations[eq_size - 1];


        Union_Find_Set equal_set(26);
        unordered_map<char, set<char>> non_equal_set;
        for (int i = 0; i <= eq_size - 1; ++i) {
            eq = equations[i];
            if (eq[0] == eq[3] && eq[1] == '!') return false;
            if (eq[1] == '=') {
                equal_set.Union(eq[0], eq[3]);
            }
        }
        //now all the equal elements are connected. if conflicts exist, we get false. otherwise, solution exists.
        for (int i = 0; i <= eq_size - 1; ++i) {
            eq = equations[i];
            if (eq[1] == '!') {
                if (equal_set.co_exist(eq[0], eq[3])) return false;
            }
        }

        return true;

    }
};


int main() {
    vector<string> input = {"g==c", "f!=e", "e==b", "j==b", "g!=a", "e==c", "b!=f", "d!=a", "j==g", "f!=i", "a==e"};
    Solution s = Solution();
    cout << s.equationsPossible(input);
}
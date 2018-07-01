//
// Created by wuhuijun on 7/1/18.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Board {
public:
    Board(int n) {
        board_size = n;
        queen_pos = vector<int>(n);
    }

    void add(int i, int j) {
        queen_pos[i] = j;
        row.insert(i);
        col.insert(j);
        left_diag.insert(i + j);
        right_diag.insert(i - j);
    }

    void remove(int i, int j) {
        queen_pos[i] = -1;
        row.erase(i);
        col.erase(j);
        left_diag.erase(i + j);
        right_diag.erase(i - j);
    }

    bool is_valid_pos(int i, int j) {
        return (row.find(i) == row.end()) && (col.find(j) == col.end()) && \
        (left_diag.find(i + j) == left_diag.end()) && (right_diag.find(i - j) == right_diag.end());
    }

    vector<string> print_board() {
        vector<string> res;
        for (int i = 0; i < queen_pos.size(); i++) {
            string tmp = "";
            for (int j = 0; j < queen_pos.size(); j++) {
                if (queen_pos[i] == j) tmp += "Q";
                else tmp += ".";
            }
            res.push_back(tmp);
        }
        return res;
    }

    int board_size;
    vector<int> queen_pos;
    set<int> row, col, left_diag, right_diag;
    vector<vector<string>> solutions;
};

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        Board b = Board(n);
        solve_row(0, b);
        return b.solutions;
    }

    void solve_row(int row, Board &b) {
        if (row == b.board_size) b.solutions.push_back(b.print_board());
        for (int i = 0; i < b.board_size; i++) {
            //set the ith col of row b
            if (b.is_valid_pos(row, i)) {
                b.add(row, i);
                solve_row(row + 1, b);
                b.remove(row, i);
            }
        }
    }
};

int main() {
    Solution s = Solution();
    vector<vector<string>> ret = s.solveNQueens(4);
    for (auto vec:ret) {
        for (auto ele:vec) {
            cout << ele;
        }
    }

}
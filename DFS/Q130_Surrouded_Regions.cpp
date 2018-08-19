//
// Created by wuhuijun on 8/19/18.
//

#include "headers.h"


void print_board(vector<vector<char>> &board) {
    for (auto vec : board) {
        for (auto val : vec) cout << val << " ";
        cout << endl;
    }
}

//propagate from the unsatisfied positions, all those cannot be reached should be changed.
//modifying the board during dfs is often used to solve this kind of questions.

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty()) return;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if ((i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1) && board[i][j] == 'O')
                    dfs(i, j, board);
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '*') board[i][j] = 'O';
            }
        }
    }

private:

    void dfs(int i, int j, vector<vector<char>> &board) {
        if (board[i][j] == 'O') board[i][j] = '*';
        else return;
        if (i > 0) dfs(i - 1, j, board);
        if (i < board.size() - 1) dfs(i + 1, j, board);
        if (j > 0) dfs(i, j - 1, board);
        if (j < board[0].size() - 1) dfs(i, j + 1, board);
    }
};


int main() {
    vector<vector<char>> input = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};

    Solution s = Solution();
    s.solve(input);
    print_board(input);

}
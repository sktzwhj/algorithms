//
// Created by wu061 on 16/12/17.
//
#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    bool exist(vector <vector<char>> &board, string word) {
        if (board.size() == 0)
            return word.size() == 0;
        vector <vector<int>> cellValid(board.size(), vector<int>(board[0].size()));
        bool flag = false;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                cellValid[i][j] = 1;

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    cellValid[i][j] = 0;
                    flag = helper(board, cellValid, word.substr(1, word.size()), i, j);
                    if (flag) return true;
                    cellValid[i][j] = 1;
                }
            }
        return false;
    }

private:
    bool helper(vector <vector<char>> &board, vector <vector<int>> &cellValid, string word, int i, int j) {
        if (word.size() == 0)
            return true;
        bool flag = false;
        if (i > 0 && board[i - 1][j] == word[0] && cellValid[i - 1][j] == 1) {
            cellValid[i - 1][j] = 0;
            flag = helper(board, cellValid, word.substr(1, word.size()), i - 1, j);
            if (flag) return true;
            cellValid[i - 1][j] = 1;
        }
        if (i + 1 < board.size() && board[i + 1][j] == word[0] && cellValid[i + 1][j] == 1) {
            cellValid[i + 1][j] = 0;
            flag = helper(board, cellValid, word.substr(1, word.size()), i + 1, j);
            if (flag) return true;
            cellValid[i + 1][j] = 1;
        }
        if (j > 0 && board[i][j - 1] == word[0] && cellValid[i][j - 1] == 1) {
            cellValid[i][j - 1] = 0;
            flag = helper(board, cellValid, word.substr(1, word.size()), i, j - 1);
            if (flag) return true;
            cellValid[i][j - 1] = 1;
        }
        if (j + 1 < board[0].size() && board[i][j + 1] == word[0] && cellValid[i][j + 1] == 1) {
            cellValid[i][j + 1] = 0;
            flag = helper(board, cellValid, word.substr(1, word.size()), i, j + 1);
            if (flag) return true;
            cellValid[i][j + 1] = 1;
        }

        return flag;
    }
};

int main() {
    vector <vector<char>> input;
    input.push_back(vector<char>(1, 'a'));
    Solution s = Solution();
    cout << s.exist(input, "b");
}

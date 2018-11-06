//
// Created by wu061 on 6/11/18.
//

#include "headers.h"

//find and grow. I write it a bit long but easy to understand. 

class Solution {
public:
    int shortestBridge(vector<vector<int>> &A) {
        int row_cnt = A.size();
        if (row_cnt == 0) return 0;
        int col_cnt = A[0].size();
        int init_row = -1, init_col = -1;
        //start from a any 1 in A.
        for (int i = 0; i < row_cnt; ++i) {
            for (int j = 0; j < col_cnt; ++j) {
                if (A[i][j] == 1) {
                    init_row = i;
                    init_col = j;
                    break;
                }
            }
            if (init_col != -1) break;
        }
        global_step_cnt = -1;
        visited = vector<vector<int>>(A.size(), vector<int>(A[0].size(), 0));
        re_color(A, init_row, init_col);
        while (!curr_step.empty() || !next_step.empty()) {
            if (curr_step.empty()) {
                global_step_cnt++;
                curr_step = next_step;
                next_step = queue<pair<int, int>>();
            }
            pair<int, int> pos = curr_step.front();
            curr_step.pop();
            int row = pos.first, col = pos.second;
            if (row > 0) {
                int cube = A[row - 1][col];
                if (cube == 1) return global_step_cnt;
                if (cube == 0 && !visited[row - 1][col]) {
                    visited[row - 1][col] = 1;
                    next_step.push(make_pair(row - 1, col));
                }
            }
            if (row < A.size() - 1) {
                int cube = A[row + 1][col];
                if (cube == 1) return global_step_cnt;
                if (cube == 0 && !visited[row + 1][col]) {
                    visited[row + 1][col] = 1;
                    next_step.push(make_pair(row + 1, col));
                }
            }

            if (col > 0) {
                int cube = A[row][col - 1];
                if (cube == 1) return global_step_cnt;
                if (cube == 0 && !visited[row][col - 1]) {
                    visited[row][col - 1] = 1;
                    next_step.push(make_pair(row, col - 1));
                }
            }

            if (col < A[0].size() - 1) {
                int cube = A[row][col + 1];
                if (cube == 1) return global_step_cnt;
                if (cube == 0 && !visited[row][col + 1]) {
                    visited[row][col + 1] = 1;
                    next_step.push(make_pair(row, col + 1));
                }
            }
        }
        return global_step_cnt;
    }

private:
    void re_color(vector<vector<int>> &A, int row, int col) {
        if (row > A.size() - 1 || row < 0 || col > A[0].size() - 1 || col < 0) return;
        if (A[row][col] == 1) {
            A[row][col] = 2;
            next_step.push(make_pair(row, col));
            re_color(A, row + 1, col);
            re_color(A, row - 1, col);
            re_color(A, row, col + 1);
            re_color(A, row, col - 1);
        }
    }

    queue<pair<int, int>> curr_step, next_step;
    vector<vector<int>> visited;
    int global_step_cnt;
};

int main() {
    Solution s = Solution();
    vector<vector<int>> input = {{0, 1},
                                 {1, 0}};
    cout << s.shortestBridge(input) << endl;
}
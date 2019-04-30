//
// Created by wu061 on 30/04/19.
//

#include "headers.h"

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0, int color) {
        stack<pair<int, int>> q;
        q.push({r0, c0});
        set<pair<int, int>> visited;
        int old_color = grid[r0][c0];
        while (!q.empty()) {
            bool boundary = false;
            auto g = q.top();
            q.pop();
            int r = g.first, c = g.second;
            visited.insert({r, c});
            if (grid[r][c] < 0) continue;
            if (r > 0) {
                if (abs(grid[r - 1][c]) == old_color) {
                    if (visited.find({r - 1, c}) == visited.end()) q.push({r - 1, c});
                } else {
                    boundary = true;
                }
            }
            if (c > 0) {
                if (abs(grid[r][c - 1]) == old_color) {
                    if (visited.find({r, c - 1}) == visited.end()) q.push({r, c - 1});
                } else {
                    boundary = true;
                }
            }
            if (r < grid.size() - 1) {
                if (abs(grid[r + 1][c]) == old_color) {
                    if (visited.find({r + 1, c}) == visited.end()) q.push({r + 1, c});
                } else {
                    boundary = true;
                }
            }
            if (c < grid[0].size() - 1) {
                if (abs(grid[r][c + 1]) == old_color) {
                    if (visited.find({r, c + 1}) == visited.end()) q.push({r, c + 1});
                } else {
                    boundary = true;
                }
            }
            if (c == 0 || r == 0 || (r == grid.size() - 1) || (c == grid[0].size() - 1)) boundary = true;

            if (boundary) grid[r][c] = -grid[r][c];
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                grid[i][j] = (grid[i][j] < 0) ? color : grid[i][j];
            }
        }

        return grid;
    }

};


int main() {
    vector<vector<int>> grid = {{1, 1, 1},
                                {1, 1, 1},
                                {1, 1, 1}};
    Solution s = Solution();
    grid = s.colorBorder(grid, 1, 1, 2);
    for (auto vec : grid) {
        for (auto val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }
}
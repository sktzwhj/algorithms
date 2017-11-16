//
// Created by wu061 on 16/11/17.
//

#include<vector>
#include<iostream>

using namespace std;

/*
 * A typical DFS problem. Note that only one person cannot be a friend circle.
 */
class Solution {
public:
    int findCircleNum(vector<vector<int>> &M) {
        int rows = M.size();
        if (rows == 0)
            return 0;
        int cols = M[0].size();
        int numFriendCircle = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                if (M[i][j] && dfs(M, i, j))
                    numFriendCircle++;
            }

        return numFriendCircle;
    }

    bool dfs(vector<vector<int>> &M, int row, int col) {
        if (M[row][col] != 0) {
            M[row][col] = 0;
        } else
            return false;
        for (int i = 0; i < M[0].size(); i++)
            dfs(M, row, i);
        for (int j = 0; j < M.size(); j++)
            dfs(M, j, col);
        return true;
    }


};

int main() {
    Solution s = Solution();
    vector<vector<int>> input = vector<vector<int>>();
    int a[] = {1, 1, 0}, b[] = {1, 1, 0}, c[] = {0, 0, 1};
    input.push_back(vector<int>(a, a + 3));
    input.push_back(vector<int>(b, b + 3));
    input.push_back(vector<int>(c, c + 3));

    cout << s.findCircleNum(input);
}
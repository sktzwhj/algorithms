
//
// Created by wuhuijun on 10/11/17.
//

#include<vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m,n;
        if(grid.size() == 0)
            return 0;
        else
        {
            m = grid.size();
            n = grid[0].size();
        }

        int ret = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    ret++;
                    dfs(grid,i,j);
                }

            }
        }
        return ret;

    }

    //dfs
private:
    void dfs(vector<vector<char>>& grid, int p, int q)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(p < 0 || p >= m || q < 0 || q >=n)
            return;
        else
        {
            if(grid[p][q] == '1')
            {
                grid[p][q] = 0;
                dfs(grid, p+1, q);
                dfs(grid, p-1, q);
                dfs(grid, p, q+1);
                dfs(grid, p, q-1);
            }
        }
    }
};
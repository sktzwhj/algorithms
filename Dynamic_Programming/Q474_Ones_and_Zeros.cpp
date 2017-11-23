//
// Created by wuhuijun on 11/9/17.
//
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

/*
 * Once you see some problems where you can see m, n have a range of values... maybe think about dp
 * The question is the most large number of strings in the str list you can form by using m 1s and n 0s
 */
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //we first initialize the dp memp
        //do not use hash. it is too slow
        vector<vector<int>> dpTable = vector<vector<int>>(m+1,vector<int>(n+1,0));

        for(int i = 0; i <=m; i++)
            for(int j = 0; j <=n; j++)
            {
                dpTable[i][j] = 0;
            }
        for(string str:strs)
        {
            int ones = 0, zeros = 0;
            for(int k = 0; k < str.size(); k++)
                str[k] == '0'?zeros++:ones++;
            for(int p = m; p >= zeros; p--)
                for(int q = n; q >= ones; q--)
                {
                    /*
                     * This step is interesting, unlike many vanilla dp problems which we only need to make one pass to
                     * the dp memo. In this problem, we iteratively update the dp memo. The following code can be inter-
                     * preted as the follows: if we choose this str, then the new dp memo should be the previous dp[p-zeros]
                     * [q-ones] + 1 which means the previous dp that does not consider current str plus one. If we do not
                     * choose the current str, then dp does not update. So what we do is to choose the max of these two.
                     */
                    dpTable[p][q] = max(dpTable[p][q], dpTable[p-zeros][q-ones] + 1);
                }
        }
        return dpTable[m][n];
    }


};

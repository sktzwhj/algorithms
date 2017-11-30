//
// Created by wuhuijun on 11/30/17.
//

#include<string>
#include<vector>
using namespace std;

/*
 * Since the problem does not ask things like different chars, it asks the number of operations.
 * This is very similar to LCS (longest common subsequence), dp should be a proper method.
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int lenWord1 = word1.size();
        int lenWord2 = word2.size();
        if(lenWord1 == 0)
            return lenWord2;
        else if(lenWord2 == 0)
            return lenWord1;

        //vector<int> tmp = vector<int>(lenWord1,0);
        vector<vector<int>> dpTable = vector<vector<int>>(lenWord1 + 1, vector<int>(lenWord2 + 1,0));
        for(int i = 0; i <= lenWord1; i++)
            dpTable[i][0] = i;
        for(int j = 0; j <= lenWord2; j++)
            dpTable[0][j] = j;
        for(int p = 1; p <= lenWord1; p++){
            for(int q = 1; q <= lenWord2; q++){
                if(word1[p-1] == word2[q-1])
                    dpTable[p][q] = dpTable[p-1][q-1];
                else
                    //if the last character is not equal, try the easiest way to make them the same. remove the last char, modify one char
                    dpTable[p][q] = min(min(dpTable[p-1][q] + 1, dpTable[p][q-1] + 1), dpTable[p-1][q-1]+1);
            }
        }
        return dpTable[lenWord1][lenWord2];
    }
};
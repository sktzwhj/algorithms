//
// Created by wuhuijun on 10/1/17.
//
#include<vector>
#include<iostream>
using namespace std;

/*
 * For a valid BST structure, once the left subtree and the right subtree is determined, the root will have only once choice.
 * So we can get a recursion formula. Then this becomes a dynamic programming problem.
 */
class Solution {
public:
    int numTrees(int n) {
        int ret;
        vector<int> count(n+1,1);
        count[0] = 1;
        count[1] = 1;
        if(n >= 2)
        {
            for(int i = 2; i <= n; i++)
            {
                int tmp = 0;
                for(int j = 0; j < i; j++)
                {
                    tmp += count[j]*count[i-j-1];
                }
                count[i] = tmp;
            }
        }
        return count[n];
    }
};

int main()
{
    Solution s = Solution();
    cout<<s.numTrees(4);
}

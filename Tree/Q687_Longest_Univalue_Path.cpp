//
// Created by wuhuijun on 11/23/17.
//
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//the tricky part is how to understand the path may not pass the root...

class Solution {
public:
    int longestUnivaluePath(TreeNode *root) {
        int longestLen = 0;
        return max(helper(root, longestLen), longestLen);

    }

    int helper(TreeNode *node, int& longestLen){
        if(node == NULL)
            return 0;
        bool l = false, r = false;
        int left = helper(node->left, longestLen);
        int right = helper(node->right, longestLen);
        if((node->left) && (node->val == node->left->val)){
            l = true;
            left++;
        }
        if((node->right) && (node->val == node->right->val)) {
            r = true;
            right++;
        }
        if(!l)left = 0;
        if(!r)right = 0;
        //left+right...tricky
        longestLen = max(longestLen, left+right);
        return max(left,right);

    }
};

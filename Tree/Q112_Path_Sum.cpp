//
// Created by wuhuijun on 9/19/18.
//
#include "headers.h"

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        if (root->right == NULL && root->left == NULL) return (sum == root->val) ? true : false;
        return ((root->left != NULL) ? hasPathSum(root->left, sum - root->val) : false)|| ((root->right != NULL)
                                                                                           ? hasPathSum(root->right,
                                                                                                        sum - root->val) : false);
    }
};


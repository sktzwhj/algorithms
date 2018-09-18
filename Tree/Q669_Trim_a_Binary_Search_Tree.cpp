//
// Created by wuhuijun on 9/18/18.
//

#include "headers.h"
//due to the leetcode platform, we do not deal with memory leak
class Solution {
public:
    TreeNode *trimBST(TreeNode *root, int L, int R) {
        if (root->left != NULL) root->left = trimBST(root->left, L, R);
        if (root->right != NULL) root->right = trimBST(root->right, L, R);
        if (root->val > R) {
            root->right = NULL;
            if (root->left != NULL) {
                root->val = root->left->val;
                TreeNode *tmp = root->left;
                root->left = tmp->left;
                root->right = tmp->right;
            } else root = NULL;
        } else if (root->val < L) {
            root->left = NULL;
            if (root->right != NULL) {
                root->val = root->right->val;
                TreeNode *tmp = root->right;
                root->right = tmp->right;
                root->left = tmp->left;
            } else root = NULL;
        }
        return root;
    }
};


int main() {
    vector<int> nodes = {3, 0, 4, -1, 2, -1, -1, -1, -1, 1};
    TreeNode *test = GenerateTreeFromArray(nodes);
    printTree(test);
    Solution s = Solution();
    printTree(s.trimBST(test, 1, 3));

}
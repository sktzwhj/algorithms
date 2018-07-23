//
// Created by WuHuijun on 19/7/18.
//

#include "headers.h"
using namespace std;
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        postOrderTraversal(root);
        return root;
    }

private:
    bool postOrderTraversal(TreeNode* root) {
        bool zero_left = true, zero_right = true;
        bool zero_curr = true;
        if (root->left != NULL) zero_left = postOrderTraversal(root->left);
        if (root->right != NULL) zero_right = postOrderTraversal(root->right);
        if (zero_left) root->left = NULL;
        if (zero_right) root->right = NULL;
        if (root->val == 0) {
            if (zero_left && zero_right) {
                zero_curr = true;
            } else {
                zero_curr = false;
            }
        } else {
            zero_curr = false;
        }
        cout<<zero_curr<<endl;
        return zero_curr;
    }
};

int main() {
    std::vector<int> input_tree = {1, -1, 0, -1, -1, 0, 1};
    TreeNode *root = GenerateTreeFromArray(input_tree);
    Solution s = Solution();
    TreeNode *ret = s.pruneTree(root);
    printTree(ret);
}
//
// Created by wuhuijun on 4/17/19.
//

#include "headers.h"

class Solution {
public:
    int maxAncestorDiff(TreeNode *root) {
        dfs(root, true);
        dfs(root);
        return max(res_max, res_min);
    }

    int dfs(TreeNode *root, bool maximum = false) {
        int left = root->val, right = root->val;
        if (root->left == NULL && root->right == NULL) return root->val;
        if (root->left != NULL) left = dfs(root->left, maximum);
        if (root->right != NULL) right = dfs(root->right, maximum);
        if (maximum) {
            res_max = max(res_max, max(abs(root->val - left), abs(root->val - right)));
            return max(root->val, max(left, right));
        }
        else {
            res_min = max(res_min, max(abs(root->val - left), abs(root->val - right)));
            return min(root->val, min(left, right));
        }
    }

private:
    int res_max = 0, res_min = 0;
};


int main() {
    vector<int> tree = {8, 3, 10, 1, 6, -1, 14, -1, -1, 4, 7, 13};
    TreeNode *t = GenerateTreeFromArray(tree);
    //printTree(t);
    Solution s = Solution();
    cout << s.maxAncestorDiff(t);
}
//
// Created by wuhuijun on 4/25/19.
//

#include "headers.h"


class Solution {
public:
    int distributeCoins(TreeNode* root) {
        aggregate(root);
        return moves;
    }

private:
    int aggregate(TreeNode* root) {
        //this function aggregates the extra coins all the way up to the root of the tree
        int left = 0, right = 0;
        if (root->left != NULL) left = aggregate(root->left);
        if (root->right != NULL) right = aggregate(root->right);
        root->val -= 1;
        root->val += (left + right);
        moves += abs(left) + abs(right);
        return root->val;
    }

    int moves = 0;
};

int main() {
    vector<int> tree_vec = {1,0,0,NULL,3};
    TreeNode* t = GenerateTreeFromArray(tree_vec);
    Solution s = Solution();
    cout<<s.distributeCoins(t);
}

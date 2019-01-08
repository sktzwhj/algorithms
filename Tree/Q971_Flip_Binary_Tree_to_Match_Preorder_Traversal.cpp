//
// Created by wuhuijun on 1/8/19.
//

#include "headers.h"

/*
 * pre-order traversal
 */

class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {
        return pre_order(root, voyage) ? res : vector<int>() = {-1};
    }

private:
    bool pre_order(TreeNode *root, vector<int> &voyage) {
        if (root == NULL) return true;
        if (root->val != voyage[pos++]) return false;
        if (root->left != NULL) {
            if (root->left->val != voyage[pos]) {
                if (root->right != NULL) {
                    //just note that swaping children means swapping the pointers rather than just values
                    res.push_back(root->val);
                    TreeNode *tmp = root->right;
                    root->right = root->left;
                    root->left = tmp;
                } else return false;
            }
        }

        return pre_order(root->left, voyage) && pre_order(root->right, voyage);
    }

    vector<int> res;
    int pos = 0;

};

int main() {
    vector<int> tree = {2, 1, 4, 5, -1, 3};
    TreeNode *root = GenerateTreeFromArray(tree);
    Solution s = Solution();
    vector<int> voyage({2, 4, 3, 1, 5});
    for (auto val : s.flipMatchVoyage(root, voyage)) {
        cout << val << " ";
    }
}
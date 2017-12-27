//
// Created by wuhuijun on 12/27/17.
//
#include <iostream>
#include <limits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct retType {
    long Max;
    long Min;
    bool Valid;
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (root == NULL)
            return true;
        return (maxOfSubTree(root)).Valid;
    }

private:
    retType maxOfSubTree(TreeNode *node) {
        long maxValue = numeric_limits<long>::min();
        long minValue = numeric_limits<long>::max();
        long leftMax = maxValue, rightMax = maxValue;
        long leftMin = minValue, rightMin = minValue;
        bool leftVal = true, rightVal = true;
        if (node->left == NULL && node->right == NULL) {
            retType ret = {node->val, node->val, true};
            return ret;
        }
        if (node->left != NULL) {
            retType leftret = maxOfSubTree(node->left);
            leftMax = leftret.Max;
            leftMin = leftret.Min;
            leftVal = leftret.Valid;
        }
        if (node->right != NULL) {
            retType rightret = maxOfSubTree(node->right);
            rightMax = rightret.Max;
            rightMin = rightret.Min;
            rightVal = rightret.Valid;
        }
        return {max(leftMax, max(rightMax, (long) node->val)), min(leftMin, min((long) node->val, rightMin)),
                (leftVal && rightVal) && (node->val > leftMax) && ((node->val < rightMin) || (node->right == NULL))};
    }
};

int main() {
    TreeNode *left = new TreeNode(1);
    TreeNode *right = new TreeNode(3);
    TreeNode *root = new TreeNode(2);
    left->left = NULL;
    left->right = NULL;
    right->left = NULL;
    right->right = NULL;
    root->left = left;
    root->right = right;
    Solution s = Solution();
    cout << s.isValidBST(root);
}

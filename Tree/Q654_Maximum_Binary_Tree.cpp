//
// Created by wu061 on 16/07/18.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        if (nums.empty()) return NULL;
        int max_idx = max_element(nums.begin(), nums.end()) - nums.begin();
        TreeNode *root = new TreeNode(nums[max_idx]);
        vector<int> left_nodes = vector<int>(nums.begin(), nums.begin() + max_idx);
        vector<int> right_nodes = vector<int>(nums.begin() + max_idx + 1, nums.end());
        TreeNode *left = constructMaximumBinaryTree(left_nodes);
        TreeNode *right = constructMaximumBinaryTree(right_nodes);
        root->left = left;
        root->right = right;
        return root;
    }

};
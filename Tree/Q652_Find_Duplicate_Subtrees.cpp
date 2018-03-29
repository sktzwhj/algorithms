//
// Created by wu061 on 29/03/18.
//

#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

//all you need is to design a way to record the traversal results, I would use string as an example

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        preorder(root);
        return duplicate_roots;
    }

private:
    unordered_map<string, int> tree_cnt;
    vector<TreeNode *> duplicate_roots;

    string preorder(TreeNode *root) {
        if (!root) return "NULL";
        string curr = to_string(root->val) + preorder(root->left) + preorder(root->right);
        if (tree_cnt[curr]++ == 1) duplicate_roots.push_back(root);
        return curr;
    }
};
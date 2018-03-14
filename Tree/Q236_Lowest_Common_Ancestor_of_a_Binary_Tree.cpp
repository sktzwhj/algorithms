//
// Created by wu061 on 14/03/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//write this first

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

        bool p_found = false, q_found = false;
        dfs_path(root, p, q, p_found, q_found);
        TreeNode *ret = root;
        vector<TreeNode *> p_path, q_path;

        while (p != root) {
            p_path.insert(p_path.begin(), p);
            p = parent[p];
        }
        while (q != root) {
            q_path.insert(q_path.begin(), q);
            q = parent[q];
        }
        p_path.insert(p_path.begin(), root);
        q_path.insert(q_path.begin(), root);
        for (int i = 0; i <= min(p_path.size(), q_path.size()); i++) {
            if ((p_path[i] != q_path[i]) && (i > 0)) {
                ret = p_path[i - 1];
                break;
            }
        }
        return ret;

    }

private:
    void dfs_path(TreeNode *root, TreeNode *p, TreeNode *q, bool &p_found, bool &q_found) {
        if (p_found && q_found) return;
        if (p == root) p_found = true;
        if (q == root) q_found = true;
        if (root->left != NULL) {
            parent[root->left] = root;
            dfs_path(root->left, p, q, p_found, q_found);
        }
        if (root->right != NULL) {
            parent[root->right] = root;
            dfs_path(root->right, p, q, p_found, q_found);
        }
    }

    unordered_map<TreeNode *, TreeNode *> parent;

};

//it turns out it can be just like this


class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : !right ? left : root;
    }
};
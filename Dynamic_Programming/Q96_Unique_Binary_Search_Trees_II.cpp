//
// Created by WuHuijun on 13/7/18.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    vector<int> tree;
    while (!q.empty()) {
        TreeNode *curr = q.front();
        if (curr != NULL) tree.push_back(curr->val);
        else tree.push_back(-1);
        if (curr != NULL) q.push(curr->left);
        if (curr != NULL) q.push(curr->right);
    }
    for (auto ele:tree) cout << ele << " ";
    cout << endl;

}

class Solution {
    /*
     * The idea is simple. For a tree, once you choose the root, you only need to think about the structure of the
     * left subtree and right subtree. Then link the root to the left root and right root. In this way, we can have
     * a recursive method like the followings.
     */
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return vector<TreeNode *>();
        vector<TreeNode *> nodes(n);
        for (int i = 0; i < n; i++) {
            //cout<<i<<endl;
            nodes[i] = new TreeNode(i + 1);
        }
        return generateSubTree(nodes);
    }

private:
    vector<TreeNode *> generateSubTree(vector<TreeNode *> &nodes) {
        /*
         * @param: nodes is a vector for the nodes in the subtree
         * @return: return the roots for the possible subtrees.
         */
        int subtree_size = nodes.size();
        vector<TreeNode *> roots;
        if (subtree_size == 1) {
            roots.push_back(nodes[0]);
            return roots;
        }

        for (int i = 0; i < subtree_size; i++) {
            //choose the ith node as the root, note the corner case where the subtree can have no nodes.
            vector<TreeNode *> left_subtree = (i != 0) ? vector<TreeNode *>(nodes.begin(), nodes.begin() + i)
                                                       : vector<TreeNode *>(1, NULL);
            vector<TreeNode *> right_subtree = (i != subtree_size - 1) ? vector<TreeNode *>(nodes.begin() + i + 1,
                                                                                            nodes.end())
                                                                       : vector<TreeNode *>(1, NULL);
            left_subtree = generateSubTree(left_subtree);
            right_subtree = generateSubTree(right_subtree);
            for (auto left_root : left_subtree) {
                for (auto right_root : right_subtree) {
                    TreeNode *node_i = new TreeNode(nodes[i]->val);
                    node_i->left = left_root;
                    node_i->right = right_root;
                    roots.push_back(node_i);
                }
            }
        }
        return roots;
    }
};

int main() {
    Solution s = Solution();
    vector<TreeNode *> roots = s.generateTrees(3);

}
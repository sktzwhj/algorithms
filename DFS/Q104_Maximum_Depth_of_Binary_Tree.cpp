//
// Created by wu061 on 26/04/19.
//

#include "headers.h"

//just a non-recursive DFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if (root != NULL) q.push({root, 1});
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            max_depth = (node.second > max_depth) ? node.second : max_depth;
            if (node.first->left != NULL) q.push({node.first->left, node.second + 1});
            if (node.first->right != NULL) q.push({node.first->right, node.second + 1});
        }
        return max_depth;
    }

private:
    int max_depth = 0;
};
int main() {
    vector<int> tree_vec = {3,9,20,-1,-1,15,7};
    TreeNode* t = GenerateTreeFromArray(tree_vec);
    Solution s = Solution();
    cout<<s.maxDepth(t)<<endl;
}
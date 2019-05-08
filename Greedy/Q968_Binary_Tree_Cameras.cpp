//
// Created by wu061 on 8/05/19.
//

#include "headers.h"

//I was initilly trying hard to do dp, but it turns out to be a greedy problem.
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        //the greedy is based on the observation that putting the camera on the parent of leaves is always better than putting on the leaves
        int state = dfs(root);
        return res + (state == 0 ? 1 : 0);
    }

private:
    int dfs(TreeNode* node) {
        if (node == NULL) return 2;
        //1 -> covered with a camera, 2 -> covered without a camera, 0 -> leaf
        int left = dfs(node->left), right = dfs(node->right);
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        return (left == 1 || right == 1) ? 2 : 0;
    }

    int res = 0;
};


int main() {
    vector<int> tree_vec = {1, 2, -1, -1, 3, 4, -1, -1, 5, 6};
    TreeNode* t = GenerateTreeFromArray(tree_vec);
    Solution s = Solution();
    cout<<s.minCameraCover(t);

}
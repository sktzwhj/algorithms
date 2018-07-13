//
// Created by WuHuijun on 11/7/18.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode *GenerateTreeFromArray(vector<int> &array) {
    //this function is used to generate test cases
    int array_size = array.size();
    if (array_size == 0) return NULL;
    vector<TreeNode *> tree_nodes;
    bool break_flag = false;
    for (int i = 0; i < array_size; ++i) {
        int level_node_num = pow(2, i);
        for (int j = 0; j < level_node_num; ++j) {
            if (array[pow(2, i) - 1 + j] != -1) {
                TreeNode *tmp_node = new TreeNode(array[pow(2, i) - 1 + j]);
                tree_nodes.push_back(tmp_node);
            } else {
                tree_nodes.push_back(NULL);
            }
            if (tree_nodes.size() == array_size) {
                break_flag = true;
                break;
            }
        }
        if (break_flag) break;
    }
    for (int i = 0; i < array_size; i++) {
        if (2 * i + 1 < array_size) tree_nodes[i]->left = tree_nodes[2 * i + 1];
        if (2 * i + 2 < array_size) tree_nodes[i]->right = tree_nodes[2 * i + 2];
    }
    return tree_nodes[0];
}

class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        if (root == NULL) return 0;
        int width = 0;
        //we track the nodes by their id. just like the array representations of binary trees.
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 1));
        int start = 1, end = 1, level = 0;
        while (!q.empty()) {
            pair<TreeNode *, int> curr = q.front();
            q.pop();
            TreeNode *curr_node = curr.first;
            int curr_node_id = curr.second;
            if (curr_node_id >= pow(2, level + 1)) {
                //if a new level starts, we change the start.
                level++;
                int curr_level_width = end - start + 1;
                if (curr_level_width > width) width = curr_level_width;
                start = curr_node_id;
            }
            //track last node.
            end = curr_node_id;
            if (curr_node->left != NULL) q.push(make_pair(curr_node->left, 2 * curr_node_id));
            if (curr_node->right != NULL) q.push(make_pair(curr_node->right, 2 * curr_node_id + 1));
        }
        int last_width = end - start + 1;
        if (last_width > width) width = last_width;
        return width;
    }

};

int main() {
    vector<int> input = {1, 3, 2, 5, 3, -1, 9};
    TreeNode *tree = GenerateTreeFromArray(input);
    Solution s = Solution();
    cout << s.widthOfBinaryTree(tree);
}
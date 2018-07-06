//
// Created by wuhuijun on 7/6/18.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

#define INT_MIN numeric_limits<int>::min();

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

//my solution uses only 32ms and beats 100%

class Solution {
public:
    void recoverTree(TreeNode *root) {
        //since there are only two elements with wrong order, we can use constant space to solve this
        if (root == NULL) return;
        getExchangePos(root);
        //cout<<"to exchanged position is "<<toExchangePos->val<<endl;
        doExchange(root);
    }

    void printTree(TreeNode* root) {
        if(root->left != NULL) printTree(root->left);
        cout<<root->val<<endl;
        if(root->right != NULL) printTree(root->right);
    }

private:
    TreeNode *toExchangePos = NULL;
    int curr_largest = INT_MIN;
    bool exchanged = false;

    void getExchangePos(TreeNode *root) {
        if (root->left != NULL) getExchangePos(root->left);
        if (root->val < curr_largest) {
            toExchangePos = root;
        } else {
            curr_largest = root->val;
        }
        if (root->right != NULL) getExchangePos(root->right);
    }

    void doExchange(TreeNode *root) {
        if (root->left != NULL) doExchange(root->left);
        if (root->val > toExchangePos->val && exchanged == false) {
            //cout<<"the position being exchanged is "<<root->val<<endl;
            int tmp_val = toExchangePos->val;
            toExchangePos->val = root->val;
            root->val = tmp_val;
            exchanged = true;
        }
        if (root->right) doExchange(root->right);
    }

};

int main() {
    vector<int> input = {3, 2, -1, -1, 1};
    TreeNode *root = GenerateTreeFromArray(input);
    Solution s = Solution();
    s.recoverTree(root);
    s.printTree(root);
    return 0;
}
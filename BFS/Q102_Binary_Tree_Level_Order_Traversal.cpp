//
// Created by wu061 on 6/12/17.
//

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector <vector<int>> levelOrder(TreeNode *root) {
        if (root == NULL)
            return valueList;
        int curLevel = 0;
        valueList.push_back(vector<int>());
        valueList[0].push_back(root->val);
        if (root->left != NULL) {
            if (valueList.size() < curLevel + 2)
                valueList.push_back(vector<int>());
            helper(root->left, curLevel + 1);
        }
        if (root->right != NULL) {
            if (valueList.size() < curLevel + 2)
                valueList.push_back(vector<int>());
            helper(root->right, curLevel + 1);
        }
        return valueList;

    }

private:
    void helper(TreeNode *root, int curLevel) {
        if (root != NULL)
            valueList[curLevel].push_back(root->val);
        if (root->left != NULL) {
            if (valueList.size() < curLevel + 2)
                valueList.push_back(vector<int>());
            helper(root->left, curLevel + 1);
        }
        if (root->right != NULL) {
            if (valueList.size() < curLevel + 2)
                valueList.push_back(vector<int>());
            helper(root->right, curLevel + 1);
        }
    }

    vector <vector<int>> valueList = vector < vector < int >> ();
};
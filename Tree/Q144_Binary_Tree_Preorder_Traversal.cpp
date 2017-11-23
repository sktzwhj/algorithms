//
// Created by wu061 on 28/09/17.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include<stack>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        TreeNode *curr = root;
        vector<int> ret;
        while(curr!=NULL || !s.empty())
        {
            while (curr!= NULL)
            {
                ret.push_back(curr->val);
                s.push(curr);
                curr = curr->left;
            }
            if(!s.empty())
            {
                TreeNode* top = s.top();
                s.pop();
                curr = top->right;
            }
        }
        return ret;
    }

private:
    stack<TreeNode*> s;
};
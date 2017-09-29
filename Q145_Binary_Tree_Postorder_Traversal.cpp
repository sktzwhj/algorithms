//
// Created by wuhuijun on 9/29/17.
//

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

/*
 * since we can do pre-order, post-order is just reverse the order...
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
    vector<int> postorderTraversal(TreeNode *root) {
        TreeNode *curr = root;
        vector<int> ret;
        stack<int> reverse_stack;
        while(curr!=NULL || !s.empty())
        {
            while (curr!= NULL)
            {
                reverse_stack.push(curr->val);
                s.push(curr);
                curr = curr->right;
            }
            if(!s.empty())
            {
                TreeNode* top = s.top();
                s.pop();
                curr = top->left;
            }
        }
        while(!reverse_stack.empty())
        {
            int top = reverse_stack.top();
            ret.push_back(top);
            reverse_stack.pop();
        }
        return ret;
    }

private:
    stack<TreeNode*> s;
};
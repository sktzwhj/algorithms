//
// Created by wuhuijun on 9/25/17.
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
 * seems the solution is to use the inorder traversal for BST
 * An optimization can be stopping at the kth value rather than going through all the nodes on the BST.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortedValues;
    void inOrderTraversal(TreeNode *root, vector<int> vec)
    {
        if(root->left!=NULL)
            inOrderTraversal(root->left, vec);
        sortedValues.push_back(root->val);
        if(root->right!=NULL)
            inOrderTraversal(root->right, vec);
    }

    int kthSmallest(TreeNode *root, int k) {
        inOrderTraversal(root,sortedValues);
        return sortedValues[k-1];
    }
};

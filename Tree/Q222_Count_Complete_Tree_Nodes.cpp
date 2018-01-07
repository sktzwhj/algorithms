//
// Created by wu061 on 1/01/18.
//
#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//a naive method got TLE since it does not make use of the characteristics of complete binary tree.
class Solution {
public:
    int countNodes(TreeNode *root) {
        nodeCnt = 0;
        nodeCounter(root);
        return nodeCnt;
    }
private:
    void nodeCounter(TreeNode *node){
        if(node != NULL) nodeCnt++;
        else return;
        if(node->left != NULL) nodeCounter(node->left);
        if(node->right != NULL) nodeCounter(node->right);
    }
    int nodeCnt;
};

/*
  a better solution which makes use of the info about heights
  for a node, if its left height = right height, the left subtree is full while the right subtree is complete
  if left height > right height, the left subtree is complete and the right subtree is full
  for a full binary tree , the # of nodes is 2^(height) - 1
 */

class Solution1 {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        else{
            int leftHeight = getheight(root->left);
            int rightHeight = getheight(root->right);
            if(leftHeight == rightHeight)
                //1 << leftHeight counts the root
                return (1 << leftHeight) + countNodes(root->right);
            else
                return (1 << rightHeight) + countNodes(root->left);
        }
    }

private:
    int getheight(TreeNode *node){
        int height = 0;
        while(node != NULL){
            height++;
            node = node->left;
        }
        return height;
    }
};

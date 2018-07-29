//
// Created by wu061 on 16/07/18.
//

#ifndef LEETCODE_HEADERS_H
#define LEETCODE_HEADERS_H
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <ctime>
#include <random>
#include <chrono>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


void printTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    vector<int> tree;
    while (!q.empty()) {
        TreeNode *curr = q.front();
        q.pop();
        if (curr != NULL) tree.push_back(curr->val);
        else tree.push_back(-1);
        if (curr != NULL) q.push(curr->left);
        if (curr != NULL) q.push(curr->right);
    }
    for (auto ele:tree) cout << ele << " ";
    cout << endl;

}

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
        if (2 * i + 1 < array_size && tree_nodes[i] != NULL) tree_nodes[i]->left = tree_nodes[2 * i + 1];
        if (2 * i + 2 < array_size && tree_nodes[i] != NULL) tree_nodes[i]->right = tree_nodes[2 * i + 2];
    }
    return tree_nodes[0];
}
#endif LEETCODE_HEADERS_H

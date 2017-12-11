//
// Created by wuhuijun on 12/11/17.
//

#include<iostream>
#include<vector>
#include<cmath>
#include<pair>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

    int sumNumbers(TreeNode *root) {
        int sum = 0;
        vector<pair<int,int>> numbers = helper(root);
        for (auto num:numbers) sum += num.first;
        return sum;
    }

private:

    vector<pair<int, int>> helper(TreeNode *node) {
        vector<pair<int, int>> numbers = vector<pair<int, int>>();
        if (node == NULL)
            return numbers;
        if ((node->left) == NULL && (node->right) == NULL) {
            numbers.push_back(make_pair(node->val, 0));
        } else {
            if (node->left != NULL) {
                vector<pair<int, int>> left = helper(node->left);
                for (int i = 0; i < left.size(); i++) {
                    left[i].second += 1;
                    left[i].first = left[i].first + pow(10, left[i].second) * (node->val);
                }
                numbers.insert(numbers.end(), left.begin(), left.end());
            }
            if (node->right != NULL) {
                vector<pair<int, int>> right = helper(node->right);
                for (int i = 0; i < right.size(); i++) {
                    right[i].second += 1;
                    right[i].first = right[i].first + pow(10, right[i].second) * (node->val);
                }
                numbers.insert(numbers.end(), right.begin(), right.end());

            }

        }

        return numbers;
    }

};

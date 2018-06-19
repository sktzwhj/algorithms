//
// Created by wu061 on 18/06/18.
//

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//the idea is simple, just do BFS and get the rightmost node of each layer
#define PAIR pair<TreeNode*, int>

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        queue<PAIR > unvisited;
        unvisited.push(make_pair(root, 1));
        vector<pair<int, int>> visited;
        vector<int> ret;
        if (root == NULL) return ret;
        while (!unvisited.empty()) {
            PAIR curr = (unvisited.front());
            if (curr.first->left != NULL) unvisited.push(make_pair(curr.first->left, curr.second + 1));
            if (curr.first->right != NULL) unvisited.push(make_pair(curr.first->right, curr.second + 1));
            visited.push_back(make_pair(curr.first->val, curr.second));
            unvisited.pop();
        }
        for (int i = 0; i < visited.size(); i++) {
            if (visited[i].second != visited[i + 1].second || i == visited.size() - 1) {
                ret.push_back(visited[i].first);
            }
        }
        return ret;
    }
};

int main() {

    TreeNode t1 = TreeNode(1);
    TreeNode t2 = TreeNode(2);
    TreeNode t3 = TreeNode(3);
    TreeNode t4 = TreeNode(4);
    TreeNode t5 = TreeNode(5);
    t1.left = &t2;
    t2.right = &t5;
    t1.right = &t3;
    t3.right = &t4;
    Solution s = Solution();
    vector<int> right_view = s.rightSideView(&t1);
    for(auto e : right_view) cout<<e<<endl;
}
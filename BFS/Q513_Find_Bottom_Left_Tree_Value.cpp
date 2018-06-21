//
// Created by wuhuijun on 6/21/18.
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
    int findBottomLeftValue(TreeNode *root) {
        queue <PAIR> unvisited;
        unvisited.push(make_pair(root, 1));
        vector <pair<int, int>> visited;
        while (!unvisited.empty()) {
            PAIR curr = (unvisited.front());
            if (curr.first->left != NULL) unvisited.push(make_pair(curr.first->left, curr.second + 1));
            if (curr.first->right != NULL) unvisited.push(make_pair(curr.first->right, curr.second + 1));
            visited.push_back(make_pair(curr.first->val, curr.second));
            unvisited.pop();
        }
        for (int i = visited.size() - 1; i >= 0; i--) {
            if (i == 0 || visited[i].second > visited[i - 1].second ) {
                return visited[i].first;
            }
        }
    }
};

int main() {
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(3);
    t1->left = t2;
    t1->right = t3;
    Solution s = Solution();
    cout << s.findBottomLeftValue(t1) << endl;
}

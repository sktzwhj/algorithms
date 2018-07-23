//
// Created by WuHuijun on 20/7/18.
//

#include "headers.h"

//my solution is suboptimal due to two main issues
//1. use extra memory, you can burn the int into 4 chars rather than make them strings.
//2. you do not need to track the pointers, just use preorder traversal to do the serialization and deserialization
//this one is much better https://leetcode.com/problems/serialize-and-deserialize-bst/discuss/93167/Concise-C++-19ms-solution-beating-99.4

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        map<TreeNode *, long> node_index;
        string serialized = "";
        if (root == NULL) return serialized;
        vector<TreeNode> tree_vec = bfs(root, node_index);
        for (int i = 0; i < tree_vec.size(); i++) {
            tree_vec[i].left = (TreeNode *) node_index[tree_vec[i].left];
            tree_vec[i].right = (TreeNode *) node_index[tree_vec[i].right];
        }
        for (auto node:tree_vec) {
            serialized += to_string(node.val);
            serialized += " " + to_string((long) node.left);
            serialized += " " + to_string((long) node.right) + " ";
        }
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data == "") return NULL;
        vector<string> splitted = splitStringBySpace(data);
        map<long, TreeNode *> node_map = map<long, TreeNode *>();
        long idx = 0;
        vector<TreeNode *> tree_vec;
        node_map.insert(make_pair(0, (TreeNode *) NULL));
        while (idx < splitted.size()) {
            TreeNode *tmp_node = new TreeNode(atoi(splitted[idx].c_str()));
            tmp_node->left = (TreeNode *) atoi(splitted[idx + 1].c_str());
            tmp_node->right = (TreeNode *) atoi(splitted[idx + 2].c_str());
            if (idx > 0) node_map.insert(make_pair(idx / 3, tmp_node));
            tree_vec.push_back(tmp_node);
            idx += 3;
        }
        for (int i = 0; i < tree_vec.size(); i++) {
            tree_vec[i]->left = node_map[(long) tree_vec[i]->left];
            tree_vec[i]->right = node_map[(long) tree_vec[i]->right];
        }
        return tree_vec[0];
    }

private:
    vector<TreeNode> bfs(TreeNode *root, map<TreeNode *, long> &node_index) {
        vector<TreeNode> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            res.push_back(*curr);
            node_index[curr] = res.size() - 1;
            if (curr->left != NULL) q.push(curr->left);
            if (curr->right != NULL) q.push(curr->right);
        }
        return res;
    }

    vector<string> splitStringBySpace(string s) {
        istringstream iss(s);
        vector<string> res;
        string subs;
        while (iss >> subs) {
            res.push_back(subs);
            cout << subs << endl;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));​

int main() {
    vector<int> tree_vec = {1, 2, 3};
    TreeNode *t = GenerateTreeFromArray(tree_vec);
    Codec c = Codec();
    TreeNode *tree = c.deserialize(c.serialize(t));
    printTree(tree);
}
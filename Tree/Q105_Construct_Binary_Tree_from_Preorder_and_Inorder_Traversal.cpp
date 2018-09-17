//
// Created by wu061 on 17/09/18.
//

#include "headers.h"

enum position {
    LEFT, RIGHT
};

struct NodeSlot {
    //the level of the available slot in the tree
    int level;
    TreeNode *parent;
    //whether it's a left position or right one.
    enum position avail_pos;
    NodeSlot(int lvl, TreeNode *ptr, enum position pos) : level(lvl), parent(ptr), avail_pos(pos) {};
};

struct NodeSlotCmp {
    bool operator()(const NodeSlot *l, const NodeSlot *r) {
        if (l->level != r->level) return l->level > r->level;
        else return int(l->avail_pos) > int(r->avail_pos);
    }
};

//my brute-force solution. slow and complicated...but works
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty()) return NULL;
        unordered_map<int, int> node_idx_pre, node_idx_in;
        for (int i = 0; i < inorder.size(); ++i) {
            node_idx_in[inorder[i]] = i;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        priority_queue<NodeSlot *, vector<NodeSlot *>, NodeSlotCmp> activeSlots;
        activeSlots.push(new NodeSlot(0, root, LEFT));
        activeSlots.push(new NodeSlot(0, root, RIGHT));
        for (int j = 1; j < preorder.size(); ++j) {
            TreeNode *curr = new TreeNode(preorder[j]);
            int curr_level = 0;
            bool inserted = false;
            vector<NodeSlot *> reinsert;
            while (!inserted) {
                NodeSlot *slot = activeSlots.top();
                activeSlots.pop();
                //cross check the inorder to decide insert to left or right
                if (slot->avail_pos == LEFT) {
                    if (node_idx_in[curr->val] < node_idx_in[slot->parent->val]) {
                        inserted = true;
                        slot->parent->left = curr;
                        curr_level = slot->level;
                    }
                } else {
                    if (node_idx_in[curr->val] > node_idx_in[slot->parent->val]) {
                        inserted = true;
                        slot->parent->right = curr;
                        curr_level = slot->level;
                        while (!activeSlots.empty()) activeSlots.pop();
                    } else {
                        //if it's a right available position at higher level, you should add it back just in case of using in the future.
                        reinsert.push_back(slot);
                    }
                }
            }
            for (auto s:reinsert) activeSlots.push(s);
            activeSlots.push(new NodeSlot(curr_level + 1, curr, LEFT));
            activeSlots.push(new NodeSlot(curr_level + 1, curr, RIGHT));
        }
        return root;
    }
};

//a much more elegant way...
class Solution(object):
    def buildTree(self, preorder, inorder):
        if inorder:
            ind = inorder.index(preorder.pop(0))
            root = TreeNode(inorder[ind])
            root.left = self.buildTree(preorder, inorder[0:ind])
            root.right = self.buildTree(preorder, inorder[ind+1:])
            return root
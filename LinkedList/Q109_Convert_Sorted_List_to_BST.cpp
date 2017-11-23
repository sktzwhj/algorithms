//
// Created by wu061 on 15/10/17.
//

#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL)
            return NULL;

        ListNode *ptr = head;
        vector<int> treeNodes;
        while (ptr != NULL) {
            treeNodes.push_back(ptr->val);
            ptr = ptr->next;
        }
        set<int> treeSet;
        int start = 0, end = treeNodes.size() - 1;
        if (start == end)
            return new TreeNode(treeNodes[0]);
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(treeNodes[mid]);
        treeSet.insert(mid);
        addNode(root, treeNodes, treeSet, mid, start, end);
        return root;
    }

private:
    void addNode(TreeNode *root, vector<int> &treeNodes, set<int> &treeSet, int rootIdx, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            int leftIdx = (start + mid) / 2;
            TreeNode *leftChild;
            TreeNode *rightChild;
            if (treeSet.find(leftIdx) == treeSet.end() && leftIdx >= 0) {
                TreeNode *leftChild = new TreeNode(treeNodes[leftIdx]);
                cout << "leftChild:" << treeNodes[leftIdx] << endl;
                root->left = leftChild;
                treeSet.insert(leftIdx);
            } else
                leftChild = NULL;

            int rightIdx = (mid + 1 + end) / 2;
            if (treeSet.find(rightIdx) == treeSet.end() && rightIdx < treeNodes.size()) {
                TreeNode *rightChild = new TreeNode(treeNodes[rightIdx]);
                cout << "rightChild:" << treeNodes[rightIdx] << endl;
                root->right = rightChild;
                treeSet.insert(rightIdx);
            } else
                rightChild = NULL;
            if (root->left != NULL) {
                cout << "go to left" << endl;
                addNode(root->left, treeNodes, treeSet, leftIdx, start, mid);
            }
            if (root->right != NULL) {
                cout << "go to right" << endl;
                addNode(root->right, treeNodes, treeSet, rightIdx, mid + 1, end);
            }

        }

    }
};

int main()
{
    ListNode* head = new ListNode(3);
    ListNode* node1 = new ListNode(5);
    ListNode* node2 = new ListNode(8);
    head->next = node1;
    node1->next = node2;
    Solution s = Solution();
    TreeNode* root = s.sortedListToBST(head);

}
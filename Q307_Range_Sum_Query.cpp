//
// Created by wu061 on 19/11/17.
//
#include<vector>
#include<iostream>
#include<assert.h>
#include<cmath>

/*
 * A use case for segment tree.
 */

using namespace std;

struct segNode {
    int left;
    int right;
    int nodeSum;
};

class SegTree {
public:
    SegTree() {
        tree = vector<segNode>();
        treeSize = 0;
    }

    SegTree(vector<int> nums) {

        //since segment tree is a complete tree so that we can use an array to store it efficiently

        tree = vector<segNode>(pow(2, int(log2(2 * nums.size())) + 1));
        treeSize = nums.size();
        treeBuild(0, nums.size() - 1, nums, 0);
        //cout << "before sum init" << endl;
        //updateSum();
        //cout << "after sum init" << endl;
    }

    void update(int index, int val) {
        //curr = 0 means we start from the root of segment tree.
        int curr = 0;
        while (tree[curr].left <= index && tree[curr].right >= index) {
            if (tree[curr].left == tree[curr].right) {
                //if we arrive at the node to modify, then we can just update.
                tree[curr].nodeSum = val;
                break;
            } else {
                //otherwise, we may need to update the left or right branch of the tree
                //we use updated vector to record which nodes need to be updated later by sum update func.
                updated[curr] = false;
                if (index >= tree[2 * curr + 1].left && index <= tree[2 * curr + 1].right)
                    curr = 2 * curr + 1;
                else
                    curr = 2 * curr + 2;

            }
        }
        updateSum();
    }

    int getRangeSum(int start, int end, int curr) {
        //cout<<curr<<" "<<tree.size()<<endl;
        //if the current node is not overlapped with the query range
        //cout << "start:" << start << "  " << "end:" << end << endl;
        if (start > tree[curr].right || end < tree[curr].left || start > end)
            return 0;
            //else overlap exists
        else {
            //cout << "current node range" << tree[curr].left << ":" << tree[curr].right << endl;
            if (start <= tree[curr].left && end >= tree[curr].right)
                return tree[curr].nodeSum;

            //int mid = (tree[curr].left + tree[curr].right) / 2;
            //cout << "split to " << start << "to" << mid << " and " << mid + 1 << "to" << end << endl;
            return getRangeSum(start, end, 2 * curr + 1) +
                   getRangeSum(start, end, 2 * curr + 2);
        }
    }

    void printTree() {
        cout << "---------------------print tree---------------------" << endl;
        for (int i = 0; i < tree.size(); i++)
            cout << tree[i].left << "->" << tree[i].right << ":" << tree[i].nodeSum << endl;
    }

    int getSize() {
        return tree.size();
    }

private:
    vector<segNode> tree;
    vector<bool> updated = vector<bool>(tree.size(), false);
    int treeSize = 0;

    int treeBuild(int left, int right, vector<int> nums, int index) {
        //cout << index << endl;
        tree[index].left = left;
        tree[index].right = right;
        if (left == right) {
            tree[index].nodeSum = nums[left];
            return tree[index].nodeSum;
        }

        int mid = (left + right) / 2;
        tree[index].nodeSum =
                treeBuild(left, mid, nums, 2 * index + 1) + treeBuild(mid + 1, right, nums, 2 * index + 2);
        return tree[index].nodeSum;


    }

    int getSum(int index) {
        if (updated[index])
            return tree[index].nodeSum;
        if (tree[index].left == tree[index].right) {
            updated[index] = true;
            return tree[index].nodeSum;
        } else {
            updated[index] = true;
            tree[index].nodeSum = getSum(2 * index + 1) + getSum(2 * index + 2);
            return tree[index].nodeSum;
        }
    }

    void updateSum() {
        for (int i = 0; i < tree.size(); i++) {
            tree[i].nodeSum = getSum(i);
        }
    }

};


class NumArray {
public:
    SegTree tree;

    NumArray(vector<int> nums) {
        if (nums.size() > 0)
            tree = SegTree(nums);
        else
            tree = SegTree();
    }

    void update(int i, int val) {
        if (tree.getSize() > 0)
            tree.update(i, val);
        else
            return;
    }

    int sumRange(int i, int j) {
        if (tree.getSize() > 0)
            return tree.getRangeSum(i, j, 0);
        else
            return 0;
    }

};

int main() {
    int a[] = {1, 3, 5};
    vector<int> input = vector<int>(a, a + 3);
    NumArray array = NumArray(input);


    //SegTree t = SegTree(input);
    //array.tree->printTree();
    cout << array.sumRange(0, 2);

    array.tree.printTree();
    //cout<<t.getRangeSum(1,2,1);
    array.update(1, 2);
    cout << array.sumRange(0, 2);
    //t.printTree();
}

//
// Created by wu061 on 12/12/17.
//

#include<vector>
#include<algorithm>
#include<unordered_map>
#include<iostream>
using namespace std;

//it is a little bit unnatural to solve this problem by BIT. mergesort is more longuitive

//we implement a Fenwick tree here
class fenwickTree {
public:
    fenwickTree(vector<int> vec) {
        treeVec = vector<long>(vec.size() + 1, 0);
    }

    void add(long pos, long val) {
        long index = pos;
        while (index < treeVec.size()) {
            treeVec[index] += val;
            index += (index & (-index));
        }
    }

    long sum(long pos) {
        long index = pos;
        long sum = 0;
        while (index >= 1) {
            sum += treeVec[index];
            index -= (index & (-index));
        }
        return sum;
    }

private:
    vector<long> treeVec;
};

class Solution {
public:
    int reversePairs(vector<int> &nums) {
        int ret = 0;
        //essentially, the problem becomes how many nodes are larger than two times of the current num
        fenwickTree tree = fenwickTree(nums);
        vector<int> v = nums;
        sort(v.begin(), v.end());
        unordered_map<int,int> orderedIndex = unordered_map<int,int>();
        for(int i = 0; i < v.size(); i++)
            orderedIndex[v[i]] = i + 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            ret += tree.sum(lower_bound(v.begin(), v.end(), nums[i]/2.0) - v.begin());
            tree.add(orderedIndex[nums[i]], 1);
        }
        return ret;
    }

};

int main()
{
    int a[] = {1,3,2,3,1};
    vector<int> input(a,a+5);
    Solution s = Solution();
    cout<<s.reversePairs(input);
}
//
// Created by WuHuijun on 16/8/18.
//


#include "headers.h"

//initially came up with this idea. got TLE since it's O(N^2)

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector <vector<int>> &edges) {
        //use adjacent list to represent the graph
        vector<int> ret(N);
        vector <vector<int>> graph(N, vector<int>());
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < N; i++) {
            int accu = 0;
            helper(i, -1, graph, accu, 1);
            ret[i] = accu;
        }
        return ret;
    }

private:
    void helper(int root, int parent, vector <vector<int>> &g, int &accu, int depth) {
        for (auto node : g[root]) {
            if (node != parent) {
                accu += depth;
                helper(node, root, g, accu, depth + 1);
            }
        }
    }
};

#include "headers.h"

//nodes are scanned for multiple times. how to reduce?
//the solution is quite tricky...
//https://leetcode.com/problems/sum-of-distances-in-tree/solution/

//basicly, ans[x] = x@X + y@Y + #Y, similarly, ans[y] = y@Y + x@X + #X
//so ans[y] - ans[x] = #X - #Y
//what we need is just one ans[root], and all # of subtrees

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector <vector<int>> &edges) {
        //use adjacent list to represent the graph
        vector<int> ans(N, 0), count(N, 1);
        vector <vector<int>> graph(N, vector<int>());
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        //first get the answer of one node (say root = 0)
        dfs(0, -1, graph, ans, count);
        //then we get the subtree size rooted at each node
        dfs_dp(0, -1, graph, ans, count);
        return ans;
    }

private:
    void dfs(int root, int parent, vector <vector<int>> &g, vector<int> &ans, vector<int> &count) {
        for (auto child : g[root]) {
            if (child != parent) {
                dfs(child, root, g, ans, count);
                //note that the ans for nodes (not root) is just partial solution here since we do not go back to parents
                ans[root] += (ans[child] + count[child]);
                count[root] += count[child];
            }
        }
    }

    void dfs_dp(int root, int parent, vector <vector<int>> &g, vector<int> &ans, vector<int> &count) {
        for (auto child : g[root]) {
            if (child != parent) {
                ans[child] = ans[root] - count[child] + (ans.size() - count[child]);
                dfs_dp(child, root, g, ans, count);
            }
        }
    }
};

int main() {
    Solution s = Solution();
    int N = 6;
    vector <vector<int>> edges = {{0, 1},
                                  {0, 2},
                                  {2, 3},
                                  {2, 4},
                                  {2, 5}};
    vector<int> ret = s.sumOfDistancesInTree(N, edges);
    for (auto val:ret) cout << val << endl;
}
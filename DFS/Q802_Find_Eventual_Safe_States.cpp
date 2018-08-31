//
// Created by wu061 on 31/08/18.
//

#include "headers.h"

enum NODE_STATUS {UNVISITED,PENDING,SAFE};
//it may be a liitle bit complicated. the pending node is always part of a circle is the invariance of this question.
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        vector<int> res;
        vector<NODE_STATUS> node_status(graph.size(), UNVISITED);
        for (int i = 0; i < graph.size(); i++) {
            if (dfs(i, graph, node_status)) res.push_back(i);
        }
        return res;
    }

private:
    bool dfs(int curr_node, vector<vector<int>> &graph, vector<NODE_STATUS> &node_status) {
        if(node_status[curr_node] != UNVISITED) {
            return node_status[curr_node] == SAFE;
        }
        node_status[curr_node] = PENDING;
        int next_size = graph[curr_node].size();
        for (auto next : graph[curr_node]) {
            if(node_status[next] == SAFE) continue;
            if(node_status[next] == PENDING || !dfs(next, graph, node_status)) {
                return false;
            }
        }
        node_status[curr_node] = SAFE;
        return true;
    }
};

int main() {
    vector<vector<int>> graph = {{1, 2},
                                 {2, 3},
                                 {5},
                                 {0},
                                 {5},
                                 {},
                                 {}};
    Solution s = Solution();
    vector<int> ret = s.eventualSafeNodes(graph);
    for (auto val : ret) cout << val << endl;
}
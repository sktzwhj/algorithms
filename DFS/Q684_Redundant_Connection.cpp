//
// Created by wu061 on 13/03/18.
//

#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
#include <stack>

using namespace std;


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        //since there is only one additional edge so that the problem becomes a bit easier. we can use dfs to find the loop in the graph
        vector<set<int>> g(1001);
        //path vector is used to recover the cycle path later
        vector<int> path(1001, -1);
        //build the graph
        for (auto edge:edges) {
            int from = edge[0], to = edge[1];
            g[from].insert(to);
            g[to].insert(from);
        }
        int visit_index = 0;
        unordered_map<int, int> visit_order;
        stack<int> dfs_stack;
        int curr_node = -1;
        dfs_stack.push(1);
        while (!dfs_stack.empty()) {
            curr_node = dfs_stack.top();
            dfs_stack.pop();

            if (!visit_order.count(curr_node)) {
                visit_order[curr_node] = visit_index++;
            } else {

                //a loop is found
                int loop_point = curr_node;
                int last_visit_index = visit_order[curr_node];
                set<int> loop_nodes;
                loop_nodes.insert(loop_point);
                while (path[curr_node] != loop_point) {
                    curr_node = path[curr_node];
                    loop_nodes.insert(curr_node);
                    //cout<<curr_node<<" is in the loop"<<endl;
                }
                for (int j = edges.size() - 1; j >= 0; j--) {
                    int from = edges[j][0], to = edges[j][1];
                    if (loop_nodes.count(from) && loop_nodes.count(to)) return edges[j];
                }
            }

            for (auto node:g[curr_node]) {
                if (node != path[curr_node]) {
                    dfs_stack.push(node);
                    path[node] = curr_node;
                }
            }
        }

    }
};

int main() {
    int a[] = {1, 2}, b[] = {2, 3}, c[] = {3, 4}, d[] = {1, 4}, e[] = {1, 5};
    vector<int> a_v(a, a + 2), b_v(b, b + 2), c_v(c, c + 2), d_v(d, d + 2), e_v(e, e + 2);
    vector<vector<int>> input;
    input.push_back(a_v);
    input.push_back(b_v);
    input.push_back(c_v);
    input.push_back(d_v);
    input.push_back(e_v);


    Solution s = Solution();
    vector<int> ret = s.findRedundantConnection(input);
    for (auto e:ret) cout << e << endl;
}

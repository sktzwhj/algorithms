//
// Created by wu061 on 16/06/18.
//

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

//first it can be quite intuitive to think about BFS. Unfortunately, got TLE.

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector <pair<int, int>> &edges) {
        vector<int> roots;
        unordered_map<int, vector<int>> neighbors;
        for (int i = 0; i < edges.size(); i++) {
            neighbors[edges[i].first].push_back(edges[i].second);
            neighbors[edges[i].second].push_back(edges[i].first);
        }
        int min_depth = n;
        for (int i = 0; i < n; i++) {
            int max_depth = 0;
            int layer = 0;
            vector<int> exist(n, 0);
            getMaxDepth(i, neighbors, exist, max_depth, layer);
            if (max_depth == min_depth)
                roots.push_back(i);
            else if (max_depth < min_depth) {
                roots.clear();
                roots.push_back(i);
                min_depth = max_depth;
            }
        }
        return roots;
    }

private:
    void getMaxDepth(int root, unordered_map<int, vector<int>> &neighbors, vector<int> &exist, int &max_depth,
                     int layer) {
        exist[root] = 1;
        int valid_neighbor_num = 0;
        for (auto neighbor: neighbors[root]) {
            if (!exist[neighbor]) {
                if (max_depth < layer + 1) max_depth = layer + 1;
                getMaxDepth(neighbor, neighbors, exist, max_depth, layer + 1);
            }
        }
    }
};

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;
//an interesting idea is that the root must be the medium node of the longest path in the graph
/*
 * this link http://wattlebird.github.io/2014/09/21/%E6%A0%91%E7%9A%84%E7%9B%B4%E5%BE%84/
 * gives a detailed analysis about why the idea works.
 */

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector <pair<int, int>> &edges) {
        set<int> roots;

        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }
        int cur_longest_path_len = 1;
        vector<int> path;
        int start_node = 0;
        int parent = -1;
        dfs(graph, start_node, parent, cur_longest_path_len, path);
        start_node = longest_path[longest_path.size() - 1];
        longest_path.clear();
        cur_longest_path_len = 1;
        dfs(graph, start_node, parent, cur_longest_path_len, path);

        //cout<<"longest path length is "<<cur_longest_path_len<<endl;
        if (cur_longest_path_len % 2 == 0) {
            //there would be two results for this path
            roots.insert(longest_path[cur_longest_path_len / 2 - 1]);
            roots.insert(longest_path[cur_longest_path_len / 2]);

        } else {
            roots.insert(longest_path[cur_longest_path_len / 2]);
        }
        return vector<int>(roots.begin(), roots.end());
    }

private:
    vector<int> longest_path;

    //first time forgot to add & for graph, got TLE... need to be careful...
    void dfs(unordered_map<int, vector<int>> &graph, int root, int parent, int &cur_longest_path_len,
             vector<int> &path) {
        //find the longest path in the graph
        bool neighbor_exist = false;
        for (auto neighbor: graph[root]) {
            if (neighbor != parent) {
                neighbor_exist = true;
                path.push_back(root);
                dfs(graph, neighbor, root, cur_longest_path_len, path);
                path.pop_back();
            }
        }
        if (!neighbor_exist) {
            path.push_back(root);
            if (path.size() >= cur_longest_path_len) {
                cur_longest_path_len = path.size();
                longest_path = path;
            }
            path.pop_back();
        }
    }
};

int main() {
    vector <pair<int, int>> edges = {make_pair(0, 1), make_pair(0, 2), make_pair(0, 3), make_pair(3, 4),
                                     make_pair(4, 5)};
    int n = 6;
    Solution s = Solution();
    vector<int> roots = s.findMinHeightTrees(n, edges);
    for (auto e:roots) cout << e << endl;
}
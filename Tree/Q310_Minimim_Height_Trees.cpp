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
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges) {
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

int main() {
    vector<pair<int, int>> edges = {make_pair(0, 1), make_pair(0, 2), make_pair(0, 3), make_pair(3, 4),
                                    make_pair(4, 5)};
    int n = 6;
    Solution s = Solution();
    vector<int> roots = s.findMinHeightTrees(n, edges);
    for (auto e:roots) cout << e << endl;
}
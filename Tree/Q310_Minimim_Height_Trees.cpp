//
// Created by wu061 on 16/06/18.
//

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges) {
        vector<int> roots;
        unordered_map<int, vector<int>> neighbors;
        for (int i = 0; i < n; i++) neighbors.insert(make_pair(i, vector<int>()));
        for (int i = 0; i < edges.size(); i++) {
            neighbors[edges[i].first].push_back(edges[i].second);
            neighbors[edges[i].second].push_back(edges[i].first);
        }
        unordered_map<int, int> root_depth_map;
        for (int i = 0; i < n; i++) {
            int max_depth = 1;
            set<int> exist_nodes = set<int>();
            getMaxDepth(i, neighbors, exist_nodes, max_depth);
            cout << "depth for root " << i << " is" << max_depth << endl;
            root_depth_map[i] = max_depth;
        }
        vector<pair<int, int>> root_depth_vec(root_depth_map.begin(), root_depth_map.end());
        sort(root_depth_vec.begin(), root_depth_vec.end(), compareByValue);
        int min_depth = root_depth_vec[0].second;
        for (auto e:root_depth_vec) {
            if (e.second == min_depth) roots.push_back(e.first);
        }
        return roots;
    }

private:
    void getMaxDepth(int root, unordered_map<int, vector<int>> &neighbors, set<int> &exist_nodes, int &max_depth) {
        cout<<"-> "<<root;
        exist_nodes.insert(root);
        int valid_neighbor_num = 0;
        for (auto neighbor: neighbors[root]) {
            if (exist_nodes.find(neighbor) == exist_nodes.end()) {
                valid_neighbor_num++;
                getMaxDepth(neighbor, neighbors, exist_nodes, max_depth);
            }
        }
        if (valid_neighbor_num > 0) ++max_depth;
        else cout<<endl;
    }

    bool static compareByValue(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }
};

int main() {
    vector<pair<int, int>> edges = {make_pair(0, 1), make_pair(0, 2), make_pair(0, 3), make_pair(3, 4), make_pair(4, 5)};
    int n = 6;
    Solution s = Solution();
    vector<int> roots = s.findMinHeightTrees(n, edges);
    for (auto e:roots) cout << e << endl;
}
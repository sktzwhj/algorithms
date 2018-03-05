//
// Created by wu061 on 5/03/18.
//

#include <vector>
#include <unordered_map>
#include <limits>
#include <queue>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

//just dijkstra algorithm

class Solution {
public:

    struct CompareNode {
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) const {
            return lhs.second > rhs.second;
        }
    };

    int networkDelayTime(vector<vector<int>> &times, int N, int K) {
        vector<vector<pair<int, int>>> nodes(N + 1, vector<pair<int, int>>());

        unordered_map<int, int> previous;
        for (int i = 0; i < times.size(); i++) nodes[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        vector<int> distance(N + 1, numeric_limits<int>::max());
        distance[K] = 0;
        distance[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareNode> pq;
        pq.push(make_pair(K, 0));
        //pq.push(make_pair(0,0));
        set<int> S;
        while (!pq.empty()) {
            pair<int, int> node = pq.top();
            pq.pop();
            int node_id = node.first;
            S.insert(node_id);
            for (pair<int, int> e:nodes[node_id]) {
                if (distance[e.first] > distance[node_id] + e.second) {
                    distance[e.first] = distance[node_id] + e.second;
                    previous[e.first] = node_id;
                    pq.push(make_pair(e.first, distance[e.first]));
                }
            }
        }
        int ret = *max_element(distance.begin(), distance.end());
        return (ret == numeric_limits<int>::max()) ? -1 : ret;
    }
};

int main() {
    int a[] = {2, 1, 1}, b[] = {2, 3, 1}, c[] = {3, 4, 1};
    vector<int> a_input(a, a + 3), b_input(b, b + 3), c_input(c, c + 3);
    vector<vector<int>> input;
    input.push_back(a_input);
    input.push_back(b_input);
    input.push_back(c_input);
    Solution s = Solution();
    s.networkDelayTime(input, 4, 2);
}
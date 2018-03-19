//
// Created by wuhuijun on 3/19/18.
//

#include <unordered_map>
#include <queue>
#include <vector>
#include <limits>
#include <iostream>
#include <set>
using namespace std;

/*
 * since the price of flight tickets cannot be negative, this problem can be easily solved by dijkstra algorithm.
 * k is the maximum allowed number of stops.
 */


class Solution {
public:
    struct CompareNode {
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) const {
            return lhs.second > rhs.second;
        }
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int INT_MAX = numeric_limits<int>::max();
        vector<vector<pair<int, int>>> nodes(n, vector<pair<int, int>>());
        for (int i = 0; i < flights.size(); i++) nodes[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));

        //use path to record the previous stop for each stop.
        unordered_map<int,int> previous;
        vector<int> price(n, numeric_limits<int>::max());
        vector<int> stop_num(n, 0);
        price[src] = 0;
        //distance[0] = 0;
        //a priority queue to sort the closest node to the src.
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareNode> pq;
        pq.push(make_pair(src, 0));
        //pq.push(make_pair(0,0));
        set<int> S;
        while (!pq.empty()) {
            pair<int, int> node = pq.top();
            pq.pop();
            int node_id = node.first;
            int node_price = node.second;
            S.insert(node_id);
            for (pair<int, int> e:nodes[node_id]) {
                if ((price[e.first] > price[node_id] + e.second) && (stop_num[node_id] <= K)) {
                    //cout<<"relax"<<endl;
                    price[e.first] = price[node_id] + e.second;
                    stop_num[e.first] = stop_num[node_id] + 1;
                    previous[e.first] = node_id;
                    pq.push(make_pair(e.first, price[e.first]));
                    //TODO:need to add the stops num into pq since stop_num vector might be changed later.
                }
            }
        }
        return (price[dst] < INT_MAX)?price[dst]:-1;
    }
};


int main()
{
    int a[] = {0,1,1};
    int b[] = {0,2,5};
    int c[] = {1,2,1};
    int d[] = {2,3,1};
    vector<int> a_(a,a+sizeof(a)), b_(b, b+sizeof(b)), c_(c, c+sizeof(c)), d_(d, d+sizeof(d));
    vector<vector<int>> input;
    input.push_back(a_);
    input.push_back(b_);
    input.push_back(c_);
    input.push_back(d_);
    Solution s = Solution();
    cout<<s.findCheapestPrice(4, input, 0, 3, 1)<<endl;
}

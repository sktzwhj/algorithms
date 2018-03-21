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
        bool operator()(const vector<int> &lhs, const vector<int> &rhs) const {
            return lhs[1] > rhs[1];
        }
    };

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        int INT_MAX = numeric_limits<int>::max();
        vector<vector<pair<int, int>>> nodes(n, vector<pair<int, int>>());
        for (int i = 0; i < flights.size(); i++)
            nodes[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));

        //use path to record the previous stop for each stop.
        unordered_map<int, int> previous;
        //a variation of vanilla dijkstra, consider the number of stops here. this makes the properties of dijkstra get satisfied.
        vector<vector<int>> price(n, vector<int>(K + 2, numeric_limits<int>::max()));
        vector<int> stop_num(n, 0);
        price[src][0] = 0;
        //distance[0] = 0;
        //a priority queue to sort the closest node to the src.
        priority_queue<vector<int>, vector<vector<int>>, CompareNode> pq;
        pq.push({src, 0, 0});
        //pq.push(make_pair(0,0));
        set<int> S;
        while (!pq.empty()) {
            vector<int> node = pq.top();
            pq.pop();
            int node_id = node[0];
            int node_price = node[1];
            int stops_before = node[2];
            //cout<<"node id = "<<node_id<<" node_price = "<<node_price<<" stops_before = "<<stops_before<<endl;
            S.insert(node_id);
            for (pair<int, int> e:nodes[node_id]) {
                if ((price[e.first][stops_before + 1] > node_price + e.second) && (stops_before < K + 1)) {
                    //cout<<"relax"<<endl;
                    price[e.first][stops_before + 1] = node_price + e.second;
                    //cout<<"price["<<e.first<<"]["<<stops_before + 1<<"]="<<price[e.first][stops_before+1]<<endl;
                    pq.push({e.first, price[e.first][stops_before + 1], stops_before + 1});

                    //cout<<"push stop "<<e.first<<endl;
                }
            }
        }
        int min = price[dst][0];
        for (int i = 0; i < K + 2; i++) {
            if (price[dst][i] < min) min = price[dst][i];
        }
        return (min == numeric_limits<int>::max()) ? -1 : min;
    }
};


int main() {
    int a[] = {0, 1, 5};
    int b[] = {1, 2, 5};
    int c[] = {0, 3, 2};
    int d[] = {3, 1, 2};
    int e[] = {4, 2, 1};
    vector<int> a_(a, a + sizeof(a)), b_(b, b + sizeof(b)), c_(c, c + sizeof(c)), d_(d, d + sizeof(d)), e_(d, e +
                                                                                                              sizeof(e));
    vector<vector<int>> input;
    input.push_back(a_);
    input.push_back(b_);
    input.push_back(c_);
    input.push_back(d_);
    input.push_back(e_);
    Solution s = Solution();
    cout << s.findCheapestPrice(5, input, 0, 2, 2) << endl;
}

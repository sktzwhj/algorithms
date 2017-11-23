//
// Created by wu061 on 17/11/17.
//

#include<vector>
#include<unordered_map>
#include<queue>
#include<set>

/*
 * very typical topological ordering problem.
 */

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        queue<int> zeroInDegreeVertex = queue<int>();
        unordered_map<int, int> nonZeroInDegree = unordered_map<int, int>();
        unordered_map<int, set<int>> Graph = unordered_map<int, set<int>>();

        for (int i = 0; i < prerequisites.size(); i++) {
            int from = prerequisites[i].first;
            int to = prerequisites[i].second;
            Graph[from].insert(to);
            if (nonZeroInDegree.find(to) != nonZeroInDegree.end())
                nonZeroInDegree[to]++;
            else
                nonZeroInDegree[to] = 1;
        }
        for (int i = 0; i < numCourses; i++) {
            if (nonZeroInDegree.find(i) == nonZeroInDegree.end()) {
                zeroInDegreeVertex.push(i);
            }
        }
        while (zeroInDegreeVertex.size() > 0) {
            int vertex = zeroInDegreeVertex.front();
            zeroInDegreeVertex.pop();
            for (auto v:Graph[vertex]) {
                nonZeroInDegree[v]--;
                if (nonZeroInDegree[v] == 0) {
                    zeroInDegreeVertex.push(v);
                    nonZeroInDegree.erase(v);
                }
            }
            Graph.erase(vertex);
        }
        if (nonZeroInDegree.size() > 0)
            return false;
        else
            return true;

    }
};
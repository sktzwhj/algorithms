//
// Created by wuhuijun on 3/14/18.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        int curr_node = 0;
        dfs(graph, curr_node, path);
        return ret_path;
    }

private:
    void dfs(vector<vector<int>>& graph, int curr_node, vector<int> path){
        path.push_back(curr_node);
        if(curr_node == graph.size() - 1){
            ret_path.push_back(path);
        }
        else{
            for(auto neighbor:graph[curr_node]){
                dfs(graph, neighbor, path);
            }
        }
    }

    vector<vector<int>> ret_path;
};
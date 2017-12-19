//
// Created by wu061 on 19/12/17.
//

#include<vector>
#include<unordered_map>
using namespace std;

class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        for(Employee* e : employees){
            employeeMap[e->id] = e;
        }
        return dfs(id);
    }

private:
    unordered_map<int, Employee*> employeeMap;

    int dfs(int id)
    {
        int subImportance = 0;
        if(employeeMap[id]->subordinates.size() > 0){
            for(int subId:employeeMap[id]->subordinates)
                subImportance += dfs(subId);
        }
        return subImportance + employeeMap[id]->importance;
    }

};
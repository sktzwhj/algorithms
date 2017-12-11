//
// Created by wu061 on 10/12/17.
//

#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

/*
 * We want to know if several accounts belong to the same person. This is similar to the problem of checking that different
 * nodes are actually belong to the same group. The typical method for this kind of problem is union-find set
 */

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        //we first initialize the union set, each node is a set
        for (int k = 0; k < accounts.size(); k++)
            parent[k] = k;
        unordered_map<string, int> accountSet = unordered_map<string, int>();


        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (accountSet.find(accounts[i][j]) != accountSet.end())
                    unionSet(i, find(accountSet[accounts[i][j]]));
                else
                    accountSet[accounts[i][j]] = i;
            }
        }

        for (int i = 0; i < accounts.size(); i++)
            for (int j = 1; j < accounts[i].size(); j++)
                accountSet[accounts[i][j]] = find(i);


        unordered_map<int, vector<string>> retMap = unordered_map<int, vector<string>>();
        for (auto it = accountSet.begin(); it != accountSet.end(); ++it)
            retMap[(*it).second].push_back((*it).first);


        vector<vector<string>> ret = vector<vector<string>>();
        for (auto it = retMap.begin(); it != retMap.end(); it++) {
            sort((*it).second.begin(), (*it).second.end());
            (*it).second.insert((*it).second.begin(), accounts[(*it).first][0]);
            ret.push_back((*it).second);
        }
        return ret;
    }

private:
    //we implement a union set here
    //each string belongs to a set, so here parent[x] = y, x is the id for a user while int is the index for the user
    unordered_map<int, int> parent = unordered_map<int, int>();

    int find(int id) {
        return (id == parent[id]) ? id : find(parent[id]);
    }

    void unionSet(int x, int y) {
        if (x == y)
            return;
        int xParent = find(x);
        parent[y] = xParent;
    }
};
//
// Created by wu061 on 23/07/18.
//

//
// Created by wuhuijun on 11/28/17.
//
#include<vector>
#include<set>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> res = vector<vector<int>>();
        vector<int> tmp = vector<int>();
        //we sort the candidates first so that we do not consider the smaller numbers after big ones. This can
        //avoid the duplicates.
        helper(candidates, 0, target, res, tmp);
        //sort also works for vec of vec
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }

private:
    void helper(vector<int> candidates, int start, int target, vector<vector<int>> &res, vector<int> sol) {
        vector<int> tmp_sol = vector<int>();
        int tmp_target;

        for (int i = start; i < candidates.size(); i++) {
            tmp_sol = sol;
            tmp_target = target;
            tmp_sol.push_back(candidates[i]);
            tmp_target -= candidates[i];
            if (tmp_target == 0) {
                sort(tmp_sol.begin(), tmp_sol.end());
                res.push_back(tmp_sol);
            } else if (tmp_target < 0)
                continue;
            else
                helper(candidates, i + 1, tmp_target, res, tmp_sol);
            tmp_sol.pop_back();
        }
    }

};


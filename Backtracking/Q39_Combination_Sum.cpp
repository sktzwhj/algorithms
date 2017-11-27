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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res = vector<vector<int>>();
        for(int i = 0; i < candidates.size(); i++){
            //cout<<candidates[i]<<endl;
            vector<int> tmp = vector<int>();
            tmp.push_back(candidates[i]);
            target -= candidates[i];
            if(target == 0)
            {
                sort(tmp.begin(),tmp.end());
                if(existSol.find(tmp)==existSol.end())
                    res.push_back(tmp);
                continue;
            }
            else if(target < 0)
                continue;
            else
                helper(candidates,target,res,tmp);
        }
        return res;
    }

private:
    void helper(vector<int> candidates, int target, vector<vector<int>>& res, vector<int> tmp_sol){
        for(int i = 0; i < candidates.size(); i++){
            //vector<int> tmp_sol(sol);
            tmp_sol.push_back(candidates[i]);
            target -= candidates[i];
            if(target == 0){
                sort(tmp_sol.begin(),tmp_sol.end());
                if(existSol.find(tmp_sol)==existSol.end()){
                    res.push_back(tmp_sol);
                    continue;
                }

            }
            else if(target < 0)
                continue;
            else
                helper(candidates, target, res, tmp_sol);


        }
    }

    set<vector<int>> existSol = set<vector<int>>();
};

int main()
{
    int a[] = {2,3,6,7};
    vector<int> input = vector<int>(a,a+4);
    Solution s = Solution();
    vector<vector<int>> res = s.combinationSum(input,7);
    for(auto vec:res){
        for(auto e:vec){
            cout<<e;
        }
        cout<<endl;
    }



}


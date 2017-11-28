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
        vector<int> tmp = vector<int>();
        //we sort the candidates first so that we do not consider the smaller numbers after big ones. This can
        //avoid the duplicates.
        sort(candidates.begin(),candidates.end());
        helper(candidates,0,target,res,tmp);
        return res;
    }

private:
    void helper(vector<int> candidates, int start, int target, vector<vector<int>>& res, vector<int> sol){
        vector<int> tmp_sol = vector<int>();
        int tmp_target;
        for(int i = start; i < candidates.size(); i++){
            tmp_sol = sol;
            tmp_target = target;
            tmp_sol.push_back(candidates[i]);
            tmp_target -= candidates[i];
            if(tmp_target == 0){
                sort(tmp_sol.begin(),tmp_sol.end());
                res.push_back(tmp_sol);
                continue;
            }
            else if(tmp_target < 0)
                continue;
            else
                helper(candidates, i, tmp_target, res, tmp_sol);
            tmp_sol.pop_back();
        }
    }

};

int main()
{
    int a[] = {2,3,6,7};
    vector<int> input = vector<int>(a,a+4);
    Solution s = Solution();
    vector<vector<int>> res = s.combinationSum(input,7);
    cout<<"the length of res is "<<res.size()<<endl;
    for(auto vec:res){
        for(auto e:vec){
            cout<<e;
        }
        cout<<endl;
    }

}


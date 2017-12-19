//
// Created by wuhuijun on 12/19/17.
//
#include <vector>
#include <iostream>
#include <limits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> wait(n, numeric_limits<int>::max());
        unordered_map<int, int> earliest;
        for(int k = 30; k <= 100; k++)
            earliest[k] = numeric_limits<int>::max();
        for(int i = n - 1; i >=0; i--){
            //cout<<"i="<<i<<endl;
            int firstWarmer = numeric_limits<int>::max();
            int temp = temperatures[i];
            for(int j = temp + 1; j <= 100; j++){
                firstWarmer = min(earliest[j], firstWarmer);
            }
            //cout<<"firstWarmer day is "<<firstWarmer<<endl;
            if(firstWarmer < numeric_limits<int>::max())
                wait[i] = firstWarmer - i;
            else
                wait[i] = 0;
            earliest[temperatures[i]] = i;
        }
        return wait;
    }
};

int main()
{
    int a[] = {73,74,75,71,69,72,76,73};
    vector<int> input = vector<int>(a,a+8);
    Solution s = Solution();
    for(auto e:s.dailyTemperatures(input))
        cout<<e<<endl;
}


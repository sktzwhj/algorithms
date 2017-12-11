//
// Created by wu061 on 6/12/17.
//
#include<vector>
#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

//this problem is a typical greedy problem. Whether you can find the optimal solution by greedy algorithm depends on
//whether the problem satisfies the optimal substructure.

class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        //first let's count the most frequent tasks.
        unordered_map<char, int> taskCnt = unordered_map<char,int>();
        for(char task : tasks){
            if(taskCnt.find(task) != taskCnt.end()) taskCnt[task]++;
            else taskCnt[task] = 1;
        }
        vector<int> cnts = vector<int>();
        for(auto e:taskCnt) cnts.push_back(e.second);
        int maxFreq = *max_element(cnts.begin(), cnts.end());
        int mostFreqCnt = count(cnts.begin(), cnts.end(), maxFreq);
        //note this boundary value, if there is not empty slots, the total time is just the task length
        return max((int)tasks.size(), (maxFreq - 1)*(n + 1) + mostFreqCnt);
    }
};

int main()
{
    char a[] = {'A','A','A','B','B','B'};
    vector<char> input = vector<char>(a,a+6);
    Solution s = Solution();
    cout<<s.leastInterval(input,0);
}

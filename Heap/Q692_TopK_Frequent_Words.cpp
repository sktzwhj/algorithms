//
// Created by wuhuijun on 1/7/18.
//
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

//a simple problem. just use the priority queue.

struct cmp{
    bool operator() (const pair<string,int> &a, pair<string,int> &b){
        if(a.second > b.second)
            return false;
        else if(a.second == b.second)
            return (a.first > b.first);
        else
            return true;
    }
};


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> strFreq;
        for(string s:words){
            if(strFreq.find(s)!=strFreq.end())strFreq[s]++;
            else strFreq[s] = 1;
        }
        priority_queue<pair<string,int>, vector<pair<string,int>>,cmp> q;
        vector<string> ret;
        for(pair<string,int> e:strFreq)
            q.push({e.first,e.second});
        for(int i = 0; i < k; i++){
            ret.push_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};

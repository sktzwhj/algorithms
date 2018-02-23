//
// Created by wu061 on 23/02/18.
//

#include <vector>
#include<iostream>
#include<queue>

using namespace std;

/*
 * we can organize two heaps, for profits we make a max heap since we want to get the max profits while for capitals
 * we maintain a min heap since we cannot start a project which requires more capital.
 */


class CapitalsCompare {
public:
    bool operator()(pair<int, int> n1, pair<int, int> n2) {
        return n1.second > n2.second;
    }
};

class ProfitCompare {
public:
    bool operator()(pair<int, int> n1, pair<int, int> n2) {
        return n1.second < n2.second;
    }
};


class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int> &Profits, vector<int> &Capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, CapitalsCompare> capitalHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, ProfitCompare> profitHeap;
        for (int i = 0; i < Profits.size(); i++)
            capitalHeap.push(make_pair(i, Capital[i]));

        int projectCnt = 0;
        int curCapital = W;
        while (projectCnt < k) {
            //move all the candidate projects from capital heap to profit heap
            while (capitalHeap.size() != 0 && capitalHeap.top().second <= curCapital) {
                //cout<<"capital heap size: "<<capitalHeap.size()<<endl;
                pair<int, int> top = capitalHeap.top();
                capitalHeap.pop();
                profitHeap.push(make_pair(top.first, Profits[top.first]));
            }
            if (profitHeap.size() != 0) {
                curCapital += profitHeap.top().second;
                profitHeap.pop();
                projectCnt++;
            } else
                break;
        }
        return curCapital;
    }
};

int main() {
    Solution s = Solution();
    int prof[] = {1, 2, 3};
    int cap[] = {1, 1, 2};
    vector<int> Profits = vector<int>(prof, prof + 3);
    vector<int> Capitals = vector<int>(cap, cap + 3);
    cout << s.findMaximizedCapital(1, 0, Profits, Capitals);
}
//
// Created by wu061 on 17/11/17.
//

/*
 * using greedy algorithm.
 * When we use greedy algorithm, we should consider whether the optimal substructure can be satisfied.
 * The optimal substructure means that the optimal solution for the problem include the optimal solution for the subproblems.
 * Therefore, when you make decisions for sub problems, you do not need to consider the solutions you might give to the
 * future subproblems.
 */
#include<vector>
#include<algorithm>
#include<iostream>
#include<limits>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

auto sortRuleLambda = [](const Interval &s1, const Interval &s2) -> bool {
    if (s1.start != s2.start)
        return s1.start < s2.start;
    else
        return s1.end > s2.end;
};


class Solution {
public:
    int eraseOverlapIntervals(vector <Interval> &intervals) {
        if (intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), sortRuleLambda);
        int lastEnd = intervals[0].end;
        int lastStart = intervals[0].start;
        int removeCnt = 0;
        for (int i = 1; i < intervals.size(); i++) {
            //cout<<intervals[i].start<<" "<<intervals[i].end<<endl;
            if (intervals[i].start < lastEnd) {
                if (intervals[i].end <= lastEnd) {
                    lastEnd = intervals[i].end;
                    lastStart = intervals[i].start;
                }
                removeCnt++;
            } else {
                lastEnd = intervals[i].end;
                lastStart = intervals[i].start;
            }

        }
        return removeCnt;
    }
};

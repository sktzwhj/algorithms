//
// Created by WuHuijun on 17/7/18.
//

#include "headers.h"

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

//first solution, AC but only beats around 9%.
class Solution {
public:
    vector <Interval> merge(vector <Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.start < b.start; });
        int index = 1;
        while (index < intervals.size()) {
            if (intervals[index - 1].end >= intervals[index].start) {
                intervals[index - 1].end = max(intervals[index].end, intervals[index - 1].end);
                intervals.erase(intervals.begin() + index);
            } else {
                index++;
            }
        }
        return intervals;
    }
};

//trade space for performance. beats over 99%.
class Solution {
public:
    vector <Interval> merge(vector <Interval> &intervals) {
        vector <Interval> res;
        if (intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.start < b.start; });
        int index = 1, last_start = intervals[0].start;
        int last_end = intervals[0].end;
        while (index < intervals.size()) {
            if (last_end >= intervals[index].start) {
                last_end = max(last_end, intervals[index].end);
            } else {
                Interval to_insert(last_start, last_end);
                res.push_back(to_insert);
                last_start = intervals[index].start;
                last_end = intervals[index].end;
            }
            index++;
        }
        Interval to_insert(last_start, last_end);
        res.push_back(to_insert);
        return res;
    }
};

int main() {
    Interval a(1, 4), b(4, 5);
    vector <Interval> input = {a, b};
    Solution s = Solution();
    for (auto interval:s.merge(input)) {
        cout << "(" << interval.start << ", " << interval.end << endl;
    }
}
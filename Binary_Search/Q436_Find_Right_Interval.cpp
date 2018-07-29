//
// Created by WuHuijun on 27/7/18.
//

#include "headers.h"

class Solution {
public:
    vector<int> findRightInterval(vector <Interval> &intervals) {
        vector<int> res;
        if (intervals.empty()) return res;
        vector <pair<Interval, int>> IntervalWithIdx;
        for (int i = 0; i < intervals.size(); i++) {
            IntervalWithIdx.push_back({intervals[i], i});
        }
        sort(IntervalWithIdx.begin(), IntervalWithIdx.end(), \
        [](pair<Interval, int> &a, pair<Interval, int> &b) { return a.first.start < b.first.start; });
        for (int i = 0; i < intervals.size(); i++) {
            res.push_back(binaryIntervalSearch(IntervalWithIdx, intervals[i], i));
        }
        return res;
    }

private:
    int binaryIntervalSearch(vector <pair<Interval, int>> &vec, Interval &query, int queryIdx) {
        int queryEnd = query.end;
        int start = 0, end = vec.size() - 1;
        int mid = (start + end) >> 1;
        while (start <= end) {
            mid = (start + end) >> 1;
            if (vec[mid].first.start < queryEnd) start = mid + 1;
            else end = mid - 1;
        }
        //now we have different situations: the vec[mid].first.start can be either leq/less than queryEnd

        for (int i = max(0, mid - 1); i <= min(mid + 1, static_cast<int>(vec.size()) - 1); i++) {
            if (vec[i].first.start >= queryEnd && (vec[i].second != queryIdx))
                return vec[i].second;
        }
        return -1;
    }
};

int main() {
    vector <Interval> input = {Interval(1, 2), Interval(2, 3)};
    Solution s = Solution();
    vector<int> res = s.findRightInterval(input);
    for (auto ele : res) cout << ele << endl;
}
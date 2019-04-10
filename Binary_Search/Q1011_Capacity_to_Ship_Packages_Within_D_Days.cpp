//
// Created by wuhuijun on 4/10/19.
//

#include "headers.h"

//use binary search. the retionale behind this is that if a smaller capacity could work. the larger ones can also work.

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int end = accumulate(weights.begin(), weights.end(), 0);
        int start = ceil(end / D);
        int mid = -1;
        while (start < end) {
            mid = (start + end)/2;
            if (validation(weights, D, mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return end;
    }

private:
    bool validation(vector<int>& weights, int D, int capacity) {
        int ship_cnt = 1;
        int current_ship_capacity = capacity;
        for (int i = 0; i < weights.size(); ++i) {
            if (current_ship_capacity >= weights[i]) {
                current_ship_capacity -= weights[i];
            } else {
                ship_cnt += 1;
                current_ship_capacity = capacity - weights[i];
                if (current_ship_capacity < 0) return false;
            }
        }
        return (ship_cnt > D) ? false: true;
    }
};

int main() {
    vector<int> input = {1, 2, 3, 1, 1};
    Solution s = Solution();
    cout<<s.shipWithinDays(input, 4);
}
//
// Created by wu061 on 5/08/18.
//

#include "headers.h"

class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        sort(people.begin(), people.end(), greater<int>());
        int i = 0;
        int num_boats = 0, curr_weight = 0;
        vector<pair<int, int>> weights(1, {0, 0});
        vector<int> full(1, 0);
        for (int j = 0; j < people.size(); j++) {
            int waste = limit, pos = -1;
            int k = 0;
            while (k < weights.size()) {
                if (!full[k] && weights[k].first + people[j] <= limit) {
                    int tmp_waste = limit - weights[k].first - people[j];
                    if (tmp_waste < waste) {
                        waste = tmp_waste;
                        pos = k;
                    }
                }
                k++;
            }
            if (pos != -1) {
                weights[pos].first += people[j];
                weights[pos].second += 1;
                if (weights[pos].second == 2 || weights[k].first == limit) full[pos] = 1;
            } else {
                weights.push_back({people[j], 1});
                if (weights[k].first == limit) full.push_back(1);
                else full.push_back(0);
            }
        }
        return weights.size();

    }
};

//I initially came up with the above solution. However, it turns out that for the case where each boat can have at most
//2 people, a much simpler two-pointer solution should be faster.
//just check whether the heaviest one can go with the lightest one.

class Solution {
public:
    int numRescueBoats(vector<int> people, int limit) {
        int i, j;
        sort(people.rbegin(), people.rend());
        for (i = 0, j = people.size() - 1; i <= j; ++i)
            if (people[i] + people[j] <= limit) j--;
        return i;
    }
};

int main() {
    vector<int> input = {3, 2, 3, 2, 2};
    Solution s = Solution();
    cout << s.numRescueBoats(input, 6);
}
//
// Created by WuHuijun on 25/5/18.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        int cover_cnt = 0, num_lists = nums.size();
        vector<pair<int, int>> merged_list;
        unordered_map<int, int> list_cover_cnt;
        for (int i = 0; i < num_lists; i++) {
            list_cover_cnt[i] = 0;
            for (auto e:nums[i]) {
                merged_list.push_back({e, i});
            }
        }
        sort(merged_list.begin(), merged_list.end());
        vector<int> res = {0, merged_list[merged_list.size() - 1].first};
        
        int left = 0;
        //left and right indexes merged_list
        int curr_window_size = res[1] - res[0];
        for (int right = 0; right < merged_list.size(); right++) {
            if (list_cover_cnt[merged_list[right].second] == 0) cover_cnt++;
            list_cover_cnt[merged_list[right].second]++;
            while (cover_cnt == num_lists && left < right) {
                int tmp_window_size = merged_list[right].first - merged_list[left].first;
                if (tmp_window_size < curr_window_size) {
                    curr_window_size = tmp_window_size;
                    res = {merged_list[left].first, merged_list[right].first};
                }
                
                list_cover_cnt[merged_list[left].second]--;
                if (list_cover_cnt[merged_list[left].second] == 0) cover_cnt--;
                left++;
                
            }
        }
        return res;
    }
};

int main() {
    //[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
    vector<vector<int>> input;
    input = {{4, 10, 15, 24, 26},
        {0, 9,  12, 20},
        {5, 18, 22, 30}};
    Solution s = Solution();
    vector<int> ret = s.smallestRange(input);
    for (auto e:ret) cout << e << endl;
}

//
// Created by wuhuijun on 2/25/18.
//

#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;


/*
 * given an unsorted array, find the max difference between the successive elements in its sorted form.
 * requirements: linear time/space complexity.
 * Although all comparison-based sorting algorithms need to obey the O(nlogn) lower bound for time complexity, the bucket
 * sorting algorithm might be able to achieve linear complexity on proper data distributions.
 */

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        int maxgap = 0;
        if (nums.size() < 2) return maxgap;
        int max_v = *max_element(nums.begin(), nums.end());
        int min_v = *min_element(nums.begin(), nums.end());
        int BUCKET_SIZE = max(1, (max_v - min_v) / ((int) nums.size() - 1));
        int BUCKET_NUM = (max_v - min_v) / BUCKET_SIZE + 1;
        vector<vector<int>> buckets;
        for (int q = 0; q <= BUCKET_NUM; q++) {
            vector<int> tmp;
            buckets.push_back(tmp);
        }
        for (int i = 0; i < nums.size(); i++) {
            int bucket_index = (nums[i] - min_v) / BUCKET_SIZE;
            vector<int>::iterator pos = buckets[bucket_index].end();
            for (int j = 0; j < buckets[bucket_index].size(); j++) {
                if (buckets[bucket_index][j] > nums[i]) {
                    pos = buckets[bucket_index].begin() + j;
                    break;
                }
            }
            buckets[bucket_index].insert(pos, nums[i]);
        }
        vector<int> sort_array;
        for (int k = 0; k <= BUCKET_NUM; k++) {
            if (buckets[k].size() > 0) {
                for (int v = 0; v < buckets[k].size(); v++)sort_array.push_back(buckets[k][v]);
            }
        }
        for (int p = 0; p < sort_array.size() - 1; p++) {
            int gap = sort_array[p + 1] - sort_array[p];
            if (gap > maxgap) maxgap = gap;
        }
        return maxgap;
    }
};

int main() {
    int a[] = {1, 1, 1, 1};
    vector<int> input = vector<int>(a, a + 4);
    Solution s = Solution();
    cout << s.maximumGap(input);
}
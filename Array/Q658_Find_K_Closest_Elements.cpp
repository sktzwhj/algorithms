//
// Created by wu061 on 17/03/18.
//
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

/*
 * simple algorithm. since the array is sorted, just use binary search. finally we nned to use a sliding window to find
 * out the best match.
 */

class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int closest_index = closestIndex(arr, x);
        //the starting point of the window is [max(closest_index-k+1. 0), min(arr.size()-1, closest_index+k-1)]
        int MIN_WINDOW_START = max(closest_index - k + 1, 0);
        int MAX_WINDOW_END = min((int) arr.size() - 1, closest_index + k - 1);
        int window_start = MIN_WINDOW_START, window_end = window_start + k - 1;
        vector<int> ret;
        for (int i = 0; i < arr.size(); i++) {
            arr[i] -= x;
        }
        int tmp_distance_sum = 0;
        int ret_window_start = window_start;

        for (int j = window_start; j < window_start + k; j++) tmp_distance_sum += abs(arr[j]);
        int min_distance_sum = tmp_distance_sum;

        while (window_end < MAX_WINDOW_END) {
            window_start++;
            window_end++;
            tmp_distance_sum = tmp_distance_sum + abs(arr[window_end]) - abs(arr[window_start - 1]);
            if (tmp_distance_sum < min_distance_sum) {
                //cout<<"index update"<<endl;
                //cout<<"tmp_distance_sum = "<<tmp_distance_sum<<" min_distance_sum = "<<min_distance_sum<<endl;
                min_distance_sum = tmp_distance_sum;
                ret_window_start = window_start;
            }

        }
        for (int i = 0; i < k; i++) {
            ret.push_back(arr[ret_window_start + i] + x);
        }
        return ret;
    }

private:
    int closestIndex(vector<int> &arr, int x) {
        int start = 0, end = arr.size() - 1;
        int closest_index = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            closest_index = mid;
            if (arr[mid] == x) break;
            else if (arr[mid] > x) end = mid - 1;
            else start = mid + 1;
        }
        //cout<<"closest index: "<<closest_index<<endl;
        return closest_index;
    }
};

int main() {
    int a[] = {1, 2, 3, 4, 5};
    vector<int> input(a, a + sizeof(a));
    Solution s = Solution();
    vector<int> ret = s.findClosestElements(input, 4, 3);
    for (auto ele:ret) cout << " " << ele;
}

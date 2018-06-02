//
// Created by wuhuijun on 6/2/18.
//

#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

//first attempt, TLE.
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        multimap<int, pair<int,int>, less_equal<int>> q;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                q.insert({abs(nums[i] - nums[j]), {i, j}});
            }
        }
        int curr = 1;
        for(auto it = q.begin(); it != q.end(); it++){
            //cout<<"curr = "<<curr<<" ,k = "<<k<<endl;
            if(curr++ == k) return (*it).first;
        }
    }
};

#include <vector>
#include <iostream>
#include <algorithm>

/*
 * we firstly tried different built-in sorted data structures, all of them
 * got TLE. But if the max value of nums is fixed, we can use radix sort to improve it.
 */

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int> &nums, int k) {
        vector<int> sorted_dist(*max_element(nums.begin(), nums.end()), 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                ++sorted_dist[abs(nums[i] - nums[j])];
            }
        }
        vector<int> flat_sort_dist;
        int cnt = 0;
        for (int i = 0; i < sorted_dist.size(); ++i) {
            for (int j = 0; j < sorted_dist[i]; ++j) {
                ++cnt;
                if (cnt == k) return i;
            }
        }
    }
};

int main() {
    vector<int> input = {1, 6, 1};
    Solution s = Solution();
    cout << s.smallestDistancePair(input, 3);
}

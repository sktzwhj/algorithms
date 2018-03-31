//
// Created by wu061 on 31/03/18.
//

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


//first a brute-force method which gets TLE. the problem is that we actually do too much redundant multiplication

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int num_size = nums.size();
        int product = 1, cnt = 0;
        for(int end = num_size - 1; end >= 0; end--){
            for(int start = end; start >= 0; start--){
                product *= nums[start];
                if(product < k) cnt++;
                else break;
            }
            product = 1;
        }
        return cnt;
    }
};

//after removing the redundant computations
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0) return 0;
        int num_size = nums.size();
        int product = 1, cnt = 0, start = 0;
        for(int end = 0; end < num_size; end++){
            product *= nums[end];
            while(product >= k && start <= end) product/= nums[start++];
            cnt += (end - start + 1);
        }
        return cnt;
    }
};

int main()
{
    int a[] = {1,1,1};
    vector<int> input(a, a+3);
    Solution s = Solution();
    cout<<s.numSubarrayProductLessThanK(input, 1);
}
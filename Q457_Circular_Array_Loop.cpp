//
// Created by wuhuijun on 11/13/17.
//
/*
 * the code requires more debug
 */
#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int> &nums) {
        int remain = nums.size();


        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                int count = 0;
                int j = i;

                while (nums[j] != 0) {

                    int tmp = nums[j];
                    j = (j + tmp + nums.size()) % nums.size();
                    if (nums[j] == 0 || nums[j] * tmp < 0)
                        break;
                    count++;
                    if (count >= remain)
                        return 1;
                }

                j = i;
                while (nums[j] != 0) {
                    int tmp = nums[j];
                    nums[j] = 0;
                    j = (j + tmp + nums.size()) % nums.size();

                    if (nums[j] == 0 || tmp * nums[j] < 0)
                        break;
                    remain--;

                }
            }
        }
        return 0;
    }
};

int main() {
    Solution s = Solution();
    int a[] = {2, -1, 1, 2, 2};
    vector<int> input = vector<int>(a, a + 5);
    cout << s.circularArrayLoop(input);
}

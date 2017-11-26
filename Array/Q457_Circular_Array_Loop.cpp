//
// Created by wuhuijun on 11/13/17.
//
/*
 * This problem can be solved by using DFS. You do DFS on the vector according to the values, if you have walked for steps
 * which are more than the number of remained active values in the vector, that means you are walking in a loop. The reason
 * why we say active is that if a path is passed and proved not a loop, you should mark them as inactive so that you would
 * not need to walk for a second time. Each time you start from the first active value to do DFS.
 * Another hint got from this problem is that when you are asked to use only
 * O(1) space, think about if you can do something in-place on the original input.
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
                    int tmp = j;
                    j = (j + nums[tmp] + nums.size()) % nums.size();
                    count++;
                    if (j == tmp || nums[j] == 0 || nums[j] * tmp < 0)
                        break;
                    if (count > remain)
                        return 1;

                }
                j = i;
                while (nums[j] != 0) {
                    int tmp = nums[j];
                    nums[j] = 0;
                    j = (j + tmp + nums.size()) % nums.size();
                    remain--;
                    if (nums[j] == 0 || tmp * nums[j] < 0)
                        break;

                }
            }
        }
        return 0;
    }
};

int main() {
    Solution s = Solution();
    int a[] = {-1,2};
    vector<int> input = vector<int>(a, a + 2);
    cout << s.circularArrayLoop(input);
}

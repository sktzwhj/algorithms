//
// Created by wuhuijun on 10/12/17.
//

#include<vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        if (nums.size() > 1) {
            vector<int> ret;
            //first element has no left product
            ret.push_back(1);
            int left_product = 1, right_product = 1;
            for (int i = 1; i < nums.size(); i++) {
                left_product *= nums[i - 1];
                ret.push_back(left_product);
            }

            for (int j = nums.size() - 2; j >= 0; j--) {
                //cout<<"j="<<j<<endl;
                right_product *= nums[j + 1];
                nums[j + 1] = right_product;
            }
            for (int s = 1; s < nums.size(); s++)
                nums[s - 1] = nums[s];
            nums[nums.size() - 1] = 1;
            for (int k = 0; k < nums.size(); k++) {
                ret[k] = ret[k] * nums[k];
                //cout<<"k="<<k<<endl;
            }

            return ret;
        }
    }
};

int main() {
    int a[] = {0, 4, 0};
    vector<int> input(a, a + 3);
    Solution s = Solution();
    vector<int> ret = s.productExceptSelf(input);
    for (int q = 0; q < ret.size(); q++)
        cout << ret[q] << endl;
}
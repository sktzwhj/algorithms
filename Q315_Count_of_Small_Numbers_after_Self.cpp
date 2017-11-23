//
// Created by wu061 on 22/11/17.
//
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

struct num {
    int index;
    int value;
};

class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {

        //printVector(nums);
        vector<int> smallerResult = vector<int>(nums.size(), 0);
        vector<num> num_values = vector<num>(nums.size());
        for (int k = 0; k < nums.size(); k++) {
            num tmp = {k, nums[k]};
            num_values.push_back(tmp);
        }

        mergeFindSmaller(num_values, 0, num_values.size() - 1, smallerResult);
        //printVector(nums);
        //printVector(smallerResult);

        return smallerResult;
    }

    void mergeFindSmaller(vector<num> &nums, int start, int end, vector<int> &smallerResult) {
        cout << "start:" << start << "num len:" << nums.size() << endl;

        if (nums.size() < 2)
            return;
        int mid = (start + end) / 2;
        vector<num> L = vector<num>();
        vector<num> R = vector<num>();
        for (int i = start; i <= mid; i++)
            L.push_back(nums[i - start]);
        for (int j = mid + 1; j <= end; j++)
            R.push_back(nums[j - start]);

        mergeFindSmaller(L, start, mid, smallerResult);
        mergeFindSmaller(R, mid + 1, end, smallerResult);
        merge(L, R, nums, start, end, smallerResult);
    }

private:
    void merge(vector<num> L, vector<num> R, vector<num> &nums, int start, int end, vector<int> &smallerResult) {
        int mid = (start + end) / 2;

        int i = start, j = mid + 1, index = 0;


        //cout << "start " << start << "end " << end << endl;
        while (i <= mid && j <= end) {
            if (L[i - start].value < R[j - mid - 1].value) {
                nums[index++] = L[i - start];

                i++;
            } else if (R[j - mid - 1].value < L[i - start].value) {
                nums[index++] = R[j - mid - 1];
                //cout << "nums[" << j << "]< nums[" << i << "]" << endl;
                for (int k = i; k <= mid; k++) {
                    smallerResult[L[i - start].index]++;
                }
                j++;


            } else {
                //if the two are equal
                nums[index++] = L[i - start];
                nums[index++] = R[j - mid - 1];
                i++;
                j++;
            }

        }

        while (i <= mid) {
            nums[index++] = L[i - start];
            i++;
        }

        while (j <= end) {
            nums[index++] = R[j - mid - 1];
            j++;
        }

    }

    void printVector(vector<int> nums) {
        cout << "the vector is:" << endl;
        for (auto e:nums)
            cout << e << endl;
    }

};

int main() {
    int a[] = {5, 2, 6, 1};
    vector<int> input = vector<int>(a, a + 4);
    Solution s = Solution();
    s.countSmaller(input);
}

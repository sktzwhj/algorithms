//
// Created by WuHuijun on 27/7/18.
//

#include "headers.h"

/*
 * initially, I was thinking about using segment tree or fenwick tree.
 * however, it turns out that since this problem is not update-dominate range sum, it's not benefitial to use those
 * since O(N^2) solution is trivial, it is obvious that we need to come up with something like nlogn
 * for this kind problems, the typical algorithms with log complexity are mergesort, binary search, etc.
 * we use mergesort here
 */

class Solution {
public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        if (nums.size() == 0) return 0;
        vector<long> prefixSum(nums.size(), nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + static_cast<long>(nums[i]);
        }
        int res = 0;
        mergeSortCount(prefixSum, 0, prefixSum.size() - 1, lower, upper, res);
        return res;
    }

private:
    void mergeSortCount(vector<long> &prefixSum, int left, int right, int lower, int upper, int &res) {
        if (left >= right) {
            if (left == right) res = ((prefixSum[left] >= lower) && (prefixSum[left] <= upper)) ? (res + 1) : res;
            return;
        }
        int mid = (left + right) / 2;
        mergeSortCount(prefixSum, left, mid, lower, upper, res);
        mergeSortCount(prefixSum, mid + 1, right, lower, upper, res);
        /*
         * we want to find pair of (leftIdx, rightIdx) which satisfy that
         * lower <= prefixSum[rightIdx] - prefixSum[leftIdx] <= upper. This is essentially
         * to find a rightIdx which satisfies lower + prefixSum[leftIdx] <= prefixSum[rightIdx] <=
         * upper + prefixSum[leftIdx]
         */
        int leftIdx = left;
        int rightIdx_lower = mid + 1, rightIdx_upper = mid + 1;
        cout << "left = " << left << ", mid = " << mid << ", right = " << right << endl;
        while (leftIdx < mid + 1) {
            while ((rightIdx_lower <= right) && (prefixSum[rightIdx_lower] - prefixSum[leftIdx] < lower))
                rightIdx_lower++;
            while ((rightIdx_upper <= right) && (prefixSum[rightIdx_upper] - prefixSum[leftIdx] <= upper))
                rightIdx_upper++;
            leftIdx++;
            cout << "rightIdx_upper = " << rightIdx_upper << ", rightIdx_lower = " << rightIdx_lower << endl;
            res += (rightIdx_upper - rightIdx_lower);
        }
        //then do the mergesort
        int len = right - left + 1;
        vector<long> mergedVec(len);
        int indexInsert = 0;
        int l = left, r = mid + 1;
        while (l <= mid && r <= right) {
            if (prefixSum[l] < prefixSum[r]) mergedVec[indexInsert++] = prefixSum[l++];
            else mergedVec[indexInsert++] = prefixSum[r++];
        }
        while (l <= mid) mergedVec[indexInsert++] = prefixSum[l++];
        while (r <= right) mergedVec[indexInsert++] = prefixSum[r++];

        for (int i = left; i <= right; i++) {
            prefixSum[i] = mergedVec[i - left];
        }
    }
};

int main() {
    vector<int> input = {-2147483647, 0, -2147483647, 2147483647};
    Solution s = Solution();
    cout << s.countRangeSum(input, -564, 3864);
}
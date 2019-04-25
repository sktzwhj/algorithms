//
// Created by wuhuijun on 4/25/19.
//

#include "headers.h"

/*
 * The most interesting part of this problem is that we have to embed the requirement of going forward into the direction
 * of the loop.
 */


class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int ans = 1, N = A.size();
        //the choice of stl map is due to the fact that it is implemented by red-black tree so that it is fast to find the smallest larger/largest smaller
        map<int, int> pos;
        vector<bool> higher(N), lower(N);
        higher[N - 1] = true;
        lower[N - 1] = true;
        pos[A[N - 1]] = N - 1;
        for (int i = N - 2; i >= 0; --i) {
            //if we were on the way to find a larger one
            auto hi = pos.lower_bound(A[i]);
            //on the way to find a smaller one
            auto lo = pos.upper_bound(A[i]);
            if (hi != pos.end()) higher[i] = lower[hi->second];
            if (lo != pos.begin()) lower[i] = higher[(--lo)->second];
            if (higher[i]) ans++;
            pos[A[i]] = i;
        }
        return ans;
    }
};

int main() {
    vector<int> input = {2, 3, 1, 1, 4};
    Solution s = Solution();
    cout<<s.oddEvenJumps(input)<<endl;
}

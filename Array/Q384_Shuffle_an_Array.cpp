//
// Created by wu061 on 17/07/18.
//

#include "hearders.h"

using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        origin_vec = vector<int>(nums.begin(), nums.end());
        permutation_vec = vector<int>(nums.begin(), nums.end());

    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        permutation_vec = origin_vec;
        return origin_vec;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        std::shuffle(permutation_vec.begin(), permutation_vec.end(),
                     default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
        return permutation_vec;
    }

private:
    vector<int> origin_vec, permutation_vec;
    vector<vector<int>> permutated_vecs;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

int main() {
    vector<int> input = {1, 2, 3};
    Solution s = Solution(input);
    vector<int> ret = s.shuffle();
    for (auto ele:ret) cout << ele << " ";
}
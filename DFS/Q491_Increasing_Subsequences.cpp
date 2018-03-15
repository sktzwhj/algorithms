//
// Created by wu061 on 15/03/18.
//

#include <vector>
#include <iostream>
#include <set>

using namespace std;

/*
 * since the given sequence is not sorted, what we can do is to perform dfs and branch prone
 */

class Solution {
public:
    vector <vector<int>> findSubsequences(vector<int> &nums) {
        //cout<<"num size:"<<nums.size()<<endl;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> path;
            set<int> pos_hash;
            dfs(nums, i, path, pos_hash);
        }
        set <vector<int>> seq_set(increasing_subseq.begin(), increasing_subseq.end());
        increasing_subseq.clear();
        for (auto e:seq_set) increasing_subseq.push_back(e);
        return increasing_subseq;
    }

private:
    vector <vector<int>> increasing_subseq;

    void dfs(vector<int> &nums, int cur_index, vector<int> &path, set<int> &pos_hash) {
        if (path.size() > 1) increasing_subseq.push_back(path);
        for (int i = cur_index; i < nums.size(); i++) {
            if ((pos_hash.count(i) == 0) && ((path.size() == 0) || nums[i] >= path.back())) {
                path.push_back(nums[i]);
                pos_hash.insert(i);
                dfs(nums, i, path, pos_hash);
                path.pop_back();
                pos_hash.erase(i);
            } else
                continue;
        }
    }
};

int main() {
    int a[] = {4, 6, 7, 7};
    vector<int> input(a, a + 4);
    Solution s = Solution();
    vector <vector<int>> ret = s.findSubsequences(input);
    for (auto vec:ret) {
        for (auto ele:vec)
            cout << ele << " ";
        cout << endl;
    }

}
//
// Created by wu061 on 12/12/18.
//

class Solution {
public:
    bool canReorderDoubled(vector<int> &A) {
        //solution: each val can either be the 1/2 of some other num or` 2 times of some other num

        int len = A.size();
        if (len == 0) return true;
        sort(A.begin(), A.end());
        int negative_len = 0;
        unordered_map<int, int> val_cnt;
        for (int i = 0; i < len; ++i) {
            val_cnt[A[i]]++;
            if (A[i] < 0) negative_len++;
        }
        //negative part
        for (int j = negative_len - 1; j > 0; --j) {
            if (val_cnt[A[j]] == 0) continue;
            if (val_cnt.find(A[j] * 2) == val_cnt.end()) return false;
            if (--val_cnt[A[j] * 2] < 0) return false;
            val_cnt[A[j]]--;
        }
        //non-negative part
        for (int j = negative_len; j < len; ++j) {
            if (val_cnt[A[j]] == 0) continue;
            if (val_cnt.find(A[j] * 2) == val_cnt.end()) return false;
            if (--val_cnt[A[j] * 2] < 0) return false;
            val_cnt[A[j]]--;
        }
        return true;
    }

};

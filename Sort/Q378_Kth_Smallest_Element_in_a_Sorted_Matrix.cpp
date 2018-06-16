//
// Created by wuhuijun on 6/15/18.
//

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

//since each row is already sorted, it is natural to come up an idea of merge sort. but we only use the second phase.

using namespace std;

class Solution {
public:
    int kthSmallest(vector <vector<int>> &matrix, int k) {
        int row_cnt = matrix.size();
        int max_merge_time = (int) log2(row_cnt) + 1;
        int cur_merge_cnt = 0, remain_row_cnt = row_cnt;
        int col_num = matrix[0].size();
        while (cur_merge_cnt < max_merge_time) {
            cur_merge_cnt++;
            if (remain_row_cnt % 2 == 0) {
                remain_row_cnt /= 2;
                merge_even_vecs(matrix, remain_row_cnt, row_cnt * col_num);
            } else {
                vector<int> last = matrix[remain_row_cnt - 1];
                matrix.pop_back();
                remain_row_cnt = (remain_row_cnt - 1) / 2;
                merge_even_vecs(matrix, remain_row_cnt, row_cnt * col_num - last.size());
                remain_row_cnt += 1;
                matrix.push_back(last);
            }
        }
        return matrix[0][k - 1];
    }

private:
    void merge_even_vecs(vector <vector<int>> &matrix, int &row_cnt, int merged_size) {
        //row_cnt must be a even number
        for (int i = 0; i < row_cnt; i++) {
            vector<int> curr_merged(matrix[2 * i].size() * 2);
            merge(matrix[2 * i].begin(), matrix[2 * i].end(), matrix[2 * i + 1].begin(), matrix[2 * i + 1].end(),
                  curr_merged.begin());
            matrix[i] = curr_merged;
        }
        matrix.erase(matrix.begin() + row_cnt, matrix.end());
    }
};

int main() {
    vector <vector<int>> m = {{5,  9,  11, 12, 14, 17, 20, 22},
                              {6,  13, 17, 22, 25, 27, 27, 32},
                              {9,  15, 22, 26, 28, 31, 35, 39},
                              {13, 16, 24, 30, 30, 33, 35, 44},
                              {16, 19, 28, 34, 39, 44, 47, 47},
                              {18, 20, 30, 39, 43, 48, 49, 53},
                              {22, 25, 32, 40, 48, 52, 56, 59},
                              {25, 26, 35, 44, 52, 57, 58, 63}};
    Solution s = Solution();
    cout << s.kthSmallest(m, 60);
}
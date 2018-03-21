//
// Created by wu061 on 21/03/18.
//

#include <vector>
#include <iostream>

using namespace std;

/*
 * seems very direct. just a simple binary search is enough
 */

class Solution {
public:
    bool searchMatrix(vector <vector<int>> &matrix, int target) {
        row_num = matrix.size();
        if (!row_num) return false;
        col_num = matrix[0].size();
        int start = 0, end = row_num * col_num - 1;
        return binary_search(matrix, start, end, target);
    }

private:
    int row_num, col_num;

    pair<int, int> index_translate(const int index) {
        int row = index / col_num;
        int col = index % col_num;
        return make_pair(row, col);
    }

    bool binary_search(vector <vector<int>> &matrix, int start, int end, const int num) {
        while (start <= end) {
            int mid = (start + end) / 2;
            pair<int, int> trans_index = index_translate(mid);
            int row = trans_index.first, col = trans_index.second;
            int val = matrix[row][col];
            if (val == num) return true;
            else if (val < num) start = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};

int main() {
    int a[] = {1, 3, 5, 7}, b[] = {10, 11, 16, 20}, c[] = {23, 30, 34, 50};
    vector<int> a_(a, a + 4), b_(b, b + 4), c_(c, c + 4);
    vector <vector<int>> input;
    input.push_back(a_);
    input.push_back(b_);
    input.push_back(c_);
    Solution s = Solution();
    cout << s.searchMatrix(input, 3) << endl;
}

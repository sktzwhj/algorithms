//
// Created by WuHuijun on 18/7/18.
//

#include "headers.h"

using namespace std;

//my solution is actually too redundant. the greedy strategy can be simple. first flip the rows whose first digit is not 1
//then flip the columns whose 1s are less than 0s. 
class Solution {
public:
    int matrixScore(vector<vector<int>> &A) {
        /*
         * our target is to make as more as 1s as we can. so the strategy can be like this.
         * every time we choose the row/col which has more 0s than 1s, do the flip until there
         * are no row/col satisfies with this condition.
         */
        int row_num = A.size(), col_num = A[0].size();
        bool row_updated = false, col_updated = false;
        do {
            row_updated = false;
            col_updated = false;
            map<pair<int, int>, int> p_map;
            for (int r = 0; r < row_num; r++) row_updated = row_updated || updateRowPriority(A, p_map, r);
            for (int c = 0; c < col_num; c++) col_updated = col_updated || updateColPriority(A, p_map, c);
            vector<pair<pair<int, int>, int>> p_vec(p_map.begin(), p_map.end());
            sort(p_vec.begin(), p_vec.end(),
                 [](const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
                     return a.second < b.second;
                 });
            if (p_vec.size() > 0) flip(p_vec[0].first, A);
        } while (row_updated || col_updated);
        int res = 0;
        for (auto vec:A) {
            for (int i = 0; i < vec.size(); i++) res += pow(2, vec.size() - 1 - i) * vec[i];
        }
        return res;
    }

private:
    void flip(pair<int, int> idx, vector<vector<int>> &A) {

        if (idx.first == -1) {
            //flip col
            for (int r = 0; r < A.size(); r++) A[r][idx.second] = (A[r][idx.second] == 0) ? 1 : 0;
        } else {
            for (int c = 0; c < A[0].size(); c++) A[idx.first][c] = (A[idx.first][c] == 0) ? 1 : 0;
        }
    }

    bool updateColPriority(vector<vector<int>> &A, map<pair<int, int>, int> &p_map, int col) {
        int zero_cnt = 0;
        for (int r = 0; r < A.size(); r++)
            if (A[r][col] == 0) zero_cnt++;
        int one_cnt = A.size() - zero_cnt;
        int priority = zero_cnt - one_cnt;
        if (priority > 0) {
            p_map[make_pair(-1, col)] = zero_cnt - one_cnt;
            return true;
        } else {
            //p_map.erase(make_pair(-1, col));
            return false;
        }
    }

    bool updateRowPriority(vector<vector<int>> &A, map<pair<int, int>, int> &p_map, int row) {
        int zero_cnt = count(A[row].begin(), A[row].end(), 0);
        int one_cnt = A[0].size() - zero_cnt;
        int priority = zero_cnt - one_cnt;
        if (A[row][0] == 0) {
            p_map[make_pair(row, -1)] = zero_cnt - one_cnt;
            return true;
        }
        //p_map.erase(make_pair(row, -1));
        return false;
    }
};

int main() {
    vector<vector<int>> input = {{0, 0, 1},
                                 {1, 1, 1},
                                 {0, 1, 0}};
    Solution s = Solution();
    cout << s.matrixScore(input);
}

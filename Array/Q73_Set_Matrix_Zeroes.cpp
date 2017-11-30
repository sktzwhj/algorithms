//
// Created by wu061 on 30/11/17.
//

#include<vector>

using namespace std;

//the problem asks for constant space complexity so that we need to make use of the existing space in the matrix.
//the idea is to use the 1st row and the 1st col.

class Solution {
public:
    void setZeroes(vector <vector<int>> &matrix) {
        if (matrix.size() > 0) {
            int numRow = matrix.size();
            int numCol = matrix[0].size();
            bool clear_1st_row = false;
            bool clear_1st_col = false;
            for (int i = 0; i < numRow; i++)
                for (int j = 0; j < numCol; j++) {
                    if (matrix[i][j] == 0) {
                        if (i == 0)
                            clear_1st_row = true;
                        if (j == 0)
                            clear_1st_col = true;
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            if (numRow > 1 && numCol > 1) {
                //start from i = 1, do not pollute the matrix
                for (int i = 1; i < numRow; i++) {
                    if (matrix[i][0] == 0) {
                        for (int k = 1; k < numCol; k++)
                            matrix[i][k] = 0;
                    }
                }
            }

            if (numRow > 1 && numCol > 1) {
                for (int i = 1; i < numCol; i++) {
                    if (matrix[0][i] == 0) {
                        for (int k = 1; k < numRow; k++)
                            matrix[k][i] = 0;
                    }
                }
            }
            
            if (clear_1st_row) {
                for (int i = 0; i < numCol; i++)
                    matrix[0][i] = 0;
            }

            if (clear_1st_col) {
                for (int i = 0; i < numRow; i++)
                    matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    int a[] = {1, 0};
    Solution s = Solution();
    vector<int> input1 = vector<int>(a, a + 2);
    vector <vector<int>> input;
    input.push_back(input1);
    s.setZeroes(input);
}
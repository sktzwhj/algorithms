//
// Created by wu061 on 16/03/18.
//

#include <vector>
#include <iostream>
using namespace std;


/*
 * after rotate, the original col num becomes the current row num. so the position of a data point will change from
 * (i, j) to (j, n - i) after the rotation. in order to do the in-place update, we need to find a chain to update
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        if(!N) return;
        for(int row = 0; row < N; row++){
            for(int col = 0; col < N; col++){
                if(need_update(matrix, row, col, N)){
                    update(matrix, row, col, N);
                }
            }
        }
    }

private:
    bool need_update(const vector<vector<int>>& matrix, const int row, const int col, const int N){
        pair<int,int> new_pos = make_pair(row, col);
        do{
            new_pos = get_new_pos(new_pos.first, new_pos.second, N);
            if(new_pos.first*N + new_pos.second < row*N + col){
                //cout<<"update is not necessary"<<endl;
                return false;
            }
        }while(new_pos.first != row || new_pos.second != col);
        //cout<<"update is necessary"<<endl;
        return true;
    }

    void update(vector<vector<int>>& matrix, const int row, const int col, const int N){
        pair<int,int> new_pos = get_new_pos(row, col, N);
        int curr_value = matrix[row][col];
        int next_value = matrix[new_pos.first][new_pos.second];
        //cout<<"update sequence..."<<endl;
        int curr_row, curr_col;
        do{
            matrix[new_pos.first][new_pos.second] = curr_value;
            curr_row = new_pos.first, curr_col = new_pos.second;
            curr_value = next_value;
            new_pos = get_new_pos(new_pos.first, new_pos.second, N);
            next_value = matrix[new_pos.first][new_pos.second];
        }while(curr_row != row || curr_col != col);
    }

    pair<int,int> get_new_pos(const int row, const int col, const int N){
        return make_pair(col, N - row - 1);
    };
};

int main()
{
    int a[] = {1,2};
    int b[] = {4,5};
    int c[] = {7,8,9};
    vector<int> a_(a,a+2), b_(b, b+2), c_(c,c+3);
    vector<vector<int>> input;
    input.push_back(a_);
    input.push_back(b_);
    //input.push_back(c_);
    Solution s = Solution();
    s.rotate(input);
    for(auto vec:input){
        for(auto ele:vec){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

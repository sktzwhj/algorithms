//
// Created by wu061 on 25/09/17.
//

#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
    int getLiveNeigbors(int i, int j, vector <vector<int>> &board) {
        int board_m = (int) (board.size());
        int board_n = (int) (board[0].size());
        int liveCnt = 0;
        for (int p = max(i - 1, 0); p <= min(i + 1, board_m - 1); p++)
            for (int q = max(j - 1, 0); q <= min(j + 1, board_n - 1); q++) {
                if (p == i && q == j)
                    continue;
                if (board[p][q] == 1) {
                    liveCnt++;
                }
            }
        return liveCnt;
    }

    void gameOfLife(vector <vector<int>> &board) {
        vector <vector<int>> newStatus;
        if (board.size() == 0) {
            cout << "0 size board" << endl;
            return;
        }


        for (int i = 0; i < (int) (board.size()); i++) {
            //cout<<"enter loop";
            vector<int> tmp_row;
            for (int j = 0; j < (int) (board[i].size()); j++) {
                int liveNeigborCnt = getLiveNeigbors(i, j, board);
                cout << "liveNeigborCnt=" << liveNeigborCnt << endl;
                int tmp_status = board[i][j];
                if (board[i][j] == 0) {
                    //cout<<"if"<<endl;
                    if (liveNeigborCnt == 3)
                        tmp_status = 1;
                } else {

                    //cout<<"else"<<endl;
                    if (liveNeigborCnt < 2 || liveNeigborCnt > 3)
                        tmp_status = 0;
                    else if (liveNeigborCnt == 2 || liveNeigborCnt == 3)
                        tmp_status = 1;
                }
                //cout<<"push back "<<tmp_status<<" to tmp_row"<<endl;
                tmp_row.push_back(tmp_status);
            }
            newStatus.push_back(tmp_row);

        }

        for (int i = 0; i < (int) (board.size()); i++) {
            for (int j = 0; j < (int) (board[i].size()); j++) {
                cout << endl;
                printf("board[%d][%d]=%d and newStatus[%d][%d]=%d\n", i, j, board[i][j], i, j, newStatus[i][j]);
                board[i][j] = newStatus[i][j];
            }
        }


    }
};

int main() {
    cout << "?" << endl;
    vector <vector<int>> input;
    vector<int> a, b;
    a.push_back(1);
    a.push_back(1);
    b.push_back(1);
    b.push_back(0);
    input.push_back(a);
    input.push_back(b);
    Solution s = Solution();
    s.gameOfLife(input);
    for (int i = 0; i < (int) (input.size()); i++) {
        for (int j = 0; j < (int) (input[i].size()); j++) {
            cout << "input[" << i << "][" << j << "]" << input[i][j] << endl;
        }
    }


}
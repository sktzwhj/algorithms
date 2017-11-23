//
// Created by wu061 on 21/09/17.
//
/*
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
 */

/*
 * suppose we start from point (x,y) and the destination is (x1,y1), in total we need to go x1-x steps to the right direction and y1-y steps to the down steps.
 * so it becomes the combination problem - put x1-x 1s in a sequence of 01 with length (x1-x+y1-y)
 */
#include<iostream>
class Solution {
public:
    void print(int* bitmap,int n){
        for (int ss = 0; ss < n; ss++) {
            if (bitmap[ss] == 1)
                std::cout << "1";
            else
                std::cout << "0";
        }
        std::cout << std::endl;
    }

    int getCombinationNumber(int m,int n) {
        std::cout<<m<<n<<std::endl;

        int *bitmap = new int[n];
        for (int i = 0; i < n; i++)
            if(i<m)
                bitmap[i] = 1;
            else
                bitmap[i] = 0;
        bool end = 0;
        int cnt = 1;
        print(bitmap,n);
        while (!end) {
            end = 1;
            for (int j = 1; j < n; j++) {
                if (bitmap[j] == 0 && bitmap[j - 1] == 1) {
                    cnt++;
                    bitmap[j] = 1;
                    bitmap[j - 1] = 0;
                    int shift_cnt = 0;
                    for (int k = 0; k < j - 1; k++) {
                        if (bitmap[k] == 0) {
                            shift_cnt += 1;
                        }
                    }
                    for (int q = j - 2; q > 0; q--) {
                        bitmap[q - shift_cnt] = 1;
                    }
                    for (int s = 0; s < shift_cnt; s++) {
                        bitmap[j - 2 - s] = 0;
                    }
                    end = 0;
                    print(bitmap,n);

                    break;
                }
            }
        }

        return cnt;
    }

    int uniquePaths(int m, int n) {
        int total_step = m + n - 2;
        return getCombinationNumber(m-1,total_step);
    }
};

int main(){

    Solution s = Solution();
    std::cout<<s.uniquePaths(7,8);
}
//
// Created by wu061 on 21/09/17.
//
#include<stack>
#include<vector>
#include<string>
#include<iostream>

class Solution {
public:

    int n = 0;
    int combination_num = 0;
    int bitmap_size = 0;

    Solution() {}

    Solution(int nsize) {
        n = nsize;
        combination_num = n - 2;
        bitmap_size = (n - 2) / 2;
    }

    bool validationCheck(int *bitmap) {
        int left_cnt, right_cnt;
        left_cnt = 1;
        right_cnt = 0;
        for (int c = 0; c < combination_num; c++) {
            if (bitmap[c] == 1)
                left_cnt++;
            else
                right_cnt++;
            //std::cout<<"left_cnt"<<left_cnt<<" "<<"right_cnt"<<right_cnt<<std::endl;
            if (right_cnt > left_cnt) {
                return 0;

            }

        }
        return 1;
    }

    std::vector <std::string> generateParenthesis() {
        /*
         * the first position must be left bracket while the last position must be right bracket
         * we still have n-2 positions to choose for a left bracket. this is a typical combination problem
         * we use bitmap to solve the problem
         * once the left brackets are decided, we are done.
         */
        //get all combinations to choose (n-2)/2 positions from n-2 positions

        int *bitmap = new int[combination_num];
        for (int i = 0; i < bitmap_size; i++)
            bitmap[i] = 1;
        bool end = 0;
        int left_cnt, right_cnt;
        while (!end) {
            end = 1;
            for (int j = 0; j < combination_num; j++) {

                if (bitmap[j] == 0 && bitmap[j - 1] == 1) {

                    if (validationCheck(bitmap)) {
                        std::cout << "(";
                        for (int ss = 0; ss < combination_num; ss++) {
                            if (bitmap[ss] == 1)
                                std::cout << "(";
                            else
                                std::cout << ")";
                        }
                        std::cout << ")";
                        std::cout << std::endl;
                        bitmap[j] = 1;
                    }

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
                    break;
                }
            }

        }
        if (validationCheck(bitmap)) {
            std::cout << "(";
            for (int ss = 0; ss < combination_num; ss++) {
                if (bitmap[ss] == 1)
                    std::cout << "(";
                else
                    std::cout << ")";

            }
            std::cout << ")";
            std::cout << std::endl;
        }


        free(bitmap);
        std::vector <std::string> ret = std::vector<std::string>();
        return ret;
    }

};

int main() {
    Solution s = Solution(6);
    s.generateParenthesis();
}
//
// Created by wu061 on 24/11/17.
//
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int digitLen = digits.size();
        digits[digitLen - 1]++;
        for(int i = digitLen - 1; i >= 0; i--){
            if(digits[i] == 10){
                digits[i] = 0;
                if(i > 0)
                    digits[i-1]++;
                else{
                    digits.resize(digitLen + 1);
                    for(int j = digitLen - 1; j > 0; j--)
                        digits[j+1] = digits[j];
                    digits[0] = 1;
                }
            }
        }
        return digits;
    }
};

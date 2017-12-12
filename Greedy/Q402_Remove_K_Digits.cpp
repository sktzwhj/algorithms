//
// Created by wuhuijun on 12/12/17.
//
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int remainLen = num.size() - k;
        //to make the number the smallest, just make the high-weight digits smaller
        //the first digit can be chosen from the first k values and it cannot be 0
        string ret = string();
        int digitIndex = 0;
        int chosenValue = num[0];
        int chosenIndex = 0;
        int start = 0, end = k;
        while (digitIndex < remainLen) {
            //cout<<"start:"<<start<<" end:"<<end<<endl;
            for (int i = start; i <= end; i++) {
                if (num[i] < chosenValue) {
                    chosenValue = num[i];
                    chosenIndex = i;
                }
            }
            start = chosenIndex + 1;
            end = k + digitIndex + 1;
            digitIndex++;
            //cout<<"chosenIndex:"<<chosenIndex<<endl;
            ret += num[chosenIndex];
            chosenValue = num[start];
            chosenIndex = start;
        }
        string real_ret = string();
        for (int i = 0; i < ret.size(); i++) {
            if (ret[i] == '0') {
                continue;
            } else {
                for (int j = i; j < ret.size(); j++)
                    real_ret += ret[j];
                break;
            }
        }
        if (real_ret.size() == 0)
            return "0";
        return real_ret;
    }
};

int main() {
    string input = "1432219";
    Solution s = Solution();
    cout << s.removeKdigits(input, 3);
}

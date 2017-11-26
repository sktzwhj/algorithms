//
// Created by wuhuijun on 11/26/17.
//
#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long digitsCDF[11];
        long curVal = 0;
        digitsCDF[0] = 0;
        for (int j = 1; j < 11; j++) {
            curVal = curVal + j * (pow(10, j) - pow(10, j - 1));
            digitsCDF[j] = curVal;
            //cout<<"digitsCDF["<<j<<"]"<<digitsCDF[j]<<endl;
        }
        for (int i = 1; i < 11; i++) {
            if (digitsCDF[i - 1] < n && n <= digitsCDF[i]) {
                //this indicates that the number has i digits, then we see the rank of it in the number
                //note that in the same group, all numbers have the same number of digits.
                long numberOrder = ceil((double) (n - digitsCDF[i - 1]) / ((double) i));
                cout << "numberOrder" << numberOrder << endl;
                //cout<<n<<endl;
                long digitOrder = n - digitsCDF[i - 1] - (numberOrder - 1) * (i);
                long num = pow(10, i - 1) + (numberOrder - 1);
                cout << "num:" << num << endl;
                //cout<<"digitOrder:"<<digitOrder<<endl;
                long ret = num;
                //cout<<numberOrder<<endl;
                //cout<<digitOrder<<endl;
                return to_string(num)[digitOrder - 1] - '0';
            }
        }
    }
};

int main() {
    int input = 11;
    Solution s = Solution();
    cout << s.findNthDigit(input);
}

//
// Created by wuhuijun on 4/11/19.
//

#include "headers.h"

class Solution {
public:
    bool isValid(string S) {
        if (S.empty()) return true;
        else {
            int index = S.find("abc");
            if (index >= 0) {
                S.erase(index, 3);
                return isValid(S);
            } else {
                return false;
            }
        }
    }
};


int main() {
    Solution s = Solution();
    cout<<s.isValid("aabcbc");
}
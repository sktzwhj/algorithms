//
// Created by wu061 on 1/06/18.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_pos = 0, t_pos = 0, find_pos = -1;
        int s_len = s.size(), t_len = t.size();
        while (s_pos < s_len) {
            cout<<"search for "<<s[s_pos]<<endl;
            t = t.substr(find_pos + 1);
            find_pos = t.find(s[s_pos++]);
            cout<<find_pos<<endl;
            if(find_pos == -1) return false;
        }
        return true;
    }
};

int main() {
    string s = "ad";
    string t = "abcde";
    Solution ss = Solution();
    cout << ss.isSubsequence(s, t);
}
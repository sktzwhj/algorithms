//
// Created by wu061 on 1/04/18.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string> &d) {
        string ret = "";
        sort(d.begin(), d.end(),
             [](string &a, string &b) { if (a.size() != b.size()) return a.size() > b.size(); else return a < b; });
        for (auto str:d) {
            if (subword(s, str)) return str;
        }
        return ret;
    }

private:
    bool subword(string &a, string &b) {
        int a_pos = 0, b_pos = 0;
        while (a_pos < a.size() && b_pos <= b.size()) {
            if (a[a_pos] == b[b_pos]) {
                a_pos++;
                b_pos++;
            } else {
                a_pos++;
            }
        }
        return (b_pos == b.size()) ? true : false;
    }
};

int main() {
    string a[] = {"ba", "ab", "a", "b"};
    vector<string> input(a, a + 4);
    Solution s = Solution();
    cout << s.findLongestWord("bab", input);
}
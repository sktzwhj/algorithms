//
// Created by wu061 on 5/07/18.
//

#include <string>
#include <iostream>
#include <vector>

using namespace std;


//first implementation got TLE
class Solution {
public:
    int uniqueLetterString(string S) {
        int start = 0, str_size = S.size();
        int res = 0;
        for (int i = 0; i < str_size; i++) {
            vector<int> unique_char(26, 0);
            int unique_cnt = 0;
            for (int j = i; j < str_size; j++) {
                unique_char[S[j] - 'A']++;
                if (unique_char[S[j] - 'A'] == 1) unique_cnt++;
                if (unique_char[S[j] - 'A'] == 2) unique_cnt--;
                res += unique_cnt;
            }
        }
        return res;
    }
};


//this one got AC. 8ms. seems to be fast.
class Solution {
public:
    int uniqueLetterString(string S) {
        /*
         * rather than looking at substring level, we look at each character and see which substrings it might exist.
         * so if we have patterns like AxxxxxAxxxxxA, then for the substrings with the second A as a unique one, its
         * left boundary is within the first and the second A while its right boundary must be within the second A and
         * the third A. just a small trick that we add two stubs occurrence for each character. the first occurrence at
         * index -1 while the last one at str_size.
         */
        int start = 0, str_size = S.size(), res = 0;
        vector<vector<int>> pos(26, vector<int>({-1}));
        for (int i = 0; i < str_size; i++) pos[S[i] - 'A'].push_back(i);
        for (int i = 0; i < 26; i++) pos[i].push_back(str_size);
        for (int j = 0; j < 26; j++)
            for (int k = 1; k < pos[j].size() - 1; k++)
                res += (pos[j][k] - pos[j][k - 1]) * (pos[j][k + 1] - pos[j][k]);
        return res;
    }
};

int main() {
    string input = "ABC";
    Solution s = Solution();
    cout << s.uniqueLetterString(input) << endl;
}
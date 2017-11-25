//
// Created by wu061 on 25/11/17.
//

#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

/*
 * although the problem is so easy in python s[::-1], it may really want to test two pointer solution like the following.
 */

class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.size() - 1;
        while(i < s.size()/2){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};


int main()
{
    string a = "hello";
    Solution s = Solution();
    cout<<s.reverseString(a)<<endl;
}
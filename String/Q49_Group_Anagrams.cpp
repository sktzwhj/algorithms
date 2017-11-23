//
// Created by wuhuijun on 9/24/17.
//

#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>"
using namespace std;

class Solution {
public:
    string getSortedChars(string str)
    {
        char* tmp = new char[str.length()+1];
        memcpy(tmp, str.c_str(),str.length()+1);
        sort(tmp,tmp+str.length());
        return tmp;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> hmap;
        vector<vector<string>> ret;
        vector<string>::iterator it;
        for(it = strs.begin(); it!=strs.end(); it++){
            string current = string(getSortedChars(*it));
            if(hmap.find(current)!=hmap.end())
            {
                int pos = hmap[current];
                ret[pos].push_back(*it);
            }
            else
            {
                vector<string> tmp;
                tmp.push_back(*it);
                ret.push_back(tmp);
                int pos = ret.size() - 1;
                hmap[current] = pos;
            }

        }
        return ret;
    }
};

int main()
{
    Solution s = Solution();
    cout<<s.getSortedChars(string("ancfs"));
}

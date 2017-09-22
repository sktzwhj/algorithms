//
// Created by wu061 on 22/09/17.
//

#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool compare(int a, int b){
        ostringstream s_a,s_b;
        s_a<<a;
        s_b<<b;
        string a_convert(s_a.str());
        string b_convert(s_b.str());

        if((a_convert + b_convert) > (b_convert + a_convert)){
            return 1;}
        else {
            return 0;
        }
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        string ret;

        bool start = 1;

        for(vector<int>::iterator it = nums.begin();it!=nums.end();++it)
        {
            if(start && *it==0){
                continue;
            }
            else {
                ostringstream s;
                s << *it;
                string tmp(s.str());
                ret += tmp;
                start = 0;
            }
        }
        if(start)
            ret = "0";


        return ret;
    }
};

int main()
{
    Solution s = Solution();
    int a[] = {0,0};
    vector<int> input(a,a+2);
    cout<<s.largestNumber(input);

}
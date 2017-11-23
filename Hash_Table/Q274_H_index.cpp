//
// Created by wuhuijun on 11/4/17.
//
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0)
            return 0;
        sort(citations.begin(),citations.end(), greater<int>());
        int start = 0, end = citations.size()-1;
        if(start==end)
            return (citations[0]>0)?1:0;
        while(start < end)
        {
            int mid = (start + end)/2;
            if(citations[mid] >= mid+1)
                start += 1;
            else
                end -= 1;
        }
        if(start==end)
        {
            if(citations[start]>=start+1)
                return start + 1;
            else
                return start;
        }
        return start;

    }
};
/*
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0)
            return 0;
        sort(citations.begin(),citations.end(), greater<int>());
        int i;
        for(i = 1; i <= citations.size();)
        {
            if(citations[i-1] >= i)
                i++;
            else
                break;
        }
        return i - 1;

    }
};
*/

int main()
{
    int a[] = {11,19};
    vector<int> input = vector<int>(a,a+2);
    Solution s = Solution();
    cout<<s.hIndex(input);

}

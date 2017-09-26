//
// Created by wu061 on 26/09/17.
//

#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    /*
     * remember the return should be a bool... made a so stupid mistake to make it an int.
     */
    static bool cmp(pair<int,int> a, pair<int,int> b)
    {
        return a.second < b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> working_nums;
        vector<int>::iterator it;
        int tmp_pos,tmp;

        for(int j = 0; j < nums.size(); j++)
        {
            tmp = nums[j];
            pair<int,int> tmp_pair;
            if(pos.find(tmp)!=pos.end())
            {
                tmp_pos = pos[tmp];
                freqCnt[tmp_pos].second++;
            }

            else
            {
                tmp_pos = freqCnt.size();
                tmp_pair.first = tmp;
                tmp_pair.second = 1;
                freqCnt.push_back(tmp_pair);
                pos[tmp] = tmp_pos;


            }}

        sort(freqCnt.begin(),freqCnt.end(),cmp);
        vector<int> ret;
        int freqCntSize = freqCnt.size();
        for(int i = freqCntSize - 1; i >= freqCntSize - k; i--)
            ret.push_back(freqCnt[i].first);
        return ret;
    }

private:
    unordered_map<int,int> pos;
    vector<pair<int,int>> freqCnt;

};

int main()
{

    int k = 7;
    int a[] = {5,1,-1,-8,-7,8,-5,0,1,10,8,0,-4,3,-1,-1,4,-5,4,-3,0,2,2,2,4,-2,-4,8,-7,-7,2,-8,0,-8,10,8,-8,-2,-9,4,-7,6,6,-1,4,2,8,-3,5,-9,-3,6,-8,-5,5,10,2,-5,-1,-5,1,-3,7,0,8,-2,-3,-1,-5,4,7,-9,0,2,10,4,4,-4,-1,-1,6,-8,-9,-1,9,-9,3,5,1,6,-1,-2,4,2,4,-6,4,4,5,-5};
    vector<int> input(a,a+100);
    Solution s = Solution();
    vector<int> ret = s.topKFrequent(input,k);
    for(int i=0;i<ret.size();i++)
        cout<<ret[i]<<endl;
}
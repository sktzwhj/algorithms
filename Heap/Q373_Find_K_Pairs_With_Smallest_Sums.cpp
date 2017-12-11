//
// Created by wu061 on 11/12/17.
//

#include<pair>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

//the idea of using priority queue would be similar. and it's amazing to find out that the STL implementation of priority
//queue is really efficient

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<pair<int, int>> ret = vector<pair<int, int>>();
        multimap<int, pair<int,int>> q = multimap<int, pair<int,int>>();
        if(k == 0)
            return ret;
        int it1Size = min(k,(int)nums1.size());
        int it2Size = min(k,(int)nums2.size());
        for(int i = 0; i < it1Size; i++)
            for(int j = 0; j < it2Size; j++){
                q.insert({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
            }
        int curr = 0;
        for(auto it = q.begin(); it != q.end(); it++){
            ret.push_back((*it).second);
            curr++;
            if(curr == k)
                break;
        }
        return ret;
    }
};
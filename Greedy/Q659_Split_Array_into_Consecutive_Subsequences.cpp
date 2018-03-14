//
// Created by wu061 on 14/03/18.
//

#include <vector>
#include <unordered_map>
using namespace std;

/*
 * note that the problem requires consecutive numbers.
 * for each number, there are two situations, it can either be appended at the end of an existing seq or need
 * to start a new one.
 */

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        //freq of each num
        unordered_map<int,int> freq;
        //the num of existing seq which ends with a certain num
        unordered_map<int,int> exist_seq;
        for(auto num:nums) freq[num]++;
        for(auto num:nums){
            //num already be used up
            if(freq[num] == 0) continue;
            if(exist_seq[num - 1]){
                //exist a seq to append
                exist_seq[num - 1]--;
                exist_seq[num]++;
                freq[num]--;
            }
            else if(freq[num + 1]&&freq[num + 2]){
                exist_seq[num+2]++;
                freq[num]--;
                freq[num+1]--;
                freq[num+2]--;
            }
            else
                return false;

        }
        return true;
    }
};
//
// Created by wu061 on 22/11/17.
//
#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        printVector(nums);
        vector<int> smallerResult = vector<int>(nums.size(),0);
        mergeFindSmaller(nums, 0,  smallerResult);
        printVector(nums);
        //cout<<"smallerResult"<<endl;
        printVector(smallerResult);
        return smallerResult;
    }

    void mergeFindSmaller(vector<int>& nums, int start,  vector<int>& smallerResult){
        if(nums.size() < 2)
            return;
        int mid = (nums.size() - 1)/2;
        vector<int> L = vector<int>();
        vector<int> R = vector<int>();
        for(int i = 0; i <= mid; i++)
            L.push_back(nums[i]);
        for(int j = mid + 1; j < nums.size(); j++)
            R.push_back(nums[j]);
        //printVector(L);
        //printVector(R);
        mergeFindSmaller(L, start,smallerResult);
        mergeFindSmaller(R, mid+1, smallerResult);
        merge(L,R,nums, start, mid, smallerResult);
    }

private:
    void merge(vector<int> L, vector<int> R, vector<int>& nums, int start, int mid,  vector<int>& smallerResult) {
        int i = 0, j = 0, index = 0;
        while (i <  L.size() && j < R.size() ) {
            if (L[i] < R[j]) {
                nums[index++] = L[i++];
            }
            else if(R[j] < L[i]) {
                nums[index++] = R[j++];
                for(int k = i; k < L.size() ; k++)
                    smallerResult[start + k]++;
            }
            else {
                //if the two are equal
                nums[index++] = L[i++];
                nums[index++] = R[j++];
            }

        }

        while (i < L.size())
            nums[index++] = L[i++];

        while (j < R.size())
            nums[index++] = R[j++];
    }

    void printVector(vector<int> nums)
    {
        cout<<"the vector is:"<<endl;
        for(auto e:nums)
            cout<<e<<endl;
    }

};

int main(){
    int a[] = {5,2,6,1};
    vector<int> input = vector<int>(a,a+4);
    Solution s = Solution();
    s.countSmaller(input);
}

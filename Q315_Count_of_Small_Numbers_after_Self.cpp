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
        vector<int> indices = vector<int>(nums.size(),0);
        for(int k = 0; k < nums.size(); k++)
            indices[k] = k;
        mergeFindSmaller(nums, 0, nums.size() -1,indices, smallerResult);
        printVector(nums);
        //cout<<"smallerResult"<<endl;
        printVector(smallerResult);
        cout<<"indices:"<<endl;
        printVector(indices);
        return smallerResult;
    }

    void mergeFindSmaller(vector<int>& nums, int start, int end, vector<int>&indices, vector<int>& smallerResult){
        cout<<"start:"<<start<<"num len:"<<nums.size()<<endl;

        if(nums.size() < 2)
            return;
        int mid = (start + end )/2;
        vector<int> L = vector<int>();
        vector<int> R = vector<int>();
        for(int i = start; i <= mid; i++)
            L.push_back(nums[i - start]);
        for(int j = mid + 1; j <= end; j++)
            R.push_back(nums[j - start]);
        //printVector(L);
        //printVector(R);
        mergeFindSmaller(L, start, mid, indices,smallerResult);
        mergeFindSmaller(R, mid+1, end, indices, smallerResult);
        merge(L,R,nums, start, end, indices, smallerResult);
    }

private:
    void merge(vector<int> L, vector<int> R, vector<int>& nums, int start, int end, vector<int>& indices, vector<int>& smallerResult) {
        int mid = (start+end)/2;

        int i = start, j = mid + 1, index = 0;



        cout<<"start "<<start<<"end "<<end<<endl;
        while (i <= mid && j <= end ) {
            if (L[i - start] < R[j - mid -1]) {
                indices[start + index] = i;
                nums[index++] = L[i - start];

                i++;
            }
            else if(R[j - mid - 1] < L[i - start]) {
                indices[start + index] = j;
                nums[index++] = R[j - mid - 1];
                cout<<"nums["<<j<<"]< nums["<<i<<"]"<<endl;
                for(int k = i; k <= mid ; k++){
                    smallerResult[indices[k]]++;
                }
                j++;



            }
            else {
                //if the two are equal
                indices[start + index] = i;
                nums[index++] = L[i - start];
                indices[start + index] = j;
                nums[index++] = R[j - mid - 1];
                i++;
                j++;
            }

        }

        while (i <= mid){
            indices[start + index] = i;
            nums[index++] = L[i - start];
            i++;
        }

        while (j <= end){
            indices[start + index] = j;
            nums[index++] = R[j - mid - 1];
            j++;
        }

    }

    void printVector(vector<int> nums)
    {
        cout<<"the vector is:"<<endl;
        for(auto e:nums)
            cout<<e<<endl;
    }

};

int main(){
    int a[] = {2,0,1};
    vector<int> input = vector<int>(a,a+3);
    Solution s = Solution();
    s.countSmaller(input);
}

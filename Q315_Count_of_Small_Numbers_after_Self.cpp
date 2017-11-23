//
// Created by wu061 on 22/11/17.
//
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class NumberIndex {
public:
    int index;
    int value;
    NumberIndex(int num, int ind) {
        value = num;
        index = ind;
    }

    NumberIndex() {

    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        //printVector(nums);
        vector<int> smallerResult = vector<int>(nums.size(), 0);
        if(nums.size() < 2){
            printVector(smallerResult);
            return smallerResult;
        }
        vector<NumberIndex> num_values = vector<NumberIndex>();
        for (int k = 0; k < nums.size(); k++) {

            //have made a stupid mistake here...if you have already initilize the vector with certain size. pushback will
            //resize and make it longer than what you think.
            NumberIndex tmp(nums[k],k);
            num_values.push_back(tmp);

        }
        cout<<"1num_values length"<<num_values.size()<<endl;

        mergeFindSmaller(num_values, smallerResult);
        //printVector(nums);
        printVector(smallerResult);
        return smallerResult;
    }

    void mergeFindSmaller(vector<NumberIndex> &nums, vector<int> &smallerResult) {
        //cout << "start:" << start << "num len:" << nums.size() << endl;
        cout<<"1nums length"<<nums.size()<<endl;

        if (nums.size() < 2)
            return;
        int mid = (0 + nums.size() - 1)/2;
        vector<NumberIndex> L = vector<NumberIndex>();
        vector<NumberIndex> R = vector<NumberIndex>();
        cout<<"nums length"<<nums.size()<<endl;
        for (int i = 0; i <= mid; i++)
            L.push_back(nums[i]);
        for (int j = mid + 1; j < nums.size(); j++)
            R.push_back(nums[j]);

        cout<<"L.size"<<L.size()<<"R.size"<<R.size()<<endl;


        mergeFindSmaller(L, smallerResult);
        mergeFindSmaller(R,smallerResult);
        merge(L, R, nums,  smallerResult);
    }

private:
    void merge(const vector<NumberIndex> L, const vector<NumberIndex> R, vector<NumberIndex> &nums,  vector<int> &smallerResult) {
        int i = 0, j = 0;
        while (i < L.size() && j < R.size()) {
            if (L[i].value < R[j].value) {
                nums[i + j] = L[i];
                smallerResult[L[i++].index] += j;
                cout<<L[i].value <<"<"<<R[j].value<<endl;
            } else if(L[i].value > R[j].value){
                nums[i + j] = R[j++];
            }
            else{
                nums[i+j] = L[i];
                smallerResult[L[i++].index] += j;
                nums[i+j] = R[j++];
            }
        }
        if(i < L.size()){
            nums[i+j] = L[i];
            smallerResult[L[i++].index] += j;
            cout<<"i="<<i<<"j="<<j<<endl;
            cout<<"L.size"<<L.size()<<"R.size"<<R.size()<<endl;

        }
        if(j < R.size())
        {
            nums[i+j] = R[j++];
        }

    }
    void printVector(vector<int> nums) {
        cout << "the vector is:" << endl;
        for (auto e:nums)
            cout << e << endl;
    }

};

int main() {
    int a[] = {-1, -1};
    vector<int> input = vector<int>(a, a + 2);
    Solution s = Solution();
    s.countSmaller(input);
}

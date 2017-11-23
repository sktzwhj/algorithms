//
// Created by wu061 on 9/10/17.
//
#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

//another typical dynamic programming problem.

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        unordered_map<int, unordered_map<int, int>> dpTable;
        if (triangle.size() == 0)
            return 0;
        if (triangle.size() == 1)
            return triangle[0][0];
        distance(0, triangle, 0, dpTable);

        return dpTable[0][0];
    }

private:
    void distance(int currentLayer, vector<vector<int>> &triangle, int idx,
                  unordered_map<int, unordered_map<int, int>> &dpTable) {

        if (currentLayer == triangle.size() - 1) {
            dpTable[currentLayer][idx] = triangle[currentLayer][idx];

        } else {
            if (dpTable[currentLayer + 1].find(idx) == dpTable[currentLayer + 1].end())
                distance(currentLayer + 1, triangle, idx, dpTable);
            if (dpTable[currentLayer + 1].find(idx + 1) == dpTable[currentLayer + 1].end())
                distance(currentLayer + 1, triangle, idx + 1, dpTable);
            dpTable[currentLayer][idx] = min(dpTable[currentLayer + 1][idx], dpTable[currentLayer + 1][idx + 1]) +
                                         triangle[currentLayer][idx];

        }
    }
};

int main() {
    Solution s = Solution();
    int l1[] = {2};
    int l2[] = {3, 4};
    int l3[] = {6, 5, 7};
    int l4[] = {4, 1, 8, 3};
    vector<int> L1(l1, l1 + 1);
    vector<int> L2(l2, l2 + 2);
    vector<int> L3(l3, l3 + 3);
    vector<int> L4(l4, l4 + 4);

    vector<vector<int>> input;
    input.push_back(L1);
    input.push_back(L2);
    input.push_back(L3);
    input.push_back(L4);


    cout << s.minimumTotal(input);
}

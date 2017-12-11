//
// Created by wu061 on 11/12/17.
//

#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;

//initial solution, works but there exists some redundant search
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        //since there might be duplicate elements, we should use the index of nums rather the num values in parent map
        //we use a set to store the nums
        unordered_map<int, int> numIndex = unordered_map<int, int>();

        for (int i = 0; i < nums.size(); i++)
            numIndex[nums[i]] = i;

        for (auto e : numIndex)
            parent[e.second] = e.second;


        for (auto pair : numIndex) {
            if (numIndex.find(pair.first - 1) != numIndex.end())
                unionSet(find(numIndex[pair.first - 1]), find(pair.second));
            if (numIndex.find(pair.first + 1) != numIndex.end())
                unionSet(find(numIndex[pair.first + 1]), find(pair.second));
        }

        unordered_map<int, int> lcsCount = unordered_map<int, int>();
        int maxLen = 0;
        for (auto pair:parent) {
            if (lcsCount.find(find(pair.second)) != lcsCount.end()) lcsCount[find(pair.second)]++;
            else lcsCount[find(pair.second)] = 1;
            if (lcsCount[find(pair.second)] > maxLen)
                maxLen = lcsCount[find(pair.second)];
        }
        return maxLen;
    }


private:
    //implement a simple union-find set here
    unordered_map<int, int> parent = unordered_map<int, int>();

    void unionSet(int x, int y) {
        if (find(x) != find(y)) {
            int yParent = find(y);
            parent[x] = yParent;
        }
    }

    int find(int x) {
        return (x == parent[x]) ? x : find(parent[x]);
    }
};

//a better solution

class Solution1 {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, bool> hash;
        for (auto val: nums) hash[val] = true;
        int Max = 0;

        /*
         * for each num, we look forward and backward to find all consecutive numbers and remove them from the hash table.
         * in this case, each sequence would be only counted once.
         */
        for (auto val: nums) {
            int len = 1, tem = val + 1;
            while (hash.count(tem)) {
                hash.erase(tem);
                len++, tem++;
            }
            tem = val - 1;
            while (hash.count(tem)) {
                hash.erase(tem);
                len++, tem--;
            }
            Max = max(len, Max);
        }
        return Max;
    }
};


int main() {
    int a[] = {2, -7, -6, 0, 4, 2, -7, 2, 2, 4, 2, -9, 2, -4, 7, 7, -8, 6, 7, -2, -6, 9, 3, 3, 5};
    vector<int> input = vector<int>(a, a + 25);
    Solution s = Solution();
    cout << s.longestConsecutive(input);

}
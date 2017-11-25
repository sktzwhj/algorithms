//
// Created by wu061 on 25/11/17.
//

#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>

using namespace std;

/*
 * do not use vector<bool> in most cases since it is not a container in implementation.
 */

class Solution {
public:
    int maxProduct(vector <string> &words) {
        unordered_map<int, int> existWord = unordered_map<int, int>();
        for (int k = 0; k < words.size(); k++) {
            int charMap = 0;
            for (int s = 0; s < words[k].size(); s++) charMap |= (1 << (words[k][s] - 'a'));
            if (existWord.find(charMap) == existWord.end() || existWord[charMap] < words[k].size())
                existWord[charMap] = words[k].size();
            //free(charMap);
        }
        int maxProduct = 0;
        for (auto kv:existWord) {
            for (auto kv1:existWord) {

                if (!(kv.first & kv1.first)) {
                    //cout<<kv.second*kv1.second<<endl;
                    if (kv.second * kv1.second > maxProduct)
                        maxProduct = kv.second * kv1.second;
                }
            }
        }
        return maxProduct;

    }

};

int main() {
    string a[] = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    vector <string> input = vector<string>(a, a + 6);
    Solution s = Solution();
    cout << s.maxProduct(input) << endl;
}
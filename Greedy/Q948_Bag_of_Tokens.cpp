//
// Created by wu061 on 18/12/18.
//

#include "headers.h"

class Solution {
public:
    int bagOfTokensScore(vector<int> &tokens, int P) {
        /*
         * Looks like we should use greedy alg to solve this.
         * power -> point
         * point -> power
         * therefore, we use the least power to get the most points.
         * the strategy is when you have power, use the least to get one point. use the point to get the most power and exchange.
         */
        sort(tokens.begin(), tokens.end());
        if (tokens.size() == 0 || P < tokens[0]) return 0;
        int point = 0;
        int left = 0, right = tokens.size() - 1;
        while (left <= right) {
            if (P < tokens[left] && point) {
                P += tokens[right--];
                point--;
            }
            if (P < tokens[left]) return point;
            //as long as you can get points with cheap price just do it. The points can be used to help you move forward when you cannot.
            P -= tokens[left++];
            point++;
        }
        return point;
    }
};

int main() {
    Solution s = Solution();
    vector<int> input = {48, 87, 26};
    cout << s.bagOfTokensScore(input, 81) << endl;
}
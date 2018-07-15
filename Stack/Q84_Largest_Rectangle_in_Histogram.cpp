//
// Created by wu061 on 15/07/18.
//

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        /*
         * the brute-force solution is easy but requires O(N^2) complexity. the algorithm of using a stack to track
         * the height and the positions is cool. I referred to this link https://www.youtube.com/watch?v=VNbkzsnllsU
         */
        int area = 0;
        stack<int> height, position;
        for (int i = 0; i < heights.size(); i++) {
            int back_pos;
            if (height.empty() || heights[i] > height.top()) {
                height.push(heights[i]);
                position.push(i);
            } else if (heights[i] < height.top()) {
                while (!height.empty() && heights[i] < height.top()) {
                    //the previous top cannot continue
                    int h = height.top();
                    int start_pos = position.top();
                    back_pos = start_pos;
                    height.pop();
                    position.pop();
                    int width = i - start_pos;
                    area = max(area, width * h);
                }
                //this part is important, the new one does not start at i but at the position where previous val starts with
                height.push(heights[i]);
                position.push(back_pos);
            }
        }
        int last_pos = heights.size();
        while (!height.empty()) {
            int h = height.top(), pos = position.top();
            height.pop();
            position.pop();
            int curr_area = h * (last_pos - pos);
            area = max(area, curr_area);
        }
        return area;
    }
};

int main() {

    vector<int> input = {2, 1, 2};
    Solution s = Solution();
    cout << s.largestRectangleArea(input);
}
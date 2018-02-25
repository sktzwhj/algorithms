//
// Created by wuhuijun on 1/24/18.
//
#include<vector>
#include<stack>
#include<cmath>
#include<iostream>

using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        stack<int> buffer;
        bool collision = true;
        while (collision) {
            collision = false;
            int i = 0;
            while (i < asteroids.size()) {
                if (buffer.empty())
                    buffer.push(asteroids[i++]);
                else {
                    int top = buffer.top();
                    if (top > 0 && asteroids[i] < 0) {
                        //collision will happen
                        if (abs(top) == abs(asteroids[i]))
                            buffer.pop();
                        else {
                            int newTop = (abs(top) > abs(asteroids[i])) ? top : asteroids[i];
                            buffer.pop();
                            buffer.push(newTop);
                            collision = true;
                        }
                        i++;
                    } else
                        buffer.push(asteroids[i++]);
                }
            }
            asteroids.clear();
            while (!buffer.empty()) {
                asteroids.insert(asteroids.begin(), buffer.top());
                buffer.pop();
            }
        }
        return asteroids;
    }
};

int main() {
    int a[] = {10, 2, -5};
    vector<int> input = vector<int>(a, a + 3);
    Solution s = Solution();
    vector<int> ret = s.asteroidCollision(input);
    for (auto e:ret)
        cout << e << endl;
}

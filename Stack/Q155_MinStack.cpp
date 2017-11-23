//
// Created by wu061 on 22/09/17.
//

#include<stack>
#include<limits>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MinStack {
private:
    vector<int> sortedStackValues;
    stack<int> base_stack;

public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        base_stack.push(x);
        if (sortedStackValues.size() == 0)
            sortedStackValues.push_back(x);
        else
            for (vector<int>::iterator it = sortedStackValues.begin(); it != sortedStackValues.end();) {
                if (*it < x)
                    ++it;
                else {
                    sortedStackValues.insert(it, x);
                    break;
                }
            }
    }

    void pop() {
        int top = base_stack.top();
        base_stack.pop();
        for (vector<int>::iterator it = sortedStackValues.begin(); it != sortedStackValues.end();) {
            if (*it == top) {
                sortedStackValues.erase(it);
                break;
            } else
                ++it;
        }

    }

    int top() {
        return base_stack.top();
    }

    int getMin() {
        return *sortedStackValues.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


int main() {
    MinStack s = MinStack();
    s.push(0);
    s.push(1);
    s.push(0);
    cout << s.getMin();
    s.pop();
    s.pop();
    cout << s.getMin();
}
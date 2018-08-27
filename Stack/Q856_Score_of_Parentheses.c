//
// Created by wu061 on 27/08/18.
//

#include <stdio.h>

#define MAX_SIZE 100

struct stack {
    int stk[MAX_SIZE];
    int top;
};

typedef struct stack Stack;
Stack s;

void initilize() {
    s.top = -1;
}

void push(int val) {
    s.stk[++s.top] = val;
}

void pop() {
    s.top--;
}

int top() {
    return s.stk[s.top];
}

int scoreOfParentheses(char *S) {
    //we first implement a stack by C

    int total_score = 0;
    for (int i = 0; i < sizeof(S); i++) {
        if (S[i] == '(') push(0);
        else {
            int cur_sum = top();
            pop();
            int val = 0;
            if (cur_sum == 0) val = 1;
            else val = 2 * cur_sum;
            s.stk[s.top] += val;
        }
    }
    return top();
}

int main() {
    char *str = "(())";
    printf("final score = %d", scoreOfParentheses(str));
}
//
// Created by wuhuijun on 10/23/17.
//
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum = (H - F)*(G - E) + (D - B)*(C - A);
        if(E > C || F > D || G < A || H < B)
            return sum;
        else
            return sum - (min(C,G) - max(A,E))*(min(H,D) - max(B,F));

    }
};

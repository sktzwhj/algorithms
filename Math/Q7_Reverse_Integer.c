//
// Created by wu061 on 20/09/17.
//
#define INT_MAX 2147483647
#include<stdbool.h>
int reverse(int x){
    int reversed_integer = 0;
    bool sign = (x>0)?1:0;
    int positive_integer = sign?x:-x;
    bool overflow = 0;
    while(positive_integer>0){
        if(reversed_integer>INT_MAX/10 || reversed_integer <-(INT_MAX+1)/10)
            return 0;

        reversed_integer = reversed_integer*10 + positive_integer%10;

        positive_integer /= 10;
    }

    return sign?reversed_integer:-reversed_integer;

}

int main()
{
    printf("%d",reverse(1534236469));
}
//
// Created by wu061 on 20/09/17.
//Determine whether an integer is a palindrome. Do this without extra space.
//
#include<math.h>
#include<stdbool.h>
#include<stdio.h>
/*
 * the point of this problem is to notice that reverse an integer may cause overflow.
 */
bool isPalindrome(int x) {
    if(x<0 || (x>0&&x%10==0))
        return 0;
    int reverted_num = 0;
    while(x > reverted_num){
        reverted_num = 10*reverted_num + x%10;
        x /= 10;
    }
    return x==reverted_num || x== reverted_num/10;

}


int main(){


    bool ret = isPalindrome(12321);
    printf("palindrome: %d",ret);

}
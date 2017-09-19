//
// Created by wuhuijun on 9/19/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *convert(char *s, int nRows)
{
    if ((NULL == s) | (nRows < 1))
    {
        return NULL;
    }
    // + 1 for NIL or '\0' in the end of a string
    const size_t len = strlen(s);
    char* output = (char*) malloc(sizeof(char) * ( len + 1));
    char* head = output;
    output[len] = '\0';
    if ( 1 == nRows )
    {
        return strcpy(output, s);
    }
    for (int row = 0; row < nRows; ++row)
    {
        //processing row by row using (2nRows-2) rule
        for (unsigned int index = row; index < len; index += 2*nRows-2)
        {
            // if it is the first row or the last row, then this is all
            *output++ = s[index];
            // otherwise, there are middle values, using (2nRows-2-2*row) rule
            // notice that nRows-1 is the last row
            if ( (row>0)&(row<nRows-1) & ((index+2*nRows - 2 - 2*row) < len))
            {
                *output++ = s[index+2*nRows - 2 - 2*row];
            }
        }
    }
    return head;
}

int main()
{
    char *s = "sadfasdfsadfsaf";
    char* output = convert(s, 3);
    printf("%s",output);
}
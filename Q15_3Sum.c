//
// Created by wuhuijun on 9/20/17.
//

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdlib.h>

int** threeSum(int* nums, int numsSize, int* returnSize) {
    int cmp(const void *a, const void *b){
        return *(int*)a - *(int*)b;
    }
    int **ret = malloc(sizeof(int*)*(*returnSize));
    if(numsSize < 2)
        return ret;
    int index = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i = 0; i < numsSize - 2; i++){
        int a = nums[i];
        int j = i + 1;
        int k = numsSize - 1;
        while(k > j){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0){
                int* tmp_indices = malloc(sizeof(int)*3);
                tmp_indices[0] = i;
                tmp_indices[1] = j;
                tmp_indices[2] = k;
                if(index < returnSize) {
                    ret[index] = tmp_indices;
                    index++;
                    ++j;
                    --k;
                }
                else
                    return ret;
            }
            else if(sum < 0)
                ++j;
            else
                ++k;
        }
        while(i<numsSize-1 && nums[i] == nums[i+1])
            ++i;
    }
    return ret;
}


int main(int argc, char *argv[])
{
    int *s = {-1,0,1,2,-1,-4};
    int** result = threeSum(s, 6, 2);
    printf("%d,%d,%d",result[0][0], result[0][1], result[0][2]);
    return 0;
}

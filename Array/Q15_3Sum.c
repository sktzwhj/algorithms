#include<stdlib.h>
//the returnSize needs to be filled. it is not a parameter given by the caller
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int cmp(const void *a, const void *b){
        return *(int*)a - *(int*)b;
    }

    int ret_mem_size = sizeof(int*)*10*numsSize;
    int **ret = (int**)malloc(ret_mem_size);
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
                tmp_indices[0] = nums[i];
                tmp_indices[1] = nums[j];
                tmp_indices[2] = nums[k];

                if(index >= ret_mem_size) {
                    ret_mem_size *= 2;
                    ret = realloc(ret, ret_mem_size);
                }
                ret[index] = tmp_indices;
                index++;
                ++j;
                --k;

            }
            else if(sum < 0)
                ++j;
            else
                ++k;
        }
        while(i<numsSize-1 && nums[i] == nums[i+1])
            ++i;
    }
    *returnSize = index;
    ret = realloc(ret,index*sizeof(int*));
    return ret;
}


int main(int argc, char *argv[])
{
    int s[6] = {-1,0,1,2,-1,-4};
    int ret_size;
    int** result = threeSum(s, 6, &ret_size);
    for(int q=0;q<ret_size;q++)
        printf("[%d,%d,%d]",result[q][0], result[q][1], result[q][2]);
    printf("%d",ret_size);
    return 0;
}

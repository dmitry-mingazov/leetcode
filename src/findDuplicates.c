/*
* https://leetcode.com/problems/find-all-duplicates-in-an-array
*/
#include <stdlib.h>
#include <stdio.h>

int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int* tmp = (int*)malloc(sizeof(int)*100000);
    int* res = (int*)malloc(sizeof(int)*50000);
    int size = 0;
    for(int i=0; i<10000; i++) {
        tmp[i] = 0;
    }
    for (int i=0; i<numsSize; i++) {
        tmp[nums[i]]++;
        if(tmp[nums[i]] > 1) {
            res[size++] = nums[i];
        }
    }
    *returnSize = size;
    return res;
}

int main(void) {
    int nums[6] = {1,2,2,6,100,100};
    int returnSize = 0;
    int* dup = findDuplicates(nums, 6, &returnSize);
    printf("Solution: [");
    for(int i=0; i<returnSize; i++) {
        printf(i != returnSize-1 ? "%d, " : "%d]\n",dup[i]);
    }
}
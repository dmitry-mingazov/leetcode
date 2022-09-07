/*
* https://leetcode.com/problems/3sum/
*/
#include <stdio.h>
#include <stdlib.h>
void mergeSort(int* nums, int numsSize);
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int _nsquare = numsSize * numsSize;
    int maxSize = _nsquare*numsSize - 3*_nsquare + 2*numsSize;
    int** result = malloc(sizeof(int*) * maxSize);
    *returnColumnSizes = malloc(sizeof(int*) * maxSize);
    mergeSort(nums, numsSize);
    *returnSize = 0;
    for(int i=0; i<numsSize-2; i++) {
        if (i > 0) {
            if (nums[i] == nums[i-1])
                continue;
        }
        int curr = nums[i];
        int* left = nums+i+1;
        int* right = nums+numsSize-1;
        while(left<right) {
            int sum = curr + *left + *right;
            if(sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                result[*returnSize] = malloc(sizeof(int)*3);
                (*returnColumnSizes)[*returnSize] = 3;
                result[*returnSize][0] = curr;
                result[*returnSize][1] = *left;
                result[*returnSize][2] = *right;
                ++*returnSize;
                int tmp = *right;
                while(tmp == *--right && left<right);
            }
        }
    }
    return result;
}

void mergeSort(int* nums, int numsSize) {
    if (numsSize < 2) 
        return;
    int k = numsSize/2;
    mergeSort(nums, k);
    mergeSort(nums+k, numsSize-k);
    int* left = malloc(sizeof(int)*(k+1));
    int* lnums = left;
    int* llimit = left+k;
    int* right = malloc(sizeof(int)*(numsSize-k+1));
    int* rnums = right;
    int* rlimit = right+numsSize-k;
    for(int i = 0; i<k; i++) {
        left[i] = nums[i];
    }
    for(int i = 0; i<numsSize-k; i++) {
        right[i] = nums[i+k];
    }
    for(int i=0; i<numsSize; i++) {
        int** min; 
        if (left == llimit) {
            min = &right;
        } else if (right == rlimit) {
            min = &left;
        } else {
            min = *left < *right ? &left : &right;
        }
        nums[i] = **min;
        ++*min;
    }
    free(lnums);
    free(rnums);
}

// --------------------------------------------

// old implementation (too slow)
// int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
//     int** result = malloc(sizeof(int*)); // something wrong
//     if (result == NULL) {
//         exit(1);
//     }
//     *returnSize = 0;
//     for(int i=0; i < numsSize; i++) {
//         for(int j=i+1; j < numsSize; j++) {
//             for(int k=0; k < numsSize; k++) {
//                 if (k==i || k==j) {
//                     continue;
//                 }
//                 if (nums[i]+nums[j]+nums[k]==0) {
//                     int* arr = malloc(sizeof(int)*3);
//                     arr[0] = nums[i];
//                     arr[1] = nums[j];
//                     arr[2] = nums[k];
//                     for(int l=0; l<3; l++) {
//                         for(int m=0; m<3-l-1; m++) {
//                             if (arr[m+1] < arr[m]) {
//                                 arr[m] = arr[m] ^ arr[m+1];
//                                 arr[m+1] = arr[m+1] ^ arr[m];
//                                 arr[m] = arr[m] ^ arr[m+1];
//                             }
//                         }
//                     }
//                     char isFound = 0;
//                     for(int c=0; c<(*returnSize); c++) {
//                         if(result[c][0] == arr[0] && result[c][1] == arr[1] && result[c][2] == arr[2]) {
//                             isFound = 1;
//                             break;
//                         }
//                     }
//                     if(isFound == 0) {
//                         (*returnSize)++;
//                         result = realloc(result, sizeof(int*)*(*returnSize));
//                         result[*returnSize-1] = arr;
//                     } else {
//                         free(arr);
//                     }
//                 }
//             }
//         }
//     }
//     *returnColumnSizes = malloc(sizeof(int)*(*returnSize));
//     for(int i=0; i<(*returnSize); i++) {
//         (*returnColumnSizes)[i] = 3;
//     }
//     return result;
// }

// --------------------------------------------------

void printArray(int* nums, int numsSize) {
    printf("[");
    for(int i=0; i < numsSize; i++) {
        if (i==numsSize-1) {
            printf("%d]", nums[i]);
        } else {
            printf("%d, ", nums[i]);
        }
    }
    printf("\n");
}

int main(void) {
    int array[27] = {-7,-4,-6,6,4,-6,-9,-10,-7,5,3,-1,-5,8,-1,-2,-8,-1,5,-3,-5,4,2,-5,-4,4,7};
    int numSize = 27;
    int returnSize;
    int* returnColumnSizes;
    int** result = threeSum(array, numSize, &returnSize, &returnColumnSizes);
    printf("Result:\n[");

    for(int i=0; i<returnSize; i++) {
        printf("[");
        for(int j=0; j<returnColumnSizes[i]; j++) {
            printf("%d,", result[i][j]);
        }
        free(result[i]);
        printf("],");
    }
    free(result);
    free(returnColumnSizes);
    printf("]\n");
}
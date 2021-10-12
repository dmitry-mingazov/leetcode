#include <stdio.h>
#include <stdlib.h>
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
int number;

int guess(int num) {
    if (num < number) {
        return 1;
    } else if (num > number) {
        return -1;
    } else {
        return 0;
    }
}

int fn(int *start, int *end) {
    int pick = (int)((*end-*start)/2+*start);
    if(pick == *start) {
        pick++;
    }
    // printf("start: %d - end: %d - pick: %d\n", *start, *end, pick);
    int info = guess(pick);
    if (info > 0) {
        *start = pick;
        return -1;
    } else if (info < 0) {
        *end = pick;
        return -1;
    } else {
        return pick;
    }
}

int guessNumber(int n){
    int start = 0;
    int end = n;
    int pick = -1;
    while(pick == -1) {
        pick = fn(&start, &end);

    }
    return pick;
}

int main(void) {
    number = 2231;
    int n = 10000;
    printf("Solution: %d\n",guessNumber(n));
}
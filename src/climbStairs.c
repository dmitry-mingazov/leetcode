/*
* https://leetcode.com/problems/climbing-stairs
*/
#include <stdio.h>

int climbStairs(int n) {
    if (n <= 3) {
        return n;
    } else {
        return climbStairs(n-3) + climbStairs(n-2)*2;
    }
}


int main(void) {
    printf("Solution: %d\n", climbStairs(5));
}
/*
* https://leetcode.com/problems/powx-n/
*/
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if(n==0)
        return 1;
    let isPositive = n > 0;
    n = Math.abs(n);
    let result = 1;
    let currPow = x;
    let currExp = 1;
    for(; n > 0; n=parseInt(n/2)) {
        if (n%2) {
            result *= currPow;
        }
        currPow *= currPow;
        currExp *= 2;
    }
    return isPositive ? result : 1/result;
};

console.log(myPow(2, 9));

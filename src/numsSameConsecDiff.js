/*
* https://leetcode.com/problems/numbers-with-same-consecutive-differences/
*/
/**
 * @param {number} n
 * @param {number} k
 * @return {number[]}
 */
var numsSameConsecDiff = function(n, k) {
    let result = [];
    for(let i=1; i < 10; i++) {
        if(i+k>9 && i<k)
            continue;
        result.push(...fn(n-1, k, i));
    }
    return result;
};

function fn(n, k, num) {
    if (n == 0) {
        return [num];
    }
    let solutions = [];
    let last = num%10;
    let left = last - k; 
    let right = last + k;
    if (left == right) {
        solutions.push(...fn(n-1, k, num*10+left));
        return solutions;
    }
    if(left >= 0) {
        solutions.push(...fn(n-1, k, num*10+left));
    }
    if(right < 10) {
        solutions.push(...fn(n-1, k, num*10+right));
    }
    return solutions;
}

// console.log(numsSameConsecDiff(2,2));
// console.log(numsSameConsecDiff(2,0));
console.log(numsSameConsecDiff(3,4));
// console.log(numsSameConsecDiff(4,7));
// console.log(numsSameConsecDiff(4,3));

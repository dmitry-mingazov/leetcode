/*
* https://leetcode.com/problems/n-queens-ii/
*/
/**
 * @param {number} n
 * @return {string[][]}
 */
var totalNQueens = function(n) {
    var board = Array.from({length: n}, () => Array.from('.'.repeat(n)));
    var solutions = [];
    let columns = Array.from({length: n}, (v, k) => k);
    solutions = fn(board, n, 0, columns);
    return solutions;
    console.log(solutions);
    // return solutions.map(mat => mat.map(arr => arr.join("")));
};

function fn(board, n, currRow, columns) {
    // console.log(`fn(${n},${currRow})`);
    if(currRow == n) {
        return 1;
    }
    let solutions = 0
    let clmns = [...columns];
    for(let i = 0; i<clmns.length; i++) {
        let currCol = clmns[i];
        clmns.splice(i, 1);
        if(isValid(board, n, currRow, currCol) == true) {
            board[currRow][currCol] = 'Q';
            let solution = fn(board, n, currRow+1, clmns)
            solutions += solution;
            board[currRow][currCol] = '.';
        } 
        clmns.splice(i, 0, currCol);
    }
    return solutions;
}

const axises = [
    // (x,y) => [x, y+1],
    // (x,y) => [x, y-1],
    // (x,y) => [x+1, y],
    // (x,y) => [x-1, y],
    (x,y) => [x+1, y+1],
    (x,y) => [x-1, y-1],
    (x,y) => [x-1, y+1],
    (x,y) => [x+1, y-1],
]

function isValid(board, n, x, y) {
    // console.log(`isValid(${n}, ${x}, ${y})`);
    for(let i=0; i < axises.length; i++) {
        const mv = axises[i];
        let [nX, nY] = mv(x, y);
        while(nX < n && nX >= 0 && nY < n && nY >= 0) {
            if(board[nX][nY] == 'Q') {
                return false;
            } 
            [nX, nY] = mv(nX, nY);
        }
    }
    return true;
}


console.log(totalNQueens(5));
/*
* https://leetcode.com/problems/construct-string-from-binary-tree/submissions/
*/
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {string}
 */
var tree2str = function(root) {
    let solution = `${root.val}`;
    if(root.left) {
        solution = solution.concat(`(${tree2str(root.left)})`);
    }
    if(root.right) {
        let parentheses = root.left ? '(' : '()(';
        solution = solution.concat(`${parentheses}${tree2str(root.right)})`);
    }
    return solution;
};
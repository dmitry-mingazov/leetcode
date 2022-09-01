/*
* https://leetcode.com/problems/count-good-nodes-in-binary-tree/
*/ 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int goodNodes(struct TreeNode* root){
    return fn(root, root->val);
}

int fn(struct TreeNode* node, int max) {
    if (node == NULL) {
        return 0;
    }
    int result = 0;
    if (node->val >= max) {
        max = node->val;
        result = 1;
    }
    result += fn(node->right, max) + fn(node->left, max);
    return result;
}

/*
* https://leetcode.com/problems/diameter-of-binary-tree
*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfs(struct TreeNode *curr, int *maxPath) {
    int maxLeft = 0;
    int maxRight = 0;
    if (curr->left != NULL) {
        maxLeft = dfs(curr->left, maxPath)+1;
    } else {
        maxLeft = 0;
    }
    if (curr->right != NULL) {
        maxRight = dfs(curr->right, maxPath)+1;
    } else {
        maxRight = 0;
    }
    int max = maxLeft > maxRight ? maxLeft : maxRight;
    if ((maxLeft + maxRight) > *maxPath) {
        *maxPath = maxLeft + maxRight;
    }
    return max;
}

int diameterOfBinaryTree(struct TreeNode* root){
    int maxPath = 0;
    dfs(root, &maxPath);
    return maxPath;
}

struct TreeNode* createNewLeft(struct TreeNode *curr, int val) {
    curr->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    curr->left->val = val;
    curr->left->left = NULL;
    curr->left->right = NULL;
    return curr->left;
}

struct TreeNode* createNewRight(struct TreeNode *curr, int val) {
    curr->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    curr->right->val = val;
    curr->right->left = NULL;
    curr->right->right = NULL;
    return curr->right;
}

int main(void) {
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode *curr = root;
    int i = 1;
    root->val = i++;
    root->left = NULL;
    root->right = NULL;
    curr = createNewLeft(curr, i++);
    createNewRight(root, i++);
    createNewLeft(curr, i++);
    createNewRight(curr, i++);

    printf("Solution: %d\n", diameterOfBinaryTree(root));
}
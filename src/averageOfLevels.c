/*
* https://leetcode.com/problems/average-of-levels-in-binary-tree/
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode* node, double* sums, int* nums, int depth);
int depthfn(struct TreeNode* node);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize){
    int dep = depthfn(root);
    double* result = malloc(sizeof(double) * dep);
    int* nums = malloc(sizeof(int) * dep);
    *returnSize = dep;
    for(int i = 0; i<dep; i++) {
        result[i] = 0;
        nums[i] = 0;
    }
    dfs(root, result, nums, 0);
    for(int i=0; i<*returnSize; i++) {
        printf("%lf (%d) ", result[i], nums[i]);
        result[i] /= nums[i];
    }
    printf("\n");
    return result;
}

int maxfn(int a, int b) {
    return a > b ? a : b;
}

int depthfn(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + maxfn(depthfn(node->left), depthfn(node->right));
}

void dfs(struct TreeNode* node, double* sums, int* nums, int depth) {
    sums[depth] += node->val;
    nums[depth] += 1;
    if (node->left != NULL)
        dfs(node->left, sums, nums, depth+1);
    if (node->right != NULL)
        dfs(node->right, sums, nums, depth+1);
}

// ---------------------------------------------


void printBst(struct TreeNode *node) {
    if (node == NULL) {
        return;
    }
    printf("%d ",node->val);
    if (node->left != NULL) {
        printBst(node->left);
    }
    if (node->right != NULL) {
        printBst(node->right);
    }
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
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = 3;
    root->left = NULL;
    root->right = NULL;
    struct TreeNode *curr = createNewLeft(root, 4);
    createNewRight(curr, 10);
    createNewLeft(curr, 8);
    createNewRight(root, 5);
    printf("[");
    printBst(root);
    printf("]\n");
    int size;
    averageOfLevels(root, &size);
}
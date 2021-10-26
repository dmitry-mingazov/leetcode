/*
* https://leetcode.com/problems/invert-binary-tree
*/
#include <stdio.h>
#include <stdlib.h>

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

// -------------------------------------------------------

void swap(struct TreeNode* node) {
    if(node == NULL) {
        return;
    }
    struct TreeNode* tmpLeft = node->right;
    struct TreeNode* tmpRight = node->left;

    node->left = tmpLeft;
    node->right = tmpRight;

    swap(node->left);
    swap(node->right);
}

struct TreeNode* invertTree(struct TreeNode* root){
    swap(root);
    return root;
}

// -------------------------------------------------------

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

    printf("[");
    printBst(root);
    printf("]\n");
    printf("[");
    printBst(invertTree(root));
    printf("]\n");
}
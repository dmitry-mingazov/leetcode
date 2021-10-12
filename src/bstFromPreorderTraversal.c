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

struct TreeNode* createNode(int val) {
    struct TreeNode *tmp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    struct TreeNode **nodes = (struct TreeNode**)malloc(sizeof(struct TreeNode)*preorderSize);
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode *tmp;
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;
    nodes[0] = root;
    int maxIndex = 0;
    for(int i=1; i<preorderSize; i++) {
        // add to the left
        if (preorder[i] < preorder[i-1]) {
            tmp = createNode(preorder[i]);
            nodes[i] = tmp;
            nodes[i-1]->left = tmp;
            // printf("Added %d to the left of %d\n", nodes[i]->val, nodes[i-1]->val);
        // curr node is the biggest, add to the extreme right
        } else if (preorder[i] > nodes[maxIndex]->val){
            tmp = createNode(preorder[i]);
            nodes[i] = tmp;
            nodes[maxIndex]->right = tmp;
            // printf("Added %d to the right of %d\n", nodes[i]->val, nodes[maxIndex]->val);
            maxIndex = i;
        // add to the right, looking backwards
        } else {
            int maxLesserIndex = i-1;
            for(int j=i; j>0; j--) {
                if(preorder[i] > preorder[j-1]) {
                    if (preorder[j-1] > nodes[maxLesserIndex]->val) {
                        maxLesserIndex = j-1;
                    } 
                } else {
                    tmp = createNode(preorder[i]);
                    nodes[i] = tmp;
                    nodes[maxLesserIndex]->right = tmp;
                    // printf("Added %d to the right of %d\n", nodes[i]->val, nodes[j]->val);
                }
            }
        }
        if (preorder[i] > nodes[maxIndex]->val) {
            maxIndex = i;
        }
    }
    return root;
}

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

int main(void) {
    int preorder[6] = {8,5,1,7,10,12};
    int preorderSize = 6;
    printf("[");
    printBst(bstFromPreorder(preorder, preorderSize));
    printf("]\n");
}
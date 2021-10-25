/*
* https://leetcode.com/problems/min-stack
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* val;
    int size;
    int min;
} MinStack;


MinStack* minStackCreate() {
    MinStack *stack = (MinStack*)malloc(sizeof(MinStack));
    stack->val = NULL;
    stack->size = 0;
    stack->min = 0;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    obj->size++;
    if (obj->val == NULL) {
        obj->val = (int*)malloc(sizeof(int) * obj->size);
        obj->min = val;
    } else {
        obj->val = (int*)realloc(obj->val, sizeof(int) * obj->size);
    }
    obj->val[obj->size - 1] = val;
    if (val < obj->min) {
        obj->min = val;
    }
}

void minStackPop(MinStack* obj) {
    obj->size--;
    if (obj->size == 0) {
        free(obj->val);
        obj->val = NULL;
        return;
    }
    obj->val = (int*)realloc(obj->val, sizeof(int) * obj->size);
    int min = obj->val[0];
    for (int i=0; i<obj->size; i++) {
        if (obj->val[i] < min) {
            min = obj->val[i];
        }
    }
    obj->min = min;
}

int minStackTop(MinStack* obj) {
    return obj->val[obj->size - 1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    free(obj->val);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

int main(void) {
    MinStack* obj = minStackCreate();

    minStackPush(obj, 1);
    minStackPush(obj, 2);
    printf("Top: %d\n",minStackTop(obj));
    printf("Min: %d\n", minStackGetMin(obj));
    minStackPop(obj);
    printf("Min: %d\n", minStackGetMin(obj));
    printf("Top: %d\n",minStackTop(obj));
}
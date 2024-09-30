#include <stdlib.h>

typedef struct {
    int* stack;
    int* increment;
    int top;
    int maxSize;
} CustomStack;

CustomStack* customStackCreate(int maxSize) {
    CustomStack* obj = (CustomStack*)malloc(sizeof(CustomStack));
    obj->stack = (int*)malloc(maxSize * sizeof(int));
    obj->increment = (int*)calloc(maxSize, sizeof(int));
    obj->top = -1;
    obj->maxSize = maxSize;
    return obj;
}

void customStackPush(CustomStack* obj, int x) {
    if (obj->top < obj->maxSize - 1) {
        obj->top++;
        obj->stack[obj->top] = x;
    }
}

int customStackPop(CustomStack* obj) {
    if (obj->top == -1) {
        return -1;
    }
    int result = obj->stack[obj->top] + obj->increment[obj->top];
    if (obj->top > 0) {
        obj->increment[obj->top - 1] += obj->increment[obj->top];
    }
    obj->increment[obj->top] = 0;
    obj->top--;
    return result;
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    int i = (k - 1 < obj->top) ? k - 1 : obj->top;
    if (i >= 0) {
        obj->increment[i] += val;
    }
}

void customStackFree(CustomStack* obj) {
    free(obj->stack);
    free(obj->increment);
    free(obj);
}
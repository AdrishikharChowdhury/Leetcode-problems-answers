#include <stdlib.h>
#include <string.h>

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* stack = (int*)malloc(asteroidsSize * sizeof(int));
    int top = -1;
    
    for (int i = 0; i < asteroidsSize; i++) {
        int asteroid = asteroids[i];
        while (top >= 0 && asteroid < 0 && stack[top] > 0) {
            if (stack[top] < -asteroid) {
                top--;
                continue;
            } else if (stack[top] == -asteroid) {
                top--;
            }
            asteroid = 0;
            break;
        }
        if (asteroid != 0) {
            stack[++top] = asteroid;
        }
    }
    
    *returnSize = top + 1;
    return stack;
}
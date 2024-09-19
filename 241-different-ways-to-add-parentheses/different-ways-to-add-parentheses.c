#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RESULTS 10000

int* diffWaysToCompute(char* expression, int* returnSize) {
    int* result = malloc(MAX_RESULTS * sizeof(int));
    *returnSize = 0;

    // Base case: if the expression is a single number
    int isNumber = 1;
    for (int i = 0; expression[i]; i++) {
        if (!isdigit(expression[i])) {
            isNumber = 0;
            break;
        }
    }
    if (isNumber) {
        result[(*returnSize)++] = atoi(expression);
        return result;
    }

    for (int i = 0; expression[i]; i++) {
        char c = expression[i];
        if (c == '+' || c == '-' || c == '*') {
            // Split the expression at the operator
            char left[100], right[100];
            strncpy(left, expression, i);
            left[i] = '\0';
            strcpy(right, expression + i + 1);

            // Recursively compute results for left and right parts
            int leftSize, rightSize;
            int* leftResults = diffWaysToCompute(left, &leftSize);
            int* rightResults = diffWaysToCompute(right, &rightSize);

            // Combine results
            for (int l = 0; l < leftSize; l++) {
                for (int r = 0; r < rightSize; r++) {
                    int value;
                    switch (c) {
                        case '+':
                            value = leftResults[l] + rightResults[r];
                            break;
                        case '-':
                            value = leftResults[l] - rightResults[r];
                            break;
                        case '*':
                            value = leftResults[l] * rightResults[r];
                            break;
                    }
                    result[(*returnSize)++] = value;
                }
            }

            free(leftResults);
            free(rightResults);
        }
    }

    return result;
}
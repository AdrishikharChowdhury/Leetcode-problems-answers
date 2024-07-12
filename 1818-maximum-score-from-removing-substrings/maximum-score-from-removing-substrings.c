int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maximumGain(char* s, int x, int y) {
    int len = strlen(s);
    int score = 0;
    char *stack = (char*)malloc(len * sizeof(char));
    int top = -1;
    char first = x > y ? 'a' : 'b';
    char second = x > y ? 'b' : 'a';
    int high = max(x, y);
    int low = min(x, y);

    // First pass
    for (int i = 0; i < len; i++) {
        if (top >= 0 && s[i] == second && stack[top] == first) {
            top--;
            score += high;
        } else {
            stack[++top] = s[i];
        }
    }

    // Reset stack for second pass
    int tempLen = top + 1;
    char *temp = (char*)malloc(tempLen * sizeof(char));
    memcpy(temp, stack, tempLen * sizeof(char));
    top = -1;

    // Second pass
    for (int i = 0; i < tempLen; i++) {
        if (top >= 0 && temp[i] == first && stack[top] == second) {
            top--;
            score += low;
        } else {
            stack[++top] = temp[i];
        }
    }

    free(stack);
    free(temp);
    return score;
}
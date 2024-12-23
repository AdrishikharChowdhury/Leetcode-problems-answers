#include <stdio.h>
#include <stdlib.h>

struct Node {
    long val;
    int pos;
    int newPos; // Track new position after sorting
};

int compare(const void* a, const void* b) {
    struct Node* n1 = (struct Node*)a;
    struct Node* n2 = (struct Node*)b;
    return (n1->val > n2->val) - (n1->val < n2->val);
}

// Calculate minimum swaps required to sort the level
int getMinSwaps(long* values, int size) {
    if (size <= 1) return 0;

    struct Node* nodes = malloc(size * sizeof(struct Node));
    if (!nodes) return 0;

    // Initialize nodes
    for (int i = 0; i < size; i++) {
        nodes[i].val = values[i];
        nodes[i].pos = i;
    }

    // Sort based on values
    qsort(nodes, size, sizeof(struct Node), compare);

    // Mark sorted positions
    for (int i = 0; i < size; i++) {
        nodes[i].newPos = i;
    }

    int* visited = calloc(size, sizeof(int));
    if (!visited) {
        free(nodes);
        return 0;
    }

    int swaps = 0;

    // Process each position
    for (int i = 0; i < size; i++) {
        if (visited[i] || nodes[i].newPos == nodes[i].pos)
            continue;

        int cycle = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = 1;
            j = nodes[j].pos;
            cycle++;
        }
        swaps += (cycle - 1);
    }

    free(visited);
    free(nodes);
    return swaps;
}



// Calculate minimum operations to sort tree by levels
int minimumOperations(struct TreeNode* root) {
    if (!root) return 0;

    int maxQueueSize = 1000, maxLevelSize = 1000;
    struct TreeNode** queue = malloc(maxQueueSize * sizeof(struct TreeNode*));
    if (!queue) return 0;

    long* levelVals = malloc(maxLevelSize * sizeof(long));
    if (!levelVals) {
        free(queue);
        return 0;
    }

    int front = 0, rear = 0, totalSwaps = 0;
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        if (levelSize > maxLevelSize) {
            maxLevelSize = levelSize * 2;
            levelVals = realloc(levelVals, maxLevelSize * sizeof(long));
            if (!levelVals) {
                free(queue);
                return 0;
            }
        }

        int levelCount = 0;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* curr = queue[front++];
            levelVals[levelCount++] = curr->val;

            if (curr->left) {
                if (rear >= maxQueueSize) {
                    maxQueueSize *= 2;
                    queue = realloc(queue, maxQueueSize * sizeof(struct TreeNode*));
                    if (!queue) {
                        free(levelVals);
                        return 0;
                    }
                }
                queue[rear++] = curr->left;
            }
            if (curr->right) {
                if (rear >= maxQueueSize) {
                    maxQueueSize *= 2;
                    queue = realloc(queue, maxQueueSize * sizeof(struct TreeNode*));
                    if (!queue) {
                        free(levelVals);
                        return 0;
                    }
                }
                queue[rear++] = curr->right;
            }
        }

        // Calculate swaps for current level
        totalSwaps += getMinSwaps(levelVals, levelCount);
    }

    free(levelVals);
    free(queue);
    return totalSwaps;
}

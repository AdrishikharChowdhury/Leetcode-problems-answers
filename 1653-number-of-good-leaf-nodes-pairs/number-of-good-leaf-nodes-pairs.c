/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_LEAVES 1000

int count = 0;

int* dfs(struct TreeNode* node, int distance, int* size) {
    if (node == NULL) {
        *size = 0;
        return NULL;
    }

    if (node->left == NULL && node->right == NULL) {
        int* leaf = malloc(sizeof(int));
        leaf[0] = 0;
        *size = 1;
        return leaf;
    }

    int leftSize = 0, rightSize = 0;
    int* leftDistances = dfs(node->left, distance, &leftSize);
    int* rightDistances = dfs(node->right, distance, &rightSize);

    for (int i = 0; i < leftSize; i++) {
        for (int j = 0; j < rightSize; j++) {
            if (leftDistances[i] + rightDistances[j] + 2 <= distance) {
                count++;
            }
        }
    }

    int* result = malloc(MAX_LEAVES * sizeof(int));
    int resultSize = 0;

    for (int i = 0; i < leftSize; i++) {
        if (leftDistances[i] + 1 < distance) {
            result[resultSize++] = leftDistances[i] + 1;
        }
    }
    for (int i = 0; i < rightSize; i++) {
        if (rightDistances[i] + 1 < distance) {
            result[resultSize++] = rightDistances[i] + 1;
        }
    }

    free(leftDistances);
    free(rightDistances);

    *size = resultSize;
    return result;
}

int countPairs(struct TreeNode* root, int distance) {
    count = 0;
    int size;
    dfs(root, distance, &size);
    return count;
}
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.

int countPathsWithSum(struct TreeNode* node, long long currentSum, int targetSum) {
    if (node == NULL) {
        return 0;
    }

    currentSum += node->val;
    int totalPaths = 0;

    if (currentSum == targetSum) {
        totalPaths++;
    }

    totalPaths += countPathsWithSum(node->left, currentSum, targetSum);
    totalPaths += countPathsWithSum(node->right, currentSum, targetSum);

    return totalPaths;
}

int pathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return 0;
    }

    // Count paths starting from the current node
    int pathsFromRoot = countPathsWithSum(root, 0, targetSum);

    // Recursively try to find paths starting from the left and right child
    int pathsOnLeft = pathSum(root->left, targetSum);
    int pathsOnRight = pathSum(root->right, targetSum);

    return pathsFromRoot + pathsOnLeft + pathsOnRight;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool findPath(struct TreeNode* node, int value, char* path, int* pathLen) {
    if (node == NULL) {
        return false;
    }
    
    if (node->val == value) {
        return true;
    }
    
    if (findPath(node->left, value, path, pathLen)) {
        path[(*pathLen)++] = 'L';
        return true;
    }
    
    if (findPath(node->right, value, path, pathLen)) {
        path[(*pathLen)++] = 'R';
        return true;
    }
    
    return false;
}

char* getDirections(struct TreeNode* root, int startValue, int destValue) {
    char path1[100000] = {0};
    char path2[100000] = {0};
    int len1 = 0, len2 = 0;
    
    findPath(root, startValue, path1, &len1);
    findPath(root, destValue, path2, &len2);
    
    // Reverse paths
    for (int i = 0; i < len1 / 2; i++) {
        char temp = path1[i];
        path1[i] = path1[len1 - 1 - i];
        path1[len1 - 1 - i] = temp;
    }
    for (int i = 0; i < len2 / 2; i++) {
        char temp = path2[i];
        path2[i] = path2[len2 - 1 - i];
        path2[len2 - 1 - i] = temp;
    }
    
    // Find common prefix
    int i = 0;
    while (i < len1 && i < len2 && path1[i] == path2[i]) {
        i++;
    }
    
    // Construct result
    char* result = (char*)malloc(100000 * sizeof(char));
    int resultLen = 0;
    
    for (int j = i; j < len1; j++) {
        result[resultLen++] = 'U';
    }
    
    for (int j = i; j < len2; j++) {
        result[resultLen++] = path2[j];
    }
    
    result[resultLen] = '\0';
    
    return result;
}

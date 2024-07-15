/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct TreeNode* createBinaryTree(int** descriptions, int descriptionsSize, int* descriptionsColSize) {
    struct TreeNode* nodeMap[100001] = {NULL};  // Assuming max value is 100000
    int childSet[100001] = {0};  // To keep track of child nodes
    
    for (int i = 0; i < descriptionsSize; i++) {
        int parent = descriptions[i][0], child = descriptions[i][1], isLeft = descriptions[i][2];
        
        if (nodeMap[parent] == NULL) {
            nodeMap[parent] = createNode(parent);
        }
        if (nodeMap[child] == NULL) {
            nodeMap[child] = createNode(child);
        }
        
        if (isLeft == 1) {
            nodeMap[parent]->left = nodeMap[child];
        } else {
            nodeMap[parent]->right = nodeMap[child];
        }
        
        childSet[child] = 1;
    }
    
    // Find the root (node that is not a child of any other node)
    for (int i = 0; i < descriptionsSize; i++) {
        if (childSet[descriptions[i][0]] == 0) {
            return nodeMap[descriptions[i][0]];
        }
    }
    
    return NULL;
}
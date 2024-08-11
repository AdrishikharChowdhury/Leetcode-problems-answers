/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <limits.h>

struct QueueNode {
    struct TreeNode* node;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q, struct TreeNode* node) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->node = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct TreeNode* deQueue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QueueNode* temp = q->front;
    struct TreeNode* node = temp->node;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return node;
}

int maxLevelSum(struct TreeNode* root) {
    if (root == NULL) return 0;
    
    struct Queue* q = createQueue();
    enQueue(q, root);
    
    int maxSum = INT_MIN;
    int maxLevel = 0;
    int currentLevel = 0;
    
    while (q->front != NULL) {
        int size = 0;
        struct QueueNode* temp = q->front;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        
        int levelSum = 0;
        currentLevel++;
        
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = deQueue(q);
            levelSum += node->val;
            
            if (node->left) enQueue(q, node->left);
            if (node->right) enQueue(q, node->right);
        }
        
        if (levelSum > maxSum) {
            maxSum = levelSum;
            maxLevel = currentLevel;
        }
    }
    
    return maxLevel;
}
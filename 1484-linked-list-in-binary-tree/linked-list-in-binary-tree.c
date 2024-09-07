#include <stdbool.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



bool dfsCheck(struct ListNode *head, struct TreeNode *root) {
    if (head == NULL) return true;
    if (root == NULL) return false;
    
    if (head->val != root->val) return false;
    
    return dfsCheck(head->next, root->left) || dfsCheck(head->next, root->right);
}

bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    if (head == NULL) return true;
    if (root == NULL) return false;
    
    if (dfsCheck(head, root)) return true;
    
    return isSubPath(head, root->left) || isSubPath(head, root->right);
}
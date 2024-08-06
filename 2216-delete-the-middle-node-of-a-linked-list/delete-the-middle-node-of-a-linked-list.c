/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    // If the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;
    
    // Find the middle node
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    
    // Delete the middle node
    prev->next = slow->next;
    free(slow);  // Free the memory of the deleted node
    
    return head;
}
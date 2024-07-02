/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false; // No cycle if the list is empty or has only one node
    }
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next; // Move one step at a time
        fast = fast->next->next; // Move two steps at a time
        
        if (slow == fast) {
            return true; // If they meet, there's a cycle
        }
    }
    
    return false;
}
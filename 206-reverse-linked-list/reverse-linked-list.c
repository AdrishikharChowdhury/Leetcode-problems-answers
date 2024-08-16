struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;  // Save the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move the prev pointer up
        current = next;        // Move to the next node
    }
    
    head = prev;  // Update the head to the new front
    return head;
}

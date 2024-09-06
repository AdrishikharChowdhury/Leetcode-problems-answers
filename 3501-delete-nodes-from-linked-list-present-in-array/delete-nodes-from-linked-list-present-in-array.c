#include <stdlib.h>
#include <stdbool.h>

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    // Find the range of values in the nums array
    int minVal = nums[0], maxVal = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < minVal) minVal = nums[i];
        if (nums[i] > maxVal) maxVal = nums[i];
    }

    // Create a hash set with a size large enough to hold all values from minVal to maxVal
    int rangeSize = maxVal - minVal + 1;
    bool* numSet = (bool*)calloc(rangeSize, sizeof(bool));
    if (numSet == NULL) {
        // Handle memory allocation failure
        return head;
    }

    // Populate the hash set with values from nums
    for (int i = 0; i < numsSize; i++) {
        numSet[nums[i] - minVal] = true;
    }

    // Dummy node to handle head removal
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* current = &dummy;

    // Traverse the list and remove nodes
    while (current->next != NULL) {
        int currentValue = current->next->val;
        if (currentValue >= minVal && currentValue <= maxVal && numSet[currentValue - minVal]) {
            // Remove the node
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);  // Free memory of the removed node
        } else {
            current = current->next;
        }
    }

    // Free the allocated memory for the hash set
    free(numSet);
    
    return dummy.next;
}

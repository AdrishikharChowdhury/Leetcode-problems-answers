/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    result[0] = -1;  // minDistance
    result[1] = -1;  // maxDistance

    if (!head || !head->next || !head->next->next)
        return result;
    struct ListNode* prev = head;
    struct ListNode* curr = head->next;
    struct ListNode* next = curr->next;

    int firstCritical = -1;
    int lastCritical = -1;
    int prevCritical = -1;
    int minDist = INT_MAX;
    int index = 1;

    while (next) {
        if ((curr->val > prev->val && curr->val > next->val) ||
            (curr->val < prev->val && curr->val < next->val)) {
            if (firstCritical == -1) {
                firstCritical = index;
            } else {
                if (prevCritical != -1) {
                    minDist = (index - prevCritical < minDist) ? index - prevCritical : minDist;
                }
            }
            lastCritical = index;
            prevCritical = index;
        }
        prev = curr;
        curr = next;
        next = next->next;
        index++;
    }

    if (lastCritical - firstCritical > 0) {
        result[0] = minDist;
        result[1] = lastCritical - firstCritical;
    }

    return result;
}
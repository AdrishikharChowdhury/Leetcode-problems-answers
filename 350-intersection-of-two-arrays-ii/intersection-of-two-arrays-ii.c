/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_VAL 1000
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) 
{
    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    int k = 0;
    int count[MAX_VAL + 1] = {0};
    for (int i = 0; i < nums1Size; i++)
    {
        if (nums1[i] <= MAX_VAL)
        {
            count[nums1[i]]++;
        }
    }
    for (int i = 0; i < nums2Size; i++)
    {
        if (nums2[i] <= MAX_VAL && count[nums2[i]] > 0)
        {
            result[k++] = nums2[i];
            count[nums2[i]]--;
        }
    }
    *returnSize = k;
    return result;
}
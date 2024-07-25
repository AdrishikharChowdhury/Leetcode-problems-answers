#include <stdlib.h>
#include <time.h>

#define INSERTION_SORT_THRESHOLD 10

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int* nums, int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = nums[i];
        int j = i - 1;
        while (j >= low && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

void shuffle(int* nums, int numsSize) {
    srand(time(NULL));
    for (int i = numsSize - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&nums[i], &nums[j]);
    }
}

void partition(int* nums, int low, int high, int* left, int* right) {
    int pivot = nums[high];
    int i = low - 1, j = high, p = low - 1, q = high;

    while (1) {
        while (nums[++i] < pivot);
        while (pivot < nums[--j]) if (j == low) break;
        if (i >= j) break;
        swap(&nums[i], &nums[j]);
        if (nums[i] == pivot) swap(&nums[++p], &nums[i]);
        if (nums[j] == pivot) swap(&nums[--q], &nums[j]);
    }
    swap(&nums[i], &nums[high]);
    j = i - 1;
    for (int k = low; k <= p; k++, j--) swap(&nums[k], &nums[j]);
    i = i + 1;
    for (int k = high - 1; k >= q; k--, i++) swap(&nums[k], &nums[i]);
    *left = j + 1;
    *right = i - 1;
}

void sort(int* nums, int low, int high) {
    if (high - low <= INSERTION_SORT_THRESHOLD) {
        insertionSort(nums, low, high);
        return;
    }

    int left, right;
    partition(nums, low, high, &left, &right);
    sort(nums, low, left - 1);
    sort(nums, right + 1, high);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    shuffle(nums, numsSize);
    sort(nums, 0, numsSize - 1);
    *returnSize = numsSize;
    return nums;
}
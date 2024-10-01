#include <stdbool.h>
#include <stdlib.h>

bool canArrange(int* arr, int arrSize, int k) {
    // Allocate memory for frequency array
    int* frequency = (int*)calloc(k, sizeof(int));
    if (frequency == NULL) {
        return false;  // Memory allocation failed
    }

    // Count the frequency of each remainder
    for (int i = 0; i < arrSize; i++) {
        int remainder = ((arr[i] % k) + k) % k;  // Handle negative numbers
        frequency[remainder]++;
    }

    // Check if the frequencies allow for pairing
    bool result = true;
    if (frequency[0] % 2 != 0) {
        result = false;
    } else {
        for (int i = 1; i <= k / 2 && result; i++) {
            if (i == k - i) {
                if (frequency[i] % 2 != 0) {
                    result = false;
                }
            } else {
                if (frequency[i] != frequency[k - i]) {
                    result = false;
                }
            }
        }
    }

    // Free allocated memory
    free(frequency);

    return result;
}
int binary_search(int** events, int eventsSize, int currentIndex) {
    int targetEnd = events[currentIndex][1];
    int left = currentIndex + 1;
    int right = eventsSize - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (events[mid][0] > targetEnd) {
            // If this is the first such event, or the previous event overlaps
            if (mid == left || events[mid-1][0] <= targetEnd) {
                return mid;
            }
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return -1;
}
int compare_start(const void* a, const void* b) {
    int* eventA = *(int**)a;
    int* eventB = *(int**)b;
    return eventA[0] - eventB[0];
}
int maxTwoEvents(int** events, int eventsSize, int* eventsColSize) {
    // Sort events by start time
    qsort(events, eventsSize, sizeof(int*), compare_start);
    
    int maxValue = 0;
    
    // Allocate max from right array
    int* maxFromRight = (int*)malloc(eventsSize * sizeof(int));
    
    // Compute max from right
    maxFromRight[eventsSize - 1] = events[eventsSize - 1][2];
    for (int i = eventsSize - 2; i >= 0; i--) {
        maxFromRight[i] = fmax(maxFromRight[i + 1], events[i][2]);
    }
    
    // Find max two events
    for (int i = 0; i < eventsSize; i++) {
        // Current event value
        int currValue = events[i][2];
        maxValue = fmax(maxValue, currValue);
        
        // Find max value for a non-overlapping event
        int j = binary_search(events, eventsSize, i);
        if (j != -1) {
            maxValue = fmax(maxValue, currValue + maxFromRight[j]);
        }
    }
    
    // Free temporary array
    free(maxFromRight);
    
    return maxValue;
}

// Comparison function for qsort - sort by start time


// Binary search to find first non-overlapping event

bool canEatAll(int* piles, int pilesSize, int k, int h) {
    long long hoursNeeded = 0;  // Use long long to prevent overflow
    for (int i = 0; i < pilesSize; i++) {
        // Ceiling division: (pile + k - 1) / k
        hoursNeeded += (piles[i] + k - 1) / k;
    }
    return hoursNeeded <= h;
}

int getMaxPile(int* piles, int pilesSize) {
    int max = 0;
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > max) {
            max = piles[i];
        }
    }
    return max;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1;
    int right = getMaxPile(piles, pilesSize);
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (canEatAll(piles, pilesSize, mid, h)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}
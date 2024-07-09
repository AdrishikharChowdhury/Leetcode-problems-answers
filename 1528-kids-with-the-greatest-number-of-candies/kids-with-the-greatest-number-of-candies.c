bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int i;
    bool* result = (bool*)malloc(candiesSize * sizeof(bool));
    *returnSize = candiesSize;

    // Find the maximum number of candies
    int maxCandies = candies[0];
    for (i = 1; i < candiesSize; i++) {
        if (candies[i] > maxCandies) {
            maxCandies = candies[i];
        }
    }

    // Check for each kid
    for (i = 0; i < candiesSize; i++) {
        result[i] = (candies[i] + extraCandies >= maxCandies);
    }

    return result;
}
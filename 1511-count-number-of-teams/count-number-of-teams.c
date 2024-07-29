int numTeams(int* rating, int ratingSize) {
    int count = 0;
    
    for (int j = 1; j < ratingSize - 1; j++) {
        int leftSmaller = 0, leftLarger = 0;
        int rightSmaller = 0, rightLarger = 0;
        
        // Count elements on the left
        for (int i = 0; i < j; i++) {
            if (rating[i] < rating[j]) leftSmaller++;
            if (rating[i] > rating[j]) leftLarger++;
        }
        
        // Count elements on the right
        for (int k = j + 1; k < ratingSize; k++) {
            if (rating[k] < rating[j]) rightSmaller++;
            if (rating[k] > rating[j]) rightLarger++;
        }
        
        // Add valid combinations
        count += leftSmaller * rightLarger + leftLarger * rightSmaller;
    }
    
    return count;
}
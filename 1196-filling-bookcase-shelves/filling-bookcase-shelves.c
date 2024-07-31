#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int minHeightShelves(int** books, int booksSize, int* booksColSize, int shelfWidth) {
    int dp[booksSize + 1];
    memset(dp, 0, sizeof(dp));
    
    for (int i = 1; i <= booksSize; i++) {
        int width = books[i-1][0];
        int height = books[i-1][1];
        dp[i] = dp[i-1] + height;
        
        for (int j = i - 1; j > 0 && width + books[j-1][0] <= shelfWidth; j--) {
            width += books[j-1][0];
            height = MAX(height, books[j-1][1]);
            dp[i] = MIN(dp[i], dp[j-1] + height);
        }
    }
    
    return dp[booksSize];
}
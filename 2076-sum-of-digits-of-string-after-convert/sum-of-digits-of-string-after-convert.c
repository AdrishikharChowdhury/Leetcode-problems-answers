int sumDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int getLucky(char* s, int k) {
    int sum = 0;
    
    // Convert step and first transform
    while (*s) {
        int value = *s - 'a' + 1;
        sum += (value / 10) + (value % 10);  // Directly sum the digits
        s++;
    }
    
    // Remaining transforms
    for (int i = 1; i < k; i++) {
        sum = sumDigits(sum);
    }
    
    return sum;
}
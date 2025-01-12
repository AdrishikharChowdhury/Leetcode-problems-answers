bool canBeValid(char* s, char* locked) {
    int n = strlen(s);
    
    // If length is odd, it can't be valid
    if (n % 2 == 1) return false;
    
    // First pass: left to right
    // Check if we can balance all closing brackets
    int balance = 0, unlock = 0;
    for (int i = 0; i < n; i++) {
        if (locked[i] == '1') {
            balance += (s[i] == '(' ? 1 : -1);
        } else {
            unlock++;
        }
        
        // At any point, if we have more closing brackets than we can handle
        if (balance + unlock < 0) return false;
    }
    
    // Second pass: right to left
    // Check if we can balance all opening brackets
    balance = 0;
    unlock = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (locked[i] == '1') {
            balance += (s[i] == ')' ? 1 : -1);
        } else {
            unlock++;
        }
        
        // At any point, if we have more opening brackets than we can handle
        if (balance + unlock < 0) return false;
    }
    
    return true;
}
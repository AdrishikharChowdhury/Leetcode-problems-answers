int reachNumber(int target) {
    // Convert target to positive for easier calculation
    target = abs(target);    
    int i = 0,sum=0;
    while (sum < target || (sum - target) % 2 != 0) 
    {
        i++;
        sum += i;
    }
    return i;
}
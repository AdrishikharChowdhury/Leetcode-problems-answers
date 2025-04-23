int sumOfDigits(int n)
{
    int sum = 0, r;
    while (n > 0)
    {
        r = n % 10;
        sum += r;
        n /= 10;
    }
    return sum;
}

int countLargestGroup(int n)
{
    int groups[100] = {0}; // Array to store counts of numbers by sum of digits
    int maxGroupSize = 0;
    
    // Count how many numbers belong to each sum of digits
    for (int i = 1; i <= n; i++)
    {
        int sum = sumOfDigits(i);
        groups[sum]++;
        
        if (groups[sum] > maxGroupSize)
        {
            maxGroupSize = groups[sum];
        }
    }
    
    // Count how many groups have the largest size
    int count = 0;
    for (int i = 0; i < 100; i++) // We assume sum of digits won't exceed 99
    {
        if (groups[i] == maxGroupSize)
        {
            count++;
        }
    }

    return count;
}
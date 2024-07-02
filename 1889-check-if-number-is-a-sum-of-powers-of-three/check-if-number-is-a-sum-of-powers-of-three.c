bool checkPowersOfThree(int n) {
    int power = 1;
    while (power <= n)
    {
        power=power*3;
    }
    while (n > 0 && power > 0)
    {
        if (power <= n)
            n=n-power;
        power=power/3; 
    }
    return n == 0;
}

class Solution {
    public static boolean Sym(int a) {
        int count = 0;
        int[] digits = new int[10];
        if (a < 10) {
            return false;
        }
        while (a != 0) {
            digits[count++] = a % 10;
            a /= 10;
        }
        if (count % 2 != 0) {
            return false;
        }
        int hl = count / 2;
        int s1 = 0, s2 = 0, i;
        for (i = 0; i < hl; i++) {
            s1 += digits[i];
            s2 += digits[count - 1 - i];
        }
        return s1 == s2;
    }
    public int countSymmetricIntegers(int low, int high) {
        int c=0;
        for(int i=low;i<=high;i++)
        {
            if(Sym(i))
            c++;
        }
        return c;
    }
}
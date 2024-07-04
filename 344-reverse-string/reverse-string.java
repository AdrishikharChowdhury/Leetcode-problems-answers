class Solution {
    public void reverseString(char[] s)
    {
        char temp;
        int sSize=s.length;
        int left=0,right=sSize-1;
        while (left < right)
        {
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
}
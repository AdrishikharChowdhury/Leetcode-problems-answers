class Solution {
    public int scoreOfString(String s) {
        int sum=0;
        for(int i=0;i<s.length()-1;i++)
        {
            int ascii1 = (int)s.charAt(i);      
            int ascii2 = (int)s.charAt(i+1);  
            sum =sum+ Math.abs(ascii1 - ascii2);
        }
        return sum;
    }
}
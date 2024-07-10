class Solution {
    public int minOperations(String[] logs) {
        int c=0;
        for(final String ch:logs)
        {
            if(ch.equals("./"))
            continue;
            if(ch.equals("../"))
            c=Math.max(0,c-1);
            else
            ++c;
        }
        return c;
    }
}
class Solution {
    public boolean checkIfExist(int[] arr) {
        int i,j;
        for(i=0;i<arr.length;i++)
        {
            for(j=arr.length-1;j>=0;j--)
            {
                if(i!=j && arr[i]==2*arr[j])
                {
                    return true;
                }
            }
        }
        return false;
    }
}
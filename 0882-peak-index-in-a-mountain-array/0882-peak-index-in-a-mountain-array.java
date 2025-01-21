class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int mid,st=1,end=arr.length-2;
        while(st<=end)
        {
            mid=st+(end-st)/2;
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
            {
                return mid;
            }
            else if(arr[mid-1]<arr[mid])
            {
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return -1;
    }
}
1int *bubbleSort(int *arr, int arrSize){
2    int temp,i,j;
3    for(i=0;i<arrSize-1;i++){
4        for(j=0;j<arrSize-i-1;j++){
5            if(arr[j]>arr[j+1])
6            {
7                temp=arr[j];
8                arr[j]=arr[j+1];
9                arr[j+1]=temp;
10            }
11        }
12    }
13    return arr;  
14}
15
16bool canMakeArithmeticProgression(int* arr, int arrSize) {
17    int i,diff;
18    arr=bubbleSort(arr,arrSize);
19    diff=arr[1]-arr[0];
20    for(i=2;i<arrSize;i++){
21        if(arr[i]-arr[i-1]!=diff){
22            return false;
23        }
24    }
25    return true;
26}
import java.util.Scanner;
public class threeConsecutiveOdds{
    public static void main(String[] args)
    {
        Scanner read=new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int x= read.nextInt();
        int[] a=new int[x];
        System.out.println("Enter the elements:");
        for(int i=0;i<x;i++)
        {
            a[i]=read.nextInt();
        }
        boolean b=tco(a,x);
        if(b)
            System.out.print("The array have 3 consecutive odd terms");
        else
            System.out.print("The array doesn't have 3 consecutive odd terms");
    }
    public static boolean tco(int[] arr,int arrSize) {
        int count = 0;
        for (int i = 0; i < arrSize; i++)
        {
            if(arr[i]%2!=0)
            {
                count++;
                if(count==3)
                    return true;
            }
            else
                count=0;
        }
        return false;
    }
}
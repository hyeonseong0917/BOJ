/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
    static int n=0;
    static int [] arr;
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        Scanner sc=new Scanner(System.in);
        while(true){
            n=Integer.parseInt(sc.next());
            arr=new int[123456*2+1];
            if(n==0){
                break;
            }
            System.out.println(getNum(n));
        }
    }
    static int getNum(int num){
        for(int i=2;i<=num*2;++i){
            arr[i]=i;
        }
        for(int i=2;i<=num*2;++i){
            if(arr[i]==0) continue;
            for(int j=2*i;j<=num*2;j+=i){
                arr[j]=0;
            }
        }
        int cnt=0;
        for(int i=num+1;i<=num*2;++i){
            if(arr[i]!=0){
                ++cnt;
            }
        }
        return cnt;
    }
}
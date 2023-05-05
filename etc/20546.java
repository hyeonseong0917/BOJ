/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
    static int money;
    static int[] arr;
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        Scanner sc=new Scanner(System.in);
        money=Integer.parseInt(sc.next());
        arr= new int[14+1];
        for(int i=0;i<14;++i){
            int a=Integer.parseInt(sc.next());
            arr[i]=a;
        }
        int jun_num=jun();
        int sung_num=sung();
        if(jun_num>sung_num){
            System.out.print("BNP");
        }else if(jun_num<sung_num){
            System.out.print("TIMING");
        }else{
            System.out.print("SAMESAME");
        }
        // System.out.println(jun());
        // System.out.println(sung());
    }
    static int jun(){
        int cur_money=money;
        int cnt=0;
        for(int i=0;i<14;++i){
            if(cur_money>=arr[i]){
                int n=cur_money/arr[i];
                cnt+=n;
                cur_money-=arr[i]*n;
            }
        }
        return cur_money+cnt*arr[13];
    }
    static int sung(){
        int cur_money=money;
        int cnt=0;
        int plus_cnt=0, minus_cnt=0;
        for(int i=2;i<13;++i){
            int cur_price=arr[i];
            if(arr[i]<arr[i-1] && arr[i-1]<arr[i-2]){
                //3일째 하락
                if(cur_money>=arr[i+1]){
                    int n=cur_money/arr[i+1];
                    cnt+=n;
                    cur_money-=arr[i+1]*n;
                }
            }
            if(arr[i]>arr[i-1] && arr[i-1]>arr[i-2]){
                cur_money+=cnt*arr[i+1];
                cnt=0;
            }
        }
        if(cnt!=0){
            cur_money+=cnt*arr[13];
        }
        return cur_money;
    }
}
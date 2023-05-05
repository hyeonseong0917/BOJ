/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class 12933
{
    static String str="";
    static boolean visited[];
    static int N=0;
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        Input();
        int res=solve();
        System.out.print(res);
    }
    static void Input(){
        Scanner sc = new Scanner(System.in);
        str=sc.next();
        visited=new boolean[2500+1];
        N=str.length();
    }
    static int check(int startIdx){
        char arr[]=new char[]{'q','u','a','c','k'};
        int idx=0;
        for(int i=startIdx;i<N;++i){
            if(str.charAt(i)==arr[idx] && visited[i]==false){
                visited[i]=true;
                idx+=1;
                if(idx==5){
                    idx=0;
                }
            }
        }
        if(idx==0){
            return 1;
        }else{
            return -1;
        }
    }
    static int solve(){
        int sum=0;
        for(int i=0;i<N;++i){
            if(str.charAt(i)=='q' && visited[i]==false){
                int num=check(i);
                if(num==-1){
                    return -1;
                }
                sum+=1;
            }
        }
        for(int i=0;i<N;++i){
            if(visited[i]==false){
                return -1;
            }
        }
        return sum;
    }
}
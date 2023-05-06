/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
    static int [] arr=new int[30+1];
    static void Input(){
        Scanner sc=new Scanner(System.in);

        for(int i=0;i<28;++i){
            int a=Integer.parseInt(sc.next());
            arr[a]=1;
        }
    }
    static ArrayList<Integer> a=new ArrayList<>();
    static void solve(){
        for(int i=1;i<=30;++i){
            if(arr[i]!=1){
                a.add(i);
            }
        }
        for(int i=0;i<2;++i){
            System.out.println(a.get(i));
        }
    }
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        Input();
        solve();
    }
}
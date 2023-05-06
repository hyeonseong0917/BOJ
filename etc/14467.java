/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Cow{
    int num,pos;
    public Cow(int num, int pos){
        this.num=num;
        this.pos=pos;
    }
}
class Main
{
    static int N=0;
    static int [] arr=new int[100+1];
    static Cow [] c=new Cow[100+1];
    static void Input(){
        Scanner sc=new Scanner(System.in);
        N=Integer.parseInt(sc.next());
        for(int i=1;i<=100;++i){
            arr[i]=-1;
        }
        for(int i=0;i<N;++i){
            int a=Integer.parseInt(sc.next());
            int b=Integer.parseInt(sc.next());
            c[i]=new Cow(a,b);
        }
    }

    static void solve(){
        int cnt=0;
        for(int i=0;i<N;++i){

            if(arr[c[i].num]==-1){
                arr[c[i].num]=c[i].pos;
            }else{
                if(arr[c[i].num]!=c[i].pos){
                    arr[c[i].num]=c[i].pos;
                    ++cnt;
                }
            }
        }
        System.out.print(cnt);
    }
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        Input();
        solve();
    }
}
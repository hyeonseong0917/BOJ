/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Person{
    int s,idx;
    public Person(int s, int idx){
        this.s=s;
        this.idx=idx;
    }
}
class 1244
{
    static int N,M=0;
    static int [] arr=new int[100+1];
    static Person[] p=new Person[100+1];
    static void Input(){
        Scanner sc=new Scanner(System.in);
        N=Integer.parseInt(sc.next());
        for(int i=1;i<=N;++i){
            arr[i]=Integer.parseInt(sc.next());
        }
        M=Integer.parseInt(sc.next());
        for(int i=0;i<M;++i){
            int s=Integer.parseInt(sc.next());
            int idx=Integer.parseInt(sc.next());
            p[i]=new Person(s,idx);
        }
    }
    static void man(int startIdx){
        int cnt=1;
        while(true){
            if(startIdx*cnt>N){
                break;
            }
            int nextIdx=startIdx*cnt;
            if(arr[nextIdx]==0){
                arr[nextIdx]=1;
            }else{
                arr[nextIdx]=0;
            }
            ++cnt;
        }
    }
    static boolean isRange(int startIdx){
        return (startIdx>=1 && startIdx<=N);
    }
    static void woman(int startIdx){
        int step=1;
        if(arr[startIdx]==0){
            arr[startIdx]=1;
        }else{
            arr[startIdx]=0;
        }
        while(true){
            if(isRange(startIdx+step)==false || isRange(startIdx-step)==false){
                break;
            }
            if(arr[startIdx+step]!=arr[startIdx-step]){
                break;
            }
            if(arr[startIdx+step]==0){
                arr[startIdx+step]=1;
                arr[startIdx-step]=1;
            }else{
                arr[startIdx+step]=0;
                arr[startIdx-step]=0;
            }
            ++step;
        }
    }
    static void solve(){
        for(int i=0;i<M;++i){
            if(p[i].s==1){
                man(p[i].idx);
            }else{
                woman(p[i].idx);
            }
        }
        String s="";
        for(int i=1;i<=N;++i){
            s+=Integer.toString(arr[i]);
            if(i%20==0 && i!=1){
                if(i!=N){
                    s+="\n";
                }
            }else{
                s+=" ";
            }
        }
        System.out.print(s);
    }
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        Input();
        solve();

    }
}
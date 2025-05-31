package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_5527 {
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        int n;
        n=sc.nextInt();
        ArrayList<Integer> v=new ArrayList<>();
        for(int i=0;i<n;++i){
            int a=sc.nextInt();
            v.add(a);
        }
        int cnt=1;
        ArrayList<Integer> arr=new ArrayList<>();
        for(int i=1;i<n;++i){
            if(v.get(i)==v.get(i-1)){
                arr.add(cnt);
                cnt=1;
            }else{
                ++cnt;
            }
        }
        arr.add(cnt);
        if(n==2){
            System.out.println(2);
        }else{
            int ans=0;
            if(arr.size()<3){
                for(int i=0;i<arr.size();++i){
                    ans+=arr.get(i);
                }
            }else{
                for(int i=0;i+2<=arr.size()-1;++i){
                    ans=Math.max(ans,arr.get(i)+arr.get(i+1)+arr.get(i+2));
                }
            }
            System.out.println(ans);
        }
    }

}

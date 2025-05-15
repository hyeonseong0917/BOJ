package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class BOJ_25635 {
    static int n;
    static ArrayList<Integer> v=new ArrayList<>();
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        for(int i=0;i<n;++i){
            int a;
            a=sc.nextInt();
            v.add(a);
        }
        Collections.sort(v);
        long ans=0;
        long psum=0;
        long max_num=v.get(n-1);
        for(int i=0;i<n-1;++i){
            psum+=v.get(i);
        }
        if(max_num-1<=psum){
            ans=max_num+psum;
        }else{
            ans=psum+psum+1;
        }
        System.out.println(ans);
    }

}

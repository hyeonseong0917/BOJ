package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class BOJ_1495 {

    static int n,s,m;
    static ArrayList<Integer> v=new ArrayList<>();
    static int dp[][];
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        s=sc.nextInt();
        m=sc.nextInt();
        dp=new int[n][1000+1];
        for(int i=0;i<n;++i){
            int a=sc.nextInt();
            v.add(a);
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<=1000;++j){
                dp[i][j]=-1;
            }
        }
        int fst_num=v.get(0)+s;
        int sed_num=s-v.get(0);
        if(fst_num>=0 && fst_num<=m){
            dp[0][fst_num]=1;
        }
        if(sed_num>=0 && sed_num<=m){
            dp[0][sed_num]=1;
        }
        for(int i=1;i<n;++i){
            int w=v.get(i);
            for(int j=0;j<=1000;++j){
                if(dp[i-1][j]==1){
                    if(j+w<=m && j+w>=0){
                        dp[i][j+w]=1;
                    }
                    if(j-w<=m && j-w>=0){
                        dp[i][j-w]=1;
                    }
                }
            }
        }
        int ans=-1;
        for(int i=m;i>=0;--i){
            if(dp[n-1][i]==1){
                ans=i;
                break;
            }
        }
        System.out.println(ans);

    }

}

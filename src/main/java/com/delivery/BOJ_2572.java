package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class BOJ_2572 {
    static int n;
    static ArrayList<Character> v=new ArrayList<>();
    static int m,k;
    static int dp[][]=new int [1000+1][500+1];
    static ArrayList<Pair> p=new ArrayList<>();
    static class Pair{
        int a;
        int b;
        char c;
        public Pair(int a, int b, char c){
            this.a=a;
            this.b=b;
            this.c=c;
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        for(int i=0;i<n;++i){
            char c;
            c=sc.next().charAt(0);
            v.add(c);
        }
        m=sc.nextInt();
        k=sc.nextInt();
        for(int i=0;i<k;++i){
            int a,b;
            a=sc.nextInt();
            b=sc.nextInt();
            char c;
            c=sc.next().charAt(0);
            p.add(new Pair(a,b,c));
        }
        for(int i=0;i<=n;++i){
            for(int j=0;j<=m;++j){
                dp[i][j]=-2023101800;
            }
        }
        dp[0][1]=0;
        for(int i=1;i<=n;++i){
            for(int j=0;j<k;++j){
                int a=p.get(j).a;
                int b=p.get(j).b;
                char c=p.get(j).c;
                // i번째 턴에 j번째 간선을 탔을 때
                int cnt=0;
                if(c==v.get(i-1)){
                    ++cnt;
                }
                dp[i][b]=Math.max(dp[i-1][a]+cnt*10,dp[i][b]);
                dp[i][a]=Math.max(dp[i-1][b]+cnt*10,dp[i][a]);
            }
        }
        int ans=0;
        for(int i=0;i<=n;++i){
            for(int j=0;j<=m;++j){
                ans=Math.max(ans,dp[i][j]);
            }
        }
        System.out.println(ans);
    }

}

package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Scanner;

public class BOJ_13707 {
    static int n,k;
    static int cache[][]=new int[5000+2][5000+2];
    static int mod=1000000000;


    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        k=sc.nextInt();
        for(int i=0;i<=n;++i){
            cache[i][1]=1;
        }
        for(int i=1;i<=k;++i){
            cache[0][i]=1;
        }
        cache[0][0]=0;
        for(int i=1;i<=n;++i){
            for(int j=2;j<=k;++j){
                cache[i][j]=cache[i][j-1]%mod+cache[i-1][j]%mod;
                cache[i][j]%=mod;
            }
        }
        System.out.println(cache[n][k]);

    }

}

package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class BOJ_5546 {
    static int n,k;
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        k=sc.nextInt();
        int v[]=new int[n+1];
        int dp[][][]=new int[n+1][3+1][2+1];
        for(int i=0;i<k;++i){
            int a=sc.nextInt();
            int b=sc.nextInt();
            v[a]=b;
        }
        int mod=10000;
        int idx=0;
        for(int i=1;i<=n;++i){
            if(v[i]==0){
                idx=i;
                if(i<=2){
                    for(int j=1;j<=3;++j){
                        if(j==v[i-1]){
                            dp[i][j][1]=1;
                        }else{
                            dp[i][j][0]=1;
                        }
                    }
                }else{
                    for(int j=1;j<=3;++j){
                        if(v[i-1]==j && v[i-1]==v[i-2]) continue;
                        if(j==v[i-1]){
                            dp[i][j][1]=1;
                        }else{
                            dp[i][j][0]=1;
                        }
                    }
                }
                break;
            }
        }
        for(int i=idx+1;i<=n;++i){
            if(v[i]==0){
                for(int j=1;j<=3;++j){
                    // dp[i][j][0]
                    for(int k=1;k<=3;++k){
                        if(j==k) continue;
                        for(int p=0;p<=1;++p){
                            dp[i][j][0]+=dp[i-1][k][p]%mod;
                            dp[i][j][0]%=mod;
                        }
                    }
                    // dp[i][j][1]
                    dp[i][j][1]=dp[i-1][j][0];
                }
            }else{
                // dp[i][v[i]][0], dp[i][v[i]][1]
                for(int j=1;j<=3;++j){
                    if(v[i]==j) continue;
                    for(int k=0;k<2;++k){
                        dp[i][v[i]][0]+=dp[i-1][j][k]%mod;
                        dp[i][v[i]][0]%=mod;
                    }

                }
                dp[i][v[i]][1]=dp[i-1][v[i]][0];
            }

        }
//        for(int i=1;i<=n;++i){
//            for(int j=1;j<=3;++j){
//                for(int k=0;k<2;++k){
//                    System.out.println(i+" "+j+" "+k+" "+dp[i][j][k]);
//                }
//            }
//        }
        long ans=0;
        for(int i=1;i<=3;++i){
            for(int j=0;j<2;++j){
                ans+=dp[n][i][j]%mod;
                ans%=mod;
            }
        }
        System.out.println(ans);
    }

}

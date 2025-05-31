package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class BOJ_1245 {

    static int n,m;
    static int board[][],visited[][];
    static int ans=0;
    static boolean flag=true;
    static int dy[]={-1,-1,-1,0,0,1,1,1};
    static int dx[]={-1,0,1,-1,1,-1,0,1};
    static boolean isRange(int y, int x){
        return (y>=0 && x>=0 && y<n && x<m);
    }
    static void dfs(int y, int x, int cur_num){
        for(int i=0;i<8;++i){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!isRange(ny,nx)) continue;
            if(board[ny][nx]>cur_num){
                flag=true;
            }
        }
        for(int i=0;i<8;++i){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!isRange(ny,nx)) continue;
            if(visited[ny][nx]==1) continue;
            if(board[ny][nx]==cur_num){
                visited[ny][nx]=1;
                dfs(ny,nx,cur_num);
            }
        }
    }
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        m=sc.nextInt();
        board=new int[n+1][m+1];
        visited=new int[n+1][m+1];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                board[i][j]=sc.nextInt();
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(visited[i][j]==1) continue;
                if(board[i][j]==0) continue;
                flag=false;
                visited[i][j]=1;
                dfs(i,j,board[i][j]);
                if(flag==false){
//                    System.out.println(i+" "+j);
                    ++ans;
                }
            }
        }
        System.out.println(ans);

    }

}

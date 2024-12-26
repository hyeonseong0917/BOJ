package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_13565 {
    static StringBuilder sb=new StringBuilder();
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static int m,n;
    static String board[];
    static boolean visited[][];
    static int dy[]={-1,0,1,0};
    static int dx[]={0,-1,0,1};
    public static void main(String[] args) throws IOException {
        Input();
        Solve();
    }
    static void Input() throws IOException{
        String fstLine=br.readLine();
        String fstSplit[]=fstLine.split(" ");
        m=Integer.parseInt(fstSplit[0]);
        n=Integer.parseInt(fstSplit[1]);
        board=new String[m];
        visited=new boolean[m][n];
        for(int i=0;i<m;++i){
            String curLine=br.readLine();
            board[i]=curLine;
        }
    }
    static boolean isRange(int y, int x){
        return (y>=0 && x>=0 && y<m && x<n);
    }
    static boolean flag=false;
    static void dfs(int y, int x){
        if(y==m-1){
            flag=true;
            return;
        }
        for(int i=0;i<4;++i){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!isRange(ny,nx) || visited[ny][nx] || board[ny].charAt(nx)=='1') continue;
            visited[ny][nx]=true;
            dfs(ny,nx);
        }
    }
    static void Solve(){
        for(int i=0;i<n;++i){
            if(!visited[0][i] && board[0].charAt(i)=='0'){
                visited[0][i]=true;
                dfs(0,i);
            }
        }
        if(flag){
            sb.append("YES");
        }else{
            sb.append("NO");
        }
        System.out.println(sb);
    }
}

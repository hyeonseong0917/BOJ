package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_3184 {
    static StringBuilder sb=new StringBuilder();
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static int r,c;
    static String [] board;
    static int totalWolf=0, totalSheep=0;
    static int curWolf=0, curSheep=0;
    static int[] dy={-1,0,1,0};
    static int[] dx={0,1,0,-1};
    static boolean visited[][];
    public static void main(String[] args) throws IOException {
        Input();
        Solve();
        printAnswer();
    }
    static void Input() throws IOException{
        String fstLine=br.readLine();
        String [] fstSplit=fstLine.split(" ");
        r=Integer.parseInt(fstSplit[0]);
        c=Integer.parseInt(fstSplit[1]);
        visited=new boolean[r][c];
        board=new String[r];
        for(int i=0;i<r;++i){
            String boardLine=br.readLine();
            board[i]=boardLine;
        }
        br.close();
    }
    static Boolean isRange(int y, int x){
        return (y>=0 && x>=0 && y<r && x<c);
    }
    static void printAnswer(){
        System.out.println(sb);
    }
    static void dfs(int y, int x){
        for(int i=0;i<4;++i){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!isRange(ny,nx)) continue;
            if(board[ny].charAt(nx)=='#') continue;
            if(visited[ny][nx]) continue;
            if(board[ny].charAt(nx)=='o') ++curSheep;
            if(board[ny].charAt(nx)=='v') ++curWolf;
            visited[ny][nx]=true;
            dfs(ny,nx);
        }
    }
    static void Solve(){
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(board[i].charAt(j)=='#') continue;
                if(!visited[i][j]){
                    curWolf=0;
                    curSheep=0;
                    if(board[i].charAt(j)=='o') ++curSheep;
                    if(board[i].charAt(j)=='v') ++curWolf;
                    visited[i][j]=true;
                    dfs(i,j);
                    if(curSheep>curWolf){
                        totalSheep+=curSheep;
                    }else{
                        totalWolf+=curWolf;
                    }
                }
            }
        }
        sb.append(totalSheep).append(" ").append(totalWolf);
    }
}

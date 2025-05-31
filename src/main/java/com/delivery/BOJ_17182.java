package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class BOJ_17182 {


    static int n,m;
    static int board[][];
    static int dist[][];
    static class Pair implements Comparable<Pair>{
        int cost;
        int pos;
        public Pair(int cost, int pos){
            this.cost=cost;
            this.pos=pos;
        }
        @Override
        public int compareTo(Pair other){
            return Integer.compare(this.cost,other.cost);
        }
    }
    static int dijkstra(int y, int x){
        int dp[]=new int[n+1];
        for(int i=0;i<n;++i){
            dp[i]=2023101800;
        }
        dp[y]=0;
        // y에서 x까지 최단거리로 가는법
        PriorityQueue<Pair> pq=new PriorityQueue<>();
        pq.add(new Pair(0,y));
        while(!pq.isEmpty()){
            Pair cur_pair=pq.poll();
            int cur_cost=cur_pair.cost;
            int cur_pos=cur_pair.pos;
            for(int i=0;i<n;++i){
                if(i==cur_pos) continue;
                int next_cost=board[cur_pos][i];
                if(dp[i]>next_cost+dp[cur_pos]){
                    dp[i]=next_cost+dp[cur_pos];
                    pq.add(new Pair(dp[i],i));
                }
            }
        }
        return dp[x];
    }
    static ArrayList<Integer> v=new ArrayList<>();
    static int ans=2023101800;
    static boolean visited[];

    static void dfs(){
        int vs=v.size();
        if(vs==n){
            int sum=0;
            for(int i=1;i<n;++i){
                sum+=dist[v.get(i-1)][v.get(i)];
            }
            ans=Math.min(ans,sum);
            return;
        }
        for(int i=0;i<n;++i){
            if(!visited[i]){
                visited[i]=true;
                v.add(i);
                dfs();
                visited[i]=false;
                v.remove(vs);
            }
        }
    }
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        m=sc.nextInt();
        board=new int[n+1][n+1];
        dist=new int[n+1][n+1];
        visited=new boolean[n+1];
        v.add(m);
        visited[m]=true;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                board[i][j]=sc.nextInt();
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i==j) continue;
                // i에서 j까지 최단거리로 가는법
                dist[i][j]=dijkstra(i,j);
            }
        }
        dfs();
        System.out.println(ans);

    }

}

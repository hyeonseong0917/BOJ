package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_10268 {
//    static class Pair implements Comparable<Pair>{
//        int val;
//        int idx;
//        public Pair(int val, int idx){
//            this.val=val;
//            this.idx=idx;
//        }
//        @Override
//        public int compareTo(Pair other){
//            return Integer.compare(this.val,other.val);
//        }
//
//    }
    static int n,m,a,b,c;
    static class Pair{
        int pos;
        int dist;
        public Pair(int pos, int dist){
            this.pos=pos;
            this.dist=dist;
        }
    }
    static ArrayList<ArrayList<Pair>> v=new ArrayList<>();
    static int dist[]=new int[10+1]; // dist[x]: a에서 x까지 갔을 떄의 총 비용
    static class DistPos implements Comparable<DistPos>{
        int dist;
        int pos;
        public DistPos(int dist, int pos){
            this.dist=dist;
            this.pos=pos;
        }
        @Override
        public int compareTo(DistPos other){
            return Integer.compare(this.dist,other.dist);
        }
    }
    static int ans=2023101800;
    static boolean visited[]=new boolean[10+1];
    static void dfs(int cur_pos, int max_cost, int cur_dist){
        if(cur_dist>c){
            return;
        }
        if(cur_pos==b){
            ans=Math.min(ans,max_cost);
            return;
        }
        for(int i=0;i<v.get(cur_pos).size();++i){
            int next_pos=v.get(cur_pos).get(i).pos;
            int next_dist=v.get(cur_pos).get(i).dist;
            if(!visited[next_pos]){
                visited[next_pos]=true;
                dfs(next_pos,Math.max(max_cost,next_dist),cur_dist+next_dist);
                visited[next_pos]=false;
            }
        }
    }
    static PriorityQueue<DistPos> pq=new PriorityQueue<>();
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        m=sc.nextInt();
        a=sc.nextInt();
        b=sc.nextInt();
        c=sc.nextInt();
        for(int i=0;i<=n;++i){
            v.add(new ArrayList<Pair>());
            dist[i]=2023101800;
        }
        for(int i=0;i<m;++i){
            int x=sc.nextInt();
            int y=sc.nextInt();
            int z=sc.nextInt();
            v.get(x).add(new Pair(y,z));
            v.get(y).add(new Pair(x,z));
        }
        dfs(a,0,0);
        if(ans==2023101800){
            System.out.println(-1);
        }else{
            System.out.println(ans);
        }

    }

}

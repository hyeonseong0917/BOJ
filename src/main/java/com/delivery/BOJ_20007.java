package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class BOJ_20007 {
    static class Pair{
        int cur_pos;
        int cur_dist;
        public Pair(int cur_pos, int cur_dist){
            this.cur_pos=cur_pos;
            this.cur_dist=cur_dist;
        }
    }
    static class DistPos implements Comparable<DistPos> {
        int cur_dist;
        int cur_pos;
        public DistPos(int cur_dist, int cur_pos){
            this.cur_dist=cur_dist;
            this.cur_pos=cur_pos;
        }
        @Override
        public int compareTo(DistPos other){
            return Integer.compare(this.cur_dist,other.cur_dist);
        }
    }
    static int n,m,x,y;
    static ArrayList<ArrayList<Pair>> v=new ArrayList<>();
    static int total_dist[];
    static void Dijkstra(int start){
        total_dist[start]=0;
        PriorityQueue<DistPos> pq=new PriorityQueue<>();
        pq.add(new DistPos(0,start));
        while(!pq.isEmpty()){
            DistPos distPos=pq.poll();
            int cur_dist=distPos.cur_dist;
            int cur_pos=distPos.cur_pos;
            for(int i=0;i<v.get(cur_pos).size();++i){
                int next_pos=v.get(cur_pos).get(i).cur_pos;
                int next_dist=v.get(cur_pos).get(i).cur_dist;
                if(total_dist[next_pos]>total_dist[cur_pos]+next_dist){
                    total_dist[next_pos]=total_dist[cur_pos]+next_dist;
                    pq.add(new DistPos(total_dist[next_pos],next_pos));
                }
            }
        }
    }
    static class DistHouse implements Comparable<DistHouse>{
        int dist;
        int house;
        public DistHouse(int dist, int house){
            this.dist=dist;
            this.house=house;
        }
        @Override
        public int compareTo(DistHouse other){
            return Integer.compare(this.dist,other.dist);
        }
    }
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        m=sc.nextInt();
        x=sc.nextInt();
        y=sc.nextInt();
        total_dist=new int[n+1];
        for(int i=0;i<n;++i){
            ArrayList<Pair> c=new ArrayList<>();
            v.add(c);
            total_dist[i]=2023101800;
        }
        for(int i=0;i<m;++i){
            int a,b,c;
            a=sc.nextInt();
            b=sc.nextInt();
            c=sc.nextInt();
            v.get(a).add(new Pair(b,c));
            v.get(b).add(new Pair(a,c));
        }
        Dijkstra(y);
        boolean flag=false;
        for(int i=0;i<n;++i){
            if(total_dist[i]==2023101800 || total_dist[i]*2>x){
                flag=true;
                break;
            }
        }
        if(flag){
            System.out.println(-1);
        }else{
            ArrayList<DistHouse> arr=new ArrayList<>();
            for(int i=0;i<n;++i){
                arr.add(new DistHouse(total_dist[i],i));
//                System.out.println(i+" "+total_dist[i]);
            }
            Collections.sort(arr);
            int idx=0;
            int sum=0;
            int ans=1;
            while(idx<n){
                if(sum+arr.get(idx).dist*2>x){
                    sum=0;
                    ++ans;
                }else{
                    sum+=arr.get(idx).dist*2;
                    ++idx;
                }
            }
            System.out.println(ans);
        }
    }

}

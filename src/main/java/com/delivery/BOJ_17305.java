package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class BOJ_17305 {
    static int n,w;
    static long sum=0;
    static PriorityQueue<Candy> pq=new PriorityQueue<>();
    static ArrayList<Integer> fst_v=new ArrayList<>();
    static ArrayList<Integer> sed_v=new ArrayList<>();
    static class Candy implements Comparable<Candy> {
        int w; // 무게
        int s; // 가치

        public Candy(int w, int s) {
            this.w = w;
            this.s = s;
        }

        @Override
        public int compareTo(Candy other) {
            if (this.s == other.s) {
                return Integer.compare(other.w, this.w);
            }
            return Integer.compare(this.s, other.s);
        }
    }
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        w=sc.nextInt();
        for(int i=0;i<n;++i){
            int a,b;
            a=sc.nextInt();
            b=sc.nextInt();
            if(a==3){
                fst_v.add(b);
            }else{
                sed_v.add(b);
            }
        }
        Collections.sort(fst_v,Collections.reverseOrder());
        Collections.sort(sed_v,Collections.reverseOrder());
        int cur_w=0;
        long cur_sum=0;
        long ans=0;
        for(int i=0;i<fst_v.size();++i){
            if(cur_w+3>w){
                break;
            }
            cur_w+=3;
            cur_sum+=fst_v.get(i);
            pq.add(new Candy(3*-1,fst_v.get(i)));
        }
        int idx=-1;
        for(int i=0;i<sed_v.size();++i){
            if(cur_w+5>w){
                idx=i;
                break;
            }
            cur_w+=5;
            cur_sum+=sed_v.get(i);
            pq.add(new Candy(5*-1,sed_v.get(i)));
        }
        if(idx==-1){
            System.out.println(cur_sum);
        }else{
//            System.out.println(cur_sum);
            while(idx<sed_v.size() && !pq.isEmpty()){
                ans=Math.max(ans,cur_sum);
                Candy cur_pair=pq.poll();
                int cw=cur_pair.w*-1;
                int cn=cur_pair.s;
//                System.out.println(cw+" "+cn);
//                if(cn>=sed_v.get(idx)){
//                    break;
//                }
                if(cur_w-cw+5>w){
                    cur_w-=cw;
                    cur_sum-=cn;
                    continue;
                }
                cur_w+=5-cw;
                cur_sum+=sed_v.get(idx)-cn;
                ++idx;
            }
            ans=Math.max(ans,cur_sum);
            System.out.println(ans);
        }
    }

}

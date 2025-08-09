package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_2961 {
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
    static int n;
    static ArrayList<Spicy> v=new ArrayList<>();
    static ArrayList<Integer> tmp=new ArrayList<>();
    static int ans=2023101800;
    static boolean visited[]=new boolean[10+1];
    static void pick(int idx, int max_size){
        if(tmp.size()==max_size){
            int a=1, b=0;
            for(int i=0;i<max_size;++i){
                a*=v.get(tmp.get(i)).a;
                b+=v.get(tmp.get(i)).b;
            }
            ans=Math.min(ans,Math.abs(a-b));
            return;
        }
        for(int i=idx;i<n;++i){
            if(!visited[i]){
                visited[i]=true;
                tmp.add(i);
                int ts=tmp.size();
                pick(i+1,max_size);
                tmp.remove(ts-1);
                visited[i]=false;
            }
        }
    }
    static class Spicy implements Comparable<Spicy>{
        int a;
        int b;
        public Spicy(int a, int b){
            this.a=a;
            this.b=b;
        }
        @Override
        public int compareTo(Spicy other){
            return Integer.compare(this.a,other.a);
        }
    }
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        for(int i=0;i<n;++i) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            v.add(new Spicy(a, b));
        }

        for(int i=1;i<=n;++i){
            // i개를 사용했을 때
            tmp.clear();
            for(int j=0;j<n;++j){
                visited[j]=false;
            }
            pick(0,i);
        }
        System.out.println(ans);
    }

}

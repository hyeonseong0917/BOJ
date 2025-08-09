package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_15666 {
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
    static int n,m;
    static ArrayList<Integer> v=new ArrayList<>();
    static ArrayList<Integer> tmp=new ArrayList<>();
    static int ans=0;
    static Map<ArrayList<Integer>,Integer> check=new HashMap<>();
    static void pick(int idx){
        if(tmp.size()==m){
            if(check.containsKey(tmp)){
                return;
            }
            check.put(tmp,1);
//            ++ans;
            for(int i=0;i<m;++i){
                System.out.print(tmp.get(i));
                if(i==m-1){
                    System.out.println();
                }else{
                    System.out.print(" ");
                }
            }
            return;
        }
        if(idx==n){
            return;
        }
        for(int i=idx;i<n;++i){

            tmp.add(v.get(i));
            pick(i);
            int ts=tmp.size();
            tmp.remove(ts-1);
            pick(i+1);
        }
    }
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        m=sc.nextInt();
//        v=new ArrayList<>();

        for(int i=0;i<n;++i){
            int a;
            a=sc.nextInt();
            v.add(a);
        }
        Collections.sort(v);
        pick(0);
//        System.out.println(ans);
    }

}

package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_20363 {
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
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        int x,y;
        x=sc.nextInt();
        y=sc.nextInt();
        // 100 200
        // 0 200
        // 100 190
        // 99 200
        int tx=x;
        int ty=y;
        x=Math.min(tx,ty);
        y=Math.max(tx,ty);
        int a=0, b=0;
        int ans=0;
        ans=x+y+x/10;
        System.out.println(ans);
    }

}

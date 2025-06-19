package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_21314 {
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
        String s;
        s=sc.next();
        int n=s.length();
//        System.out.println(s);
        // 가장 큰 값 구하기
        // 10^n: n+1개의 m
        // 5*10^n: n개의 m, 1개의 k
        // 가장 큰 값
        String max_val="";
        int idx=0;
        // MMMMMMMK: 무조건 5000000
        // K앞에 M있다면 5000으로
        while(idx<n){
            if(s.charAt(idx)=='K'){
                max_val+='5';
                ++idx;
            }else{
                // 이 뒤에 K가 있는지??
                int flag=-1;
                for(int i=idx;i<n;++i){
                    if(s.charAt(i)=='K'){
                        flag=i;
                        break;
                    }
                }
//                System.out.println(flag);
                if(flag==-1){
                    // K가 없음
                    while(idx<n){
                        max_val+='1';
                        ++idx;
                    }
                }else{
                    max_val+='5';
                    int cnt=flag-idx;
                    for(int i=0;i<cnt;++i){
                        max_val+='0';
                    }
                    idx=flag+1;
                }
            }
        }

        // 가장 작은 값
        // MMM이어진거는 무조건 100000..
        // K는 무조건 단일 5
        String min_val="";
        idx=0;
        while(idx<n){
            if(s.charAt(idx)=='K'){
                min_val+='5';
                ++idx;
            }else{
                int cnt=0;
                ++idx;
                while(idx<n){
                    if(s.charAt(idx)=='M'){
                        ++cnt;
                        ++idx;
                    }else{
                        break;
                    }
                }
                min_val+='1';
                for(int i=0;i<cnt;++i){
                    min_val+='0';
                }
            }
        }
        System.out.println(max_val);
        System.out.println(min_val);

    }

}

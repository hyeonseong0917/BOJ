package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_27497 {

    static class Pair{
        int cnt;
        char c;
        public Pair(int cnt, char c){
            this.cnt=cnt;
            this.c=c;
        }
    }
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        Deque<Pair> dq=new ArrayDeque<>();

        int cnt=0;
        for(int i=0;i<n;++i){
            int a=sc.nextInt();
            int ds=dq.size();
//            System.out.println(ds+" "+i);
            if(a==3){
                if(!dq.isEmpty()){
                    Pair firstPair=dq.peekFirst();
                    Pair sedPair=dq.peekLast();
                    if(firstPair.cnt<=sedPair.cnt){
                        dq.removeLast();
                    }else{
                        dq.removeFirst();
                    }
                }
            }else{
                char c=sc.next().charAt(0);
                if(a==1){
                    dq.addLast(new Pair(cnt,c));
                }else{
                    dq.addFirst(new Pair(cnt,c));
                }
                ++cnt;
            }
        }
        if(dq.isEmpty()){
            System.out.println(0);
        }else{
            StringBuilder ans = new StringBuilder();
            while (!dq.isEmpty()) {
                ans.append(dq.pollFirst().c);  // O(1) per operation
            }
            System.out.println(ans.toString());
        }
    }

}

package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_2300 {
    static int n;
    static ArrayList<Pos> v;
    static int[] dp;
    static class Pos{
        int x;
        int y;
        public Pos(int x, int y){
            this.x=x;
            this.y=y;
        }
    }
    static class Comp implements Comparator<Pos> {
        @Override
        public int compare(Pos a, Pos b){
            if(a.x==b.x){
                return a.y-b.y;
            }
            return a.x-b.x;
        }
    }
    public static void main(String[] args) throws IOException {
        StringBuilder sb=new StringBuilder();
//        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        v=new ArrayList<>();
        dp=new int[n+1];
        for(int i=0;i<n;++i){
            Pos pos=new Pos(0,0);
            pos.x=sc.nextInt();
            pos.y=sc.nextInt();
            v.add(pos);
        }
        Collections.sort(v,new Comp());
        for(int i=0;i<n;++i){
            dp[i]=2023101800;
        }

//        Scanner sc=new Scanner(System.in);
//        StringBuilder sb=new StringBuilder();
//        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
//        int n=Integer.parseInt(br.readLine());
//        Stack<Integer> st=new Stack<>();
//        for(int i=0;i<n;++i){
//            String a=br.readLine();
//            if(a.charAt(0)=='1'){
//                st.push(Integer.parseInt(a.substring(2)));
//            }else{
//                if(a.charAt(0)=='2'){
//                    if(st.empty()){
//                        sb.append(-1).append("\n");
//                    }else{
//                        int curNum=st.peek();
//                        st.pop();
//                        sb.append(curNum).append("\n");
//                    }
//                }else if(a.charAt(0)=='3'){
//                    if(st.empty()){
//                        sb.append(0).append("\n");
//                    }else{
//                        int curSize=st.size();
//                        sb.append(curSize).append("\n");
//                    }
//                }else if(a.charAt(0)=='4'){
//                    if(st.empty()){
//                        sb.append(1).append("\n");
//                    }else{
//                        sb.append(0).append("\n");
//                    }
//                }else{
//                    if(st.empty()){
//                        sb.append(-1).append("\n");
//                    }else{
//                        int curNum=st.peek();
//                        sb.append(curNum).append("\n");
//                    }
//                }
//            }
//        }
//        br.close();
//        System.out.println(sb);
    }
}

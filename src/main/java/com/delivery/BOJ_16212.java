package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Stack;

public class BOJ_16212 {
    public static void main(String[] args) throws IOException {
        StringBuilder sb=new StringBuilder();
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        String a=br.readLine();
        ArrayList<Integer> v=new ArrayList<>();
        String tmp="";
        for(int i=0;i<a.length();++i){
            if(a.charAt(i)==' '){
                v.add(Integer.parseInt(tmp));
                tmp="";
            }else{
                tmp+=a.charAt(i);
            }
        }
        v.add(Integer.parseInt(tmp));
        Collections.sort(v);
        for(int i=0;i<v.size();++i){
            sb.append(v.get(i)).append(" ");
        }
        br.close();
        System.out.println(sb);

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

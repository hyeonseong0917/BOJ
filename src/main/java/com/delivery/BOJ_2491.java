package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_2491 {
    static int n;
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        ArrayList<Integer> v=new ArrayList<>();
        for(int i=0;i<n;++i){
            int a=sc.nextInt();
            v.add(a);
        }
        int ans=1;
        int fst_num=1;
        int sed_num=1;
        for(int i=1;i<n;++i){
            if(v.get(i)>=v.get(i-1)){
                ++fst_num;
            }else{
                ans=Math.max(ans,fst_num);
                fst_num=1;
            }
        }
        ans=Math.max(ans,fst_num);
        for(int i=1;i<n;++i){
            if(v.get(i)<=v.get(i-1)){
                ++sed_num;
            }else{
                ans=Math.max(ans,sed_num);
                sed_num=1;
            }
        }
        ans=Math.max(ans,sed_num);
        System.out.println(ans);
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

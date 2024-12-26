package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class BOJ_1431 {
    static StringBuilder sb=new StringBuilder();
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static int n;
    static ArrayList<String> arr=new ArrayList<>();
    public static void main(String[] args) throws IOException {
        Input();
        Solve();
        for(int i=0;i<arr.size();++i){
            sb.append(arr.get(i)).append("\n");
        }
        System.out.println(sb);
    }

    static void Input() throws IOException{
        n=Integer.parseInt(br.readLine());
        for(int i=0;i<n;++i){
            String s=br.readLine();
            arr.add(s);
        }
    }
    static void Solve(){
        Collections.sort(arr, new Comparator<String>(){
            @Override
            public int compare(String a, String b){
                if(a.length()==b.length()){
                    int aSum=0, bSum=0;
                    for(int i=0;i<a.length();++i){
                        if(!('A'<=a.charAt(i) && a.charAt(i)<='Z')){
                            aSum+=(a.charAt(i)-'0');
                        }
                        if(!('A'<=b.charAt(i) && b.charAt(i)<='Z')){
                            bSum+=(b.charAt(i)-'0');
                        }
                    }
                    if(aSum==bSum){
                        for(int i=0;i<a.length();++i){
                            if(a.charAt(i)!=b.charAt(i)){
                                return a.charAt(i)-b.charAt(i);
                            }
                        }
                    }
                    return aSum-bSum;
                }
                return a.length()-b.length();
            }
        });
    }
}

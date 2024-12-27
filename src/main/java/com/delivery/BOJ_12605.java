package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class BOJ_12605 {
    static StringBuilder sb=new StringBuilder();
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static int n;
    public static void main(String[] args) throws IOException {
        Input();
        Solve();
    }
    static ArrayList<String> v=new ArrayList<>();
    static void Input() throws IOException{
        n=Integer.parseInt(br.readLine());
        for(int i=0;i<n;++i){
            v.clear();
            String splitedLine[]=br.readLine().split(" ");
            for(int j=0;j<splitedLine.length;++j){
                v.add(splitedLine[j]);
            }
            Collections.reverse(v);
            String tmp="Case #" + (i+1) + ": ";
            for(int j=0;j<v.size();++j){
                tmp+=v.get(j);
                if(j!=v.size()-1){
                    tmp+=" ";
                }
            }
            sb.append(tmp);
            sb.append("\n");
        }
        System.out.println(sb);
    }
    static void Solve(){

    }
}

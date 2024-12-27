package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class BOJ_26148 {
    static StringBuilder sb=new StringBuilder();
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static int n,d;
    public static void main(String[] args) throws IOException {
        Input();
        Solve();
    }
    static void Input() throws IOException{
        n=Integer.parseInt(br.readLine());
        d=Integer.parseInt(br.readLine());
    }
    static int febLastDay=28;
    static void Solve(){
        if((n%4==0 && n%100!=0) || n%400==0){
            febLastDay=29;
        }
        int curMonth=1;
        int curDate=1;
        int curDay=n%7;
        int ans=0;
        HashMap<Integer, Integer> m=new HashMap<>();
        while(curMonth<=12){
            if(m.containsKey(curDay%7)){
                m.put(curDay%7,m.get(curDay%7)+1);
            }else{
                m.put(curDay%7,1);
            }
            ++curDate;
            ++curDay;
            if(isFinishMonth(curMonth, curDate)){
                ++curMonth;
                for(int i=0;i<7;++i){
                    if(m.get(i)==5){
                        ++ans;
                    }
                }
                m.clear();
                curDate=1;
            }

        }
        System.out.println(ans);
    }
    static boolean isFinishMonth(int curMonth, int curDate){
        if(curDate==febLastDay+1 && curMonth==2){
            return true;
        }
        if(curDate==31 && (curMonth==4 || curMonth==6 || curMonth==9 || curMonth==11)){
            return true;
        }
        if(curDate==32){
            return true;
        }
        return false;
    }
}

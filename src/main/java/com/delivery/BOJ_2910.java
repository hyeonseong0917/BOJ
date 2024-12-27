package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;

public class BOJ_2910 {
    static StringBuilder sb=new StringBuilder();
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static int n,c;
    static ArrayList<Integer> arr=new ArrayList<>();
    static HashMap<Integer, Integer> m=new HashMap<>();
    static ArrayList<Order> distArr=new ArrayList<>();
    static class Pair{
        int value;
        int cnt;
        int order;
        public Pair(int value, int cnt, int order){
            this.value=value;
            this.cnt=cnt;
            this.order=order;
        }
    }
    static class Order{
        int value;
        int order;
        public Order(int value, int order){
            this.value=value;
            this.order=order;
        }
    }
    static ArrayList<Pair> v=new ArrayList<>();
    public static void main(String[] args) throws IOException {
        Input();
        Solve();
    }

    static void Input() throws IOException{
        String fstLine=br.readLine();
        String fstSplit[]=fstLine.split(" ");
        n=Integer.parseInt(fstSplit[0]);
        c=Integer.parseInt(fstSplit[1]);
        String sedSplit[]=br.readLine().split(" ");
        for(int i=0;i<n;++i){
            int curNum=Integer.parseInt(sedSplit[i]);
            arr.add(curNum);
        }
    }
    static void Solve(){
        for(int i=0;i<n;++i){
            int curNum=arr.get(i);
            if(m.containsKey(curNum)){
                m.put(curNum,m.get(curNum)+1);
            }else{
                distArr.add(new Order(curNum,i));
                m.put(curNum,1);
            }
        }
        for(int i=0;i<distArr.size();++i){
            int curNum=distArr.get(i).value;
            int curOrder=distArr.get(i).order;
            int curCnt=m.get(curNum);
            v.add(new Pair(curNum,curCnt,curOrder));
        }
        Collections.sort(v,new Comp());
        for(int i=0;i<v.size();++i){
            int curCnt=v.get(i).cnt;
            for(int j=0;j<curCnt;++j){
                sb.append(v.get(i).value).append(" ");
            }
        }
        System.out.println(sb);
    }
    static class Comp implements Comparator<Pair> {
        @Override
        public int compare(Pair a, Pair b){
            if(a.cnt==b.cnt){
                return a.order-b.order;
            }
            return b.cnt-a.cnt;
        }
    }
}

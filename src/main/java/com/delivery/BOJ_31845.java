package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_31845 {
    static class Pair implements Comparable<Pair>{
        int val;
        int idx;
        public Pair(int val, int idx){
            this.val=val;
            this.idx=idx;
        }
        @Override
        public int compareTo(Pair other){
            return Integer.compare(this.val,other.val);
        }

    }
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        int n,m;
        n=sc.nextInt();
        m=sc.nextInt();
        ArrayList<Integer> arr=new ArrayList<>();
        for(int i=0;i<n;++i){
            int a=sc.nextInt();
            arr.add(a);
        }
        ArrayList<Pair> v=new ArrayList<>();
        for(int i=0;i<n;++i){
            v.add(new Pair(arr.get(i),i));
        }
        Collections.sort(v);
        int ans=0;
        int cnt=Math.min(m,(n+1)/2);
        // [n-cnt,n-1]
        ArrayList<Integer> tmp=new ArrayList<>();
        for(int i=n-cnt;i<n;++i){
            tmp.add(v.get(i).val);
        }
        int idx=0;
        if(tmp.get(0)<0){
            ++idx;
        }
        for(int i=idx;i<tmp.size();++i){
            ans+=Math.max(tmp.get(i),0);
        }
        System.out.println(ans);
        // m번 수행, 딜러와 플레이어는 각각 1에서 n까지 적힌 카드를 한 장 씩 가지고 있음
        // 딜러: 1,2,3,4,5,..n 그리고 더미 1
        // 플레이어: 1,2,3,4,5...n

    }

}

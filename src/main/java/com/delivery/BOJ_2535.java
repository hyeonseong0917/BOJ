package com.delivery;

import java.util.*;

public class BOJ_2535 {
    static class Score{
        int countryNum;
        int studentNum;
        int grade;
        public Score(int countryNum, int studentNum, int grade){
            this.countryNum=countryNum;
            this.studentNum=studentNum;
            this.grade=grade;
        }
    }
    static class Comp implements Comparator<Score>{
        @Override
        public int compare(Score a, Score b){
            return b.grade-a.grade;
        }
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();

        ArrayList<Score> v=new ArrayList<>();
        for(int i=0;i<N;++i){
            int a,b,c;
            a=sc.nextInt();
            b=sc.nextInt();
            c=sc.nextInt();
            Score score=new Score(a,b,c);
            v.add(score);
        }
        Collections.sort(v,new Comp());
        ArrayList<Score> ans=new ArrayList<>();
        int visited[]=new int[100+1];
        int cnt=0;
        for(int i=0;i<N;++i){
            if(cnt>=3) break;
            int curCountry=v.get(i).countryNum;
            if(visited[curCountry]==2) continue;
            ++cnt;
            ans.add(v.get(i));
            ++visited[v.get(i).countryNum];
        }
        for(int i=0;i<cnt;++i){
            System.out.println(ans.get(i).countryNum + " " + ans.get(i).studentNum);
        }
    }
}

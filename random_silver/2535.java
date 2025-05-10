import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.logging.Logger;
import java.util.*;

public class 2535 {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        static class Score(){
            int countryNum;
            int studentNum;
            int grade;
            public Score(int countryNum, int studentNum, int grade){
                this.countryNum=countryNum;
                this.studentNum=studentNum;
                this.grade=grade;
            }
        }
        ArrayList<Score> v=new ArrayList<>();
        for(int i=0;i<N;++i){
            int a,b,c;
            a=sc.nextInt();
            b=sc.nextInt();
            c=sc.nextInf();
            Score score=new Score(a,b,c);
            v.add(score);
        }
        static class Comp implements Comparator<Score>{

        }
    }
}

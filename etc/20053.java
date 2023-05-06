/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
    static int t,N;
    static ArrayList<Integer> arr=new ArrayList<>();
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        Scanner sc=new Scanner(System.in);
        t=Integer.parseInt(sc.next());
        for(int i=0;i<t;++i){
            N=Integer.parseInt(sc.next());
            int maxNum=-122232421;
            int minNum=122232421;
            for(int j=0;j<N;++j){
                int a=Integer.parseInt(sc.next());
                if(maxNum<a){
                    maxNum=a;
                }
                if(minNum>a){
                    minNum=a;
                }
            }

            System.out.println(minNum + " " + maxNum);

        }
    }
}
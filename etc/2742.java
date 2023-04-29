/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        String s="";
        Scanner sc=new Scanner(System.in);
        s=sc.next();
        int num=Integer.parseInt(s);
        for(int i=num;i>=1;--i){
            System.out.println(i);
        }
        // System.out.print(num);
    }
}
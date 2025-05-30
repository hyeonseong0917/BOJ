package com.delivery;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class BOJ_11536 {


    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        ArrayList<String> v=new ArrayList<>();
        for(int i=0;i<n;++i){
            String s=sc.next();
            v.add(s);
        }
        boolean asc_flag=true;
        boolean desc_flag=true;
        for(int i=0;i<n-1;++i){
            if(v.get(i).compareTo(v.get(i+1))>=0){
                asc_flag=false;
            }
        }
        for(int i=0;i<n-1;++i){
            if(v.get(i).compareTo(v.get(i+1))<=0){
                desc_flag=false;
            }
        }
        if(asc_flag==false && desc_flag==false){
            System.out.println("NEITHER");
        }else{
            if(asc_flag==true){
                System.out.println("INCREASING");
            }else{
                System.out.println("DESCREASING");
            }
        }
    }

}

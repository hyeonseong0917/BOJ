/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class 20291
{
    static int N=0;
    static Map<String, Integer> m=new TreeMap<>();
    static String[] arr=new String[50000+1];
    static void Input(){
        Scanner sc=new Scanner(System.in);
        N=Integer.parseInt(sc.next());
        for(int i=0;i<N;++i){
            String s=sc.next();
            int n=s.indexOf('.')+1;
            s=s.substring(n);
            arr[i]=s;
        }
    }
    static void solve(){
        ArrayList<String> v=new ArrayList<>();
        for(int i=0;i<N;++i){
            String target=arr[i];
            if(m.containsKey(target)==true){
                m.put(target,m.get(target)+1);
            }else{
                m.put(target,1);
                v.add(target);
            }

        }
        for(String key: m.keySet()){
            System.out.println(key+" "+m.get(key));
        }
    }
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        Input();
        solve();
    }
}
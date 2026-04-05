package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static String s;
    static boolean visited[]=new boolean[6];
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        s=st.nextToken();
    }
    static String tmp="";
    static int INF=2023101800;
    static int ans=INF;
    static void dfs(){
        int ts=tmp.length();
        int ss=s.length();
        if(ts==ss){
            int t_num=Integer.parseInt(tmp);
            int s_num=Integer.parseInt(s);
            if(s_num<t_num){
                ans=Math.min(ans,t_num);
            }
            return;
        }
        for(int i=0;i<ss;++i){
            if(visited[i]) continue;
            visited[i]=true;
            tmp+=s.charAt(i);
            int k=tmp.length();
            dfs();
            visited[i]=false;
            tmp=tmp.substring(0,k-1);
        }
    }
    public static void Solve(){
        // s보다 크면서 가장 작은 수?
        dfs();
        if(ans==INF){
            System.out.print(0);
        }else{
            System.out.print(ans);
        }
    }


    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}




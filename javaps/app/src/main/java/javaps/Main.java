package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N,M;
    static ArrayList<ArrayList<Integer>> g=new ArrayList<ArrayList<Integer>>();
    static int check[]=new int[100000+1];
    static int dp[]=new int[100000+1];
    static class CntNum implements Comparable<CntNum>{
        int cnt;
        int num;
        public CntNum(int cnt, int num){
            this.cnt=cnt;
            this.num=num;
        }
        @Override
        public int compareTo(CntNum other){
            return this.cnt-other.cnt;
        }
    }
    static ArrayList<CntNum> v=new ArrayList<>();
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        M=Integer.parseInt(st.nextToken());
        for(int i=0;i<N;++i){
            g.add(new ArrayList<>());
        }
        for(int i=0;i<M;++i){
            st = new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            g.get(a).add(b);
            g.get(b).add(a);
        }
        for(int i=0;i<N;++i){
            int gs=g.get(i).size();
            check[i]=gs;
            v.add(new CntNum(gs,i));
            dp[i]=1;
        }
        Collections.sort(v);
        for(int i=0;i<N;++i){
            int cur_cnt=v.get(i).cnt;
            int cur_num=v.get(i).num;
            for(int j=0;j<g.get(cur_num).size();++j){
                int next_num=g.get(cur_num).get(j);
                int next_cnt=check[next_num];
                if(cur_cnt<next_cnt){
                    if(dp[next_num]<dp[cur_num]+1){
                        dp[next_num]=dp[cur_num]+1;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<N;++i){
            ans=Math.max(ans,dp[i]);
        }
        System.out.println(ans);
    }
    
    public static void Solve(){
            
    }

    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}


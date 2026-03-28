package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N,M;
    static ArrayList<ArrayList<Integer>> v=new ArrayList<ArrayList<Integer>>();
    static ArrayList<ArrayList<Integer>> rv=new ArrayList<ArrayList<Integer>>();
    static int dist[][]=new int[1000+1][1000+1];
    static int dp[][]=new int[1000+1][1000+1];
    static int check[]=new int[1000+1];
    static ArrayList<Integer> arr=new ArrayList<>();
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        M=Integer.parseInt(st.nextToken());
        for(int i=0;i<=N;++i){
            ArrayList<Integer> tmp=new ArrayList<>();
            v.add(tmp);
            rv.add(new ArrayList<Integer>());
            for(int j=0;j<=N;++j){
                dp[i][j]=-1;
            }
        }
        for(int i=0;i<M;++i){
            st = new StringTokenizer(br.readLine());
            int a,b,c;
            a=Integer.parseInt(st.nextToken());
            b=Integer.parseInt(st.nextToken());
            if(a!=1){
                ++check[b];
            }
            c=Integer.parseInt(st.nextToken());
            if(b==1){
                arr.add(a);
            }
            dist[a][b]=c;
            v.get(a).add(b);
            rv.get(b).add(a);
        }
    }
    
    public static void Solve(){
        Queue<Integer> q=new LinkedList<>();
        dp[1][1]=0;
        for(int i=2;i<=N;++i){
            if(check[i]==0){
                q.add(i);
                dp[i][2]=dist[1][i];
            }
        }
        
        while(!q.isEmpty()){
            int cur_num=q.poll();
            for(int i=0;i<v.get(cur_num).size();++i){
                int next_num=v.get(cur_num).get(i);
                if(next_num==1) continue;
                --check[next_num];
                for(int j=2;j<N;++j){
                    if(dp[cur_num][j]==-1) continue;
                    if(dp[next_num][j+1]<dp[cur_num][j]+dist[cur_num][next_num]){
                        dp[next_num][j+1]=dp[cur_num][j]+dist[cur_num][next_num];
                    }
                }
                if(check[next_num]==0){
                    q.add(next_num);
                }
                
            }
        }
        int ans=0;
        for(int i=0;i<arr.size();++i){
            int last_num=arr.get(i);
            for(int j=2;j<=N;++j){
                if(dp[last_num][j]==-1) continue;
                ans=Math.max(ans,dp[last_num][j]+dist[last_num][1]);
            }
        }
        System.out.println(ans);
        ArrayList<Integer> ans_vec=new ArrayList<>();
        int ans_cnt=0;

        for(int i=0;i<arr.size();++i){
            if(!ans_vec.isEmpty()) break;
            int last_num=arr.get(i);
            for(int j=2;j<=N;++j){
                if(!ans_vec.isEmpty()) break;
                if(dp[last_num][j]==-1) continue;
                if(ans==dp[last_num][j]+dist[last_num][1]){
                    ans_vec.add(1);
                    ans_cnt=j;
                    ans_vec.add(last_num);
                    ans-=dist[last_num][1];
                }
            }
        }
        // System.out.println(ans+" "+ans_cnt);
        // // ans_vec에는 1,last_num들어있음
        // 현재 ans_cnt
        while(true){
            int as=ans_vec.size();
            int cur_last_num=ans_vec.get(as-1);
            // System.out.println(cur_last_num);
            if(cur_last_num==1) break;
            for(int i=0;i<rv.get(cur_last_num).size();++i){
                int next_num=rv.get(cur_last_num).get(i);
                if(dp[next_num][ans_cnt-1]+dist[next_num][cur_last_num]==dp[cur_last_num][ans_cnt]){
                    ans_vec.add(next_num);
                    ans_cnt-=1;
                    break;
                }
            }
        }
        Collections.reverse(ans_vec);
        for(int i=0;i<ans_vec.size();++i){
            System.out.print(ans_vec.get(i)+" ");
        }
    }

    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}


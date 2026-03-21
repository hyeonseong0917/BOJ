package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n,m;
    static char board[][]=new char[2000+1][2000+1];
    static int cost[][]=new int[2000+1][2000+1];
    static boolean is_finish[][]=new boolean[2000+1][2000+1];
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        for(int i=0;i<n;++i){
            st = new StringTokenizer(br.readLine());
            String str=st.nextToken();
            for(int j=0;j<str.length();++j){
                is_finish[i][j]=false;
                board[i][j]=str.charAt(j);
                // System.out.println(board[i][j]);
            }
        }
        for(int i=0;i<n;++i){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<m;++j){
                cost[i][j]=Integer.parseInt(st.nextToken());
            }
        }
    }
    static boolean flag=false;
    static class Pos{
        int y;
        int x;
        public Pos(int y, int x){
            this.y=y;
            this.x=x;
        }
    }
    static ArrayList<Pos> v=new ArrayList<>();
    static ArrayList<Pos> p=new ArrayList<>();
    static boolean visited[][]=new boolean[2000+1][2000+1];
    static boolean on_stack[][]=new boolean[2000+1][2000+1];
    static boolean isRange(int y, int x){
        return (y>=0 && x>=0 && y<n && x<m);
    }
    static int dy[]={-1,0,1,0};
    static int dx[]={0,1,0,-1};
    // 사이클이 발생하는 좌표만 모아보기?
    static void dfs(int y, int x){
        if(is_finish[y][x]){
            flag=true;
            return;
        }
        if(visited[y][x]){
            if(on_stack[y][x]){
                v.add(new Pos(y,x));
            }
            return;
        }
        
        visited[y][x]=true;
        on_stack[y][x]=true;
        p.add(new Pos(y,x));
        int d=0;
        if(board[y][x]=='U'){
            d=0;
        }else if(board[y][x]=='R'){
            d=1;
        }else if(board[y][x]=='D'){
            d=2;
        }else{
            d=3;
        }
        int ny=y+dy[d];
        int nx=x+dx[d];
        if(!isRange(ny,nx)){
            flag=true;
            on_stack[y][x]=false;
            return;
        }
        dfs(ny,nx);
        on_stack[y][x]=false;
    }
    static boolean check[][]=new boolean[2000+1][2000+1];
    static int max_num=2023101800;
    static void r_dfs(int y, int x){
        if(check[y][x]) return;
        check[y][x]=true;
        int d=0;
        if(board[y][x]=='U'){
            d=0;
        }else if(board[y][x]=='R'){
            d=1;
        }else if(board[y][x]=='D'){
            d=2;
        }else{
            d=3;
        }
        max_num=Math.min(max_num,cost[y][x]);
        r_dfs(y+dy[d],x+dx[d]);
    }
    static void Solve(){
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                // i,j에서 출발해서 i,j에 도착하는지?
                if(visited[i][j]) continue;
                flag=false;
                p.clear();
                dfs(i,j);
                if(flag==true){
                    for(int k=0;k<p.size();++k){
                        int y=p.get(k).y;
                        int x=p.get(k).x;
                        is_finish[y][x]=true;
                    }
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<v.size();++i){
            int y=v.get(i).y;
            int x=v.get(i).x;
            // System.out.println(y+" "+x);
            if(check[y][x]) continue;
            max_num=2023101800;
            r_dfs(y,x);
            ans+=max_num;
        }
        System.out.print(ans);
    }

    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}


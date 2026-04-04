package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N,M,K;
    static int dy[]={-1,0,1,0};
    static int dx[]={0,1,0,-1};
    static boolean isRange(int y, int x){
        return (y>=0 && x>=0 && y<N && x<M);
    }
    static int board[][]=new int[2000+1][2000+1];
    static int check[][]=new int[2000+1][2000+1];
    static class Pos{
        int d;
        int y;
        int x;
        public Pos(int d, int y, int x){
            this.d=d;
            this.y=y;
            this.x=x;
        }
    }
    static Queue<Pos> q=new LinkedList<>();
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        M=Integer.parseInt(st.nextToken());
        K=Integer.parseInt(st.nextToken());
        for(int i=0;i<N;++i){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<M;++j){
                int a=Integer.parseInt(st.nextToken());
                board[i][j]=a;
                if(a==3){
                    check[i][j]=1;
                    q.add(new Pos(0,i,j));
                }
            }
        }
    }
    static int INF=2023101800;
    static int dist[][]=new int[2000+1][2000+1];
    public static void Solve(){
        while(!q.isEmpty()){
            Pos p=q.poll();
            int d=p.d;
            int y=p.y;
            int x=p.x;
            if(d>K) continue;
            for(int i=0;i<4;++i){
                int ny=y+dy[i];
                int nx=x+dx[i];
                if(!isRange(ny,nx)) continue;
                if(check[ny][nx]==1) continue;
                if(d+1<=K){
                    check[ny][nx]=1;
                    q.add(new Pos(d+1,ny,nx));
                }
                
            }
        }
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                dist[i][j]=INF;
                if(board[i][j]==4){
                    q.add(new Pos(0,i,j));
                    dist[i][j]=0;
                }
            }
        }
        while(!q.isEmpty()){
            Pos p=q.poll();
            int y=p.y;
            int x=p.x;
            for(int i=0;i<4;++i){
                int ny=y+dy[i];
                int nx=x+dx[i];
                if(!isRange(ny,nx)) continue;
                if(check[ny][nx]==1) continue;
                if(board[ny][nx]==1) continue;
                if(dist[ny][nx]>dist[y][x]+1){
                    dist[ny][nx]=dist[y][x]+1;
                    q.add(new Pos(0,ny,nx));
                }
            }
        }
        int ans=INF;
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                if(board[i][j]==2){
                    ans=Math.min(ans,dist[i][j]);
                }
            }
        }
        // for(int i=0;i<N;++i){
        //     for(int j=0;j<M;++j){
        //         System.out.print(check[i][j]+" ");
        //     }System.out.println();
        // }
        if(ans==INF){
            System.out.print(-1);
        }else{
            System.out.print(ans);
        }


    }


    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}




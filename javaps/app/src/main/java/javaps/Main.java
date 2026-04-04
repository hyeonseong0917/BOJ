package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N,M,K;
    static int board[][]=new int[1000+1][1000+1];
    static int dist[][]=new int[1000+1][1000+1];
    static int dy[]={-1,0,1,0};
    static int dx[]={0,1,0,-1};
    static boolean isRange(int y, int x){
        return (y>=0 && x>=0 && y<N && x<M);
    }
    static class Pos implements Comparable<Pos>{
        int d;
        int y;
        int x;
        public Pos(int d, int y, int x){
            this.d=d;
            this.y=y;
            this.x=x;
        }
        @Override
        public int compareTo(Pos other){
            return this.d-other.d;
        }
    }
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
                dist[i][j]=2023101800;
            }
        }
    }
    
    public static void Solve(){
        PriorityQueue<Pos> q=new PriorityQueue<>();
        for(int i=0;i<N;++i){
            q.add(new Pos(board[i][0],i,0));
            dist[i][0]=board[i][0];
        }
        for(int i=0;i<M;++i){
            q.add(new Pos(board[0][i],0,i));
            dist[0][i]=board[0][i];
        }
        for(int i=0;i<N;++i){
            q.add(new Pos(board[i][M-1],i,M-1));
            dist[i][M-1]=board[i][M-1];
        }
        while(!q.isEmpty()){
            Pos p=q.poll();
            int d=p.d;
            int y=p.y;
            int x=p.x;
            for(int i=0;i<4;++i){
                int ny=y+dy[i];
                int nx=x+dx[i];
                if(!isRange(ny,nx)) continue;
                if(dist[ny][nx]>dist[y][x]){
                    dist[ny][nx]=Math.max(board[ny][nx],dist[y][x]);
                    q.add(new Pos(dist[ny][nx],ny,nx));
                }
            }
        }
        // for(int i=0;i<N;++i){
        //     for(int j=0;j<M;++j){
        //         System.out.print(dist[i][j]+" ");
        //     }System.out.println();
        // }
        ArrayList<Integer> v=new ArrayList<>();
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                v.add(dist[i][j]);
            }
        }
        Collections.sort(v);
        int ans=v.get(K-1);
        System.out.println(ans);
    }


    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}


package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N,M,A,B,K;
    static int board[][]=new int[500+1][500+1];
    static class Pos{
        int y;
        int x;
        public Pos(int y, int x){
            this.y=y;
            this.x=x;
        }
    }
    static Pos start_pos;
    static Pos fin_pos;
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        M=Integer.parseInt(st.nextToken());
        A=Integer.parseInt(st.nextToken());
        B=Integer.parseInt(st.nextToken());
        K=Integer.parseInt(st.nextToken());
        int a,b;
        for(int i=0;i<K;++i){
            st = new StringTokenizer(br.readLine());
            a=Integer.parseInt(st.nextToken());
            b=Integer.parseInt(st.nextToken());
            board[a-1][b-1]=1;
        }
        st = new StringTokenizer(br.readLine());
        a=Integer.parseInt(st.nextToken());
        b=Integer.parseInt(st.nextToken());
        start_pos=new Pos(a-1,b-1);

        st = new StringTokenizer(br.readLine());
        a=Integer.parseInt(st.nextToken());
        b=Integer.parseInt(st.nextToken());
        fin_pos=new Pos(a-1,b-1);
    }
    // [y,y+a-1] ~ [x,x+b-1]
    static int dist[][]=new int[500+1][500+1];
    static int dy[]={-1,0,1,0};
    static int dx[]={0,1,0,-1};
    static boolean isRange(int y, int x){
        return (y>=0 && x>=0 && y<N && x<M);
    }
    static void Solve(){
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                dist[i][j]=2023101800;
            }
        }
        dist[start_pos.y][start_pos.x]=0;
        Queue<Pos> q=new LinkedList<>();
        q.add(start_pos);
        while(!q.isEmpty()){
            Pos p=q.poll();
            int y=p.y;
            int x=p.x;
            // System.out.println("yx:"+y+" "+x);
            int ny,nx;
            int d;
            // 위로 이동 가능?
            d=0;
            ny=y+dy[d];
            nx=x+dx[d];
            if(isRange(ny,nx)){
                int flag=0;
                for(int i=nx;i<nx+B;++i){
                    if(!isRange(ny,i) || board[ny][i]==1){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    if(dist[y-1][x]>dist[y][x]+1){
                        dist[y-1][nx]=dist[y][x]+1;
                        q.add(new Pos(y-1,x));
                    }
                }
            }
            // 오른쪽으로 이동 가능?
            d=1;
            ny=y+dy[d];
            nx=x+dx[d]*B;
            if(isRange(ny,nx)){
                int flag=0;
                for(int i=ny;i<ny+A;++i){
                    if(!isRange(i,nx) || board[i][nx]==1){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    if(dist[y][x+1]>dist[y][x]+1){
                        dist[y][x+1]=dist[y][x]+1;
                        q.add(new Pos(y,x+1));
                    }
                }
            }
            // 아래 이동 가능?
            d=2;
            ny=y+dy[d]*A;
            nx=x+dx[d];
            if(isRange(ny,nx)){
                int flag=0;
                for(int i=nx;i<nx+B;++i){
                    if(!isRange(ny,i) || board[ny][i]==1){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    if(dist[y+1][x]>dist[y][x]+1){
                        dist[y+1][x]=dist[y][x]+1;
                        q.add(new Pos(y+1,x));
                    }
                }
            }
            // 왼쪽 이동 가능?
            d=3;
            ny=y+dy[d];
            nx=x+dx[d];
            if(isRange(ny,nx)){
                int flag=0;
                for(int i=ny;i<ny+A;++i){
                    if(!isRange(i,nx) || board[i][nx]==1){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    if(dist[y][x-1]>dist[y][x]+1){
                        dist[y][x-1]=dist[y][x]+1;
                        q.add(new Pos(y,x-1));
                    }
                }
            }
        }
        // System.out.println(fin_pos.y+" "+fin_pos.x);
        if(dist[fin_pos.y][fin_pos.x]==2023101800){
            System.out.println(-1);
        }else{
            System.out.println(dist[fin_pos.y][fin_pos.x]);
        }
    }

    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}


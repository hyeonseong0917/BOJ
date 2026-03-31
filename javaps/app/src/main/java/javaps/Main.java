package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    // 이동하는 모든 칸에서 나무와 거리의 최솟값이 가장 크도록 하고싶음
    static int N,M;
    static char board[][]=new char[500+1][500+1];
    static int dist[][]=new int[500+1][500+1];
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        M=Integer.parseInt(st.nextToken());
        for(int i=0;i<N;++i){
            st = new StringTokenizer(br.readLine());
            String str=st.nextToken();
            for(int j=0;j<M;++j){
                board[i][j]=str.charAt(j);
            }
        }
    }
    static class Pos{
        int y;
        int x;
        public Pos(int y, int x){
            this.y=y;
            this.x=x;
        }
    }
    static int dy[]={-1,0,1,0};
    static int dx[]={0,1,0,-1};
    static boolean isRange(int y, int x){
        return (y>=0 && x>=0 && y<N && x<M);
    }
    public static void Solve(){
        Queue<Pos> q=new LinkedList<>();
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                if(board[i][j]=='+'){
                    dist[i][j]=0;
                    q.add(new Pos(i,j));
                }else{
                    dist[i][j]=2023101800;
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
                if(board[ny][nx]=='+') continue;
                if(dist[ny][nx]>dist[y][x]+1){
                    dist[ny][nx]=dist[y][x]+1;
                    q.add(new Pos(ny,nx));
                }
            }
        }
        // for(int i=0;i<N;++i){
        //     for(int j=0;j<M;++j){
        //         System.out.print(dist[i][j]);
        //     }System.out.println();
        // }
        
        // 이동하는 거리에서 최솟값이 가장 크도록 할 때 그 값은?
        int cy=0,cx=0;
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                if(board[i][j]=='V'){
                    cy=i;
                    cx=j;
                }else{
                    
                }
            }
        }
        // System.out.println(cy+" "+cx);
        int L=0, R=N*M;
        // System.out.println(R);
        int min_num=0;
        boolean visited[][]=new boolean[500+1][500+1];
        while(L<=R){
            // System.out.println(L+" "+R);
            int mid=(L+R)/2;
            // 최솟값이 mid로 가능한지?
            boolean flag=false;
            for(int i=0;i<N;++i){
                for(int j=0;j<M;++j){
                    visited[i][j]=false;
                }
            }
            q=new LinkedList<>();
            q.add(new Pos(cy,cx));
            visited[cy][cx]=true;
            while(!q.isEmpty()){
                Pos p=q.poll();
                int y=p.y;
                int x=p.x;
                // if(L==0 && R==2){
                //     System.out.println(y+" "+x+" "+dist[y][x]);
                // }
                if(dist[y][x]<mid) break;
                // if(y==3 && x==2){
                //     System.out.println("fdsfsdf");
                // }
                if(board[y][x]=='J'){
                    flag=true;
                    break;
                }
                for(int i=0;i<4;++i){
                    int ny=y+dy[i];
                    int nx=x+dx[i];
                    
                    if(!isRange(ny,nx)) continue;
                    if(dist[ny][nx]<mid) continue;
                    if(visited[ny][nx]) continue;
                    // if(y==3 && x==2){
                    //     System.out.println("rkskekfkak"+ny+" "+nx+" "+dist[ny][nx]);
                    // }
                    q.add(new Pos(ny,nx));
                    visited[ny][nx]=true;
                }
            }
            if(flag==true){
                // System.out.println("fdsfds");
                min_num=Math.max(min_num,mid);
                L=mid+1;
            }else{
                R=mid-1;
            }
        }
        System.out.println(min_num);
    }

    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}


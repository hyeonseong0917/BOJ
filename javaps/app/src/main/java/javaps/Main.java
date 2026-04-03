package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n,m;
    static int board[][]=new int[1000+1][1000+1];
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        for(int i=0;i<n;++i){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<m;++j){
                
                String s=st.nextToken();
                board[i][j]=Integer.parseInt(s);
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
    static boolean isRange(int y, int x){
        return (y>=0 && x>=0 && y<n && x<m);
    }
    static int dy[]={-1,0,1,0};
    static int dx[]={0,1,0,-1};
    public static void Solve(){
        Queue<Pos> q=new LinkedList<>();
        boolean visited[][]=new boolean[1000+1][1000+1];
        int check[][]=new int[1000+1][1000+1];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                Pos p;
                if(board[i][j]==1){
                    // visited[i][j]=1;
                    check[i][j]=1;
                    p=new Pos(i,j);
                    q.add(p);
                }else if(board[i][j]==2){
                    // visited[i][j]=1;
                    p=new Pos(i,j);
                    check[i][j]=1;
                    q.add(p);
                }
                
            }
        }
        while(!q.isEmpty()){
            int qs=q.size();
            for(int i=0;i<qs;++i){
                Pos p=q.poll();
                int y=p.y;
                int x=p.x;
                if(board[y][x]==3) continue;
                for(int j=0;j<4;++j){
                    int ny=y+dy[j];
                    int nx=x+dx[j];
                    if(!isRange(ny,nx)) continue;
                    if(board[ny][nx]==board[y][x]) continue;
                    if(board[ny][nx]==-1) continue;
                    if(board[ny][nx]==0){
                        check[ny][nx]=check[y][x]+1;
                        board[ny][nx]=board[y][x];
                        q.add(new Pos(ny,nx));
                    }else{
                        if(check[ny][nx]==check[y][x]+1){
                            board[ny][nx]=3;
                        }
                    }
                }
            }
        }
        int fst_cnt=0, sed_cnt=0, trd_cnt=0;
        // for(int i=0;i<n;++i){
        //     for(int j=0;j<m;++j){
        //         System.out.print(board[i][j]);
        //     }System.out.println();
        // }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]==1){
                    ++fst_cnt;
                }else if(board[i][j]==2){
                    ++sed_cnt;
                }else if(board[i][j]==3){
                    ++trd_cnt;
                }
            }
        }
        System.out.print(fst_cnt+" "+sed_cnt+" "+trd_cnt);
    }

    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}


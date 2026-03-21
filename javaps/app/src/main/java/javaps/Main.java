package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static char board[][]=new char[6][6];
    static class Pos{
        int y;
        int x;
        public Pos(int y, int x){
            this.y=y;
            this.x=x;
        }
    }
    static ArrayList<Pos> v=new ArrayList<>();
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<6;++i){
            for(int j=0;j<6;++j){
                board[i][j]='.';
            }
        }
        board[2][2]='W';
        board[2][3]='B';
        board[3][2]='B';
        board[3][3]='W';
        n=Integer.parseInt(st.nextToken());
        for(int i=0;i<n;++i){
            st = new StringTokenizer(br.readLine());
            int y=Integer.parseInt(st.nextToken());
            int x=Integer.parseInt(st.nextToken());
            v.add(new Pos(y,x));
        }

    }
    static int dy[]={-1,-1,-1,0,1,1,1,0};
    static int dx[]={-1,0,1,1,1,0,-1,-1};
    static boolean isRange(int y, int x){
        return (y>=0 && x>=0 && y<6 && x<6);
    }
    static void Solve(){
        for(int i=0;i<n;++i){
            int y=v.get(i).y;
            int x=v.get(i).x;
            --y;
            --x;
            char c='B';
            if(i%2==1){
                // 흰돌
                c='W';
            }
            board[y][x]=c;
            for(int j=0;j<8;++j){
                // j번째 방향을 선택함
                int ny=y+dy[j];
                int nx=x+dx[j];
                int flag=0;
                while(true){
                    if(!isRange(ny,nx)) break;
                    if(board[ny][nx]=='.') break;
                    if(board[ny][nx]==c){
                        flag=1;
                        break;
                    }
                    ny+=dy[j];
                    nx+=dx[j];
                }
                if(flag==1){
                    int cy=y;
                    int cx=x;
                    while(true){
                        if(cy==ny && cx==nx) break;
                        board[cy][cx]=c;
                        cy+=dy[j];
                        cx+=dx[j];
                    }
                }
            }
            // for(int j=0;j<6;++j){
            //     for(int k=0;k<6;++k){
            //         System.out.print(board[j][k]);
            //     }System.out.println();
            // }
        }
        int b_cnt=0, w_cnt=0;
        for(int i=0;i<6;++i){
            for(int j=0;j<6;++j){
                System.out.print(board[i][j]);
                if(board[i][j]=='B'){
                    ++b_cnt;
                }else if(board[i][j]=='W'){
                    ++w_cnt;
                }
            }System.out.println();
        }
        if(b_cnt<w_cnt){
            System.out.print("White");
        }else{
            System.out.print("Black");
        }
    }

    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}

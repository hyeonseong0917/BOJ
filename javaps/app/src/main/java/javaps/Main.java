package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int H,W,R,C,D;
    static int board[][][]=new int[2][64][64];
    static boolean visited[][][]=new boolean[2][64][64];
    static int check[][]=new int[64][64];
    static boolean isRange(int y, int x){
        return (y>=0 && x>=0 && y<H && x<W);
    }
    static int dy[]={-1,0,1,0};
    static int dx[]={0,1,0,-1};
    static int ans=0;
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        H=Integer.parseInt(st.nextToken());
        W=Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        R=Integer.parseInt(st.nextToken());
        C=Integer.parseInt(st.nextToken());
        D=Integer.parseInt(st.nextToken());
        for(int i=0;i<H;++i){
            st = new StringTokenizer(br.readLine());
            String s=st.nextToken();
            for(int j=0;j<W;++j){
                board[0][i][j]=s.charAt(j);
                check[i][j]=1;
            }
        }
        for(int i=0;i<H;++i){
            st = new StringTokenizer(br.readLine());
            String s=st.nextToken();
            for(int j=0;j<W;++j){
                board[1][i][j]=s.charAt(j);
            }
        }
    }
    // 지금부터 위의 과정을 반복해도 더이상 지울 수 없다면??
    // 그 조건이 언제인지??
    
    static void Solve(){
        int cnt=0;
        while(true){
            // 1. 시뮬레이션
            if(check[R][C]==1){
                check[R][C]=0;
                D+=board[0][R][C];
                D%=4;
                cnt=0;
            }else{
                D+=board[1][R][C];
                D%=4;
                ++cnt;
            }
            R+=dy[D];
            C+=dx[D];
            ++ans;
            // 2. 언제 종료해야?
            if(cnt>H*W*4 || !isRange(R,C)){
                ans-=cnt;
                break;
            }

        }
        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}


package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n,m,p,HP;
    static String board[]=new String[1000+1];
    static class Player{
        char id;
        int dps;
        public Player(char id, int dps){
            this.id=id;
            this.dps=dps;
        }

    }
    static ArrayList<Player> v=new ArrayList<>();
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        p=Integer.parseInt(st.nextToken());
        for(int i=0;i<n;++i){
            st = new StringTokenizer(br.readLine());
            board[i]=st.nextToken();
        }
        for(int i=0;i<p;++i){
            st = new StringTokenizer(br.readLine());
            char cur_id=st.nextToken().charAt(0);
            int cur_dps=Integer.parseInt(st.nextToken());
            v.add(new Player(cur_id,cur_dps));
        }
        st = new StringTokenizer(br.readLine());
        HP=Integer.parseInt(st.nextToken());
    }
    // static class CntNum implements Comparable<CntNum>{
    //     int cnt;
    //     int num;
    //     public CntNum(int cnt, int num){
    //         this.cnt=cnt;
    //         this.num=num;
    //     }
    //     @Override
    //     public int compareTo(CntNum other){
    //         return this.cnt-other.cnt;
    //     }
    // }
    static class Pos{
        int y;
        int x;
        public Pos(int y, int x){
            this.y=y;
            this.x=x;
        }
    }
    static class DistPos implements Comparable<DistPos>{
        int dist;
        int y;
        int x;
        public DistPos(int dist, int y, int x){
            this.dist=dist;
            this.y=y;
            this.x=x;
        }
        @Override
        public int compareTo(DistPos other){
            return this.dist-other.dist;
        }
    }
    static Pos[] init_pos=new Pos[26];
    static ArrayList<ArrayList<Integer>> time_player=new ArrayList<ArrayList<Integer>>();
    static int[][] dist=new int[1000+1][1000+1];
    static int dy[]=new int[]{-1,0,1,0};
    static int dx[]=new int[]{0,1,0,-1};
    static boolean isRange(int y, int x){
        return (y>=0 && x>=0 && y<n && x<m);
    }
    static void Solve(){
        // 1. 각 player별로 도달하기까지 최소 시간이 몇초인지 구한다
        // 2. 시간=1부터 쭉 순회함. 보스몬스터 체력 0 될때까지.
        // 3. 데미지 준 player cnt 구함
        
        // 0. id에 맞는 좌표를 구하기
        int by=0,bx=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                dist[i][j]=2023101800;
                if(board[i].charAt(j)=='B'){
                    by=i;
                    bx=j;
                    continue;
                }
                if(board[i].charAt(j)=='.' || board[i].charAt(j)=='B' || board[i].charAt(j)=='X') continue;
                int a=board[i].charAt(j)-'a';
                init_pos[a]=new Pos(i,j);
                
            }
        }
        // 1. x시간에 추가되는 플레이어들의 인덱스 넣기
        for(int i=0;i<=1000000;++i){
            ArrayList<Integer> arr=new ArrayList<>();
            time_player.add(arr);
        }
        // 2. B의 좌표에서 모든 지점까지의 최소 거리를 구한다
        dist[by][bx]=0;
        PriorityQueue<DistPos> pq=new PriorityQueue<>();
        pq.add(new DistPos(0,by,bx));
        while(!pq.isEmpty()){
            DistPos cur_dist_pos=pq.poll();
            int cur_dist=cur_dist_pos.dist;
            int y=cur_dist_pos.y;
            int x=cur_dist_pos.x;
            // System.out.println(y+" "+x);
            for(int i=0;i<4;++i){
                int ny=y+dy[i];
                int nx=x+dx[i];
                if(!isRange(ny,nx)) continue;
                if(board[ny].charAt(nx)=='X') continue;
                if(dist[ny][nx]>dist[y][x]+1){
                    dist[ny][nx]=dist[y][x]+1;
                    pq.add(new DistPos(dist[ny][nx],ny,nx));
                }
            }
        }
        
        for(int i=0;i<p;++i){
            char cur_id=v.get(i).id;
            int cur_dps=v.get(i).dps;
            int cur_y=init_pos[cur_id-'a'].y;
            int cur_x=init_pos[cur_id-'a'].x;
            // cur_y에서 cur_x까지 얼마나 걸리는지?
            int cur_time=dist[cur_y][cur_x];
            if(cur_time==2023101800) continue;
            time_player.get(cur_time).add(i);
        }
        int total_dps=0;
        int cnt=0;
        for(int i=1;i<=1000001;++i){
            // 현재 i초임.
            HP-=total_dps;
            if(HP<=0) break;
            for(int j=0;j<time_player.get(i).size();++j){
                int cur_idx=time_player.get(i).get(j);
                total_dps+=v.get(cur_idx).dps;
                ++cnt;
            }
        }
        System.out.println(cnt);
    }

    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}

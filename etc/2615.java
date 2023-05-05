/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Pos{
    int y,x;
    public Pos(int y, int x){
        this.y=y;
        this.x=x;
    }
}
class Descending implements Comparator<Pos>{
    public int compare(Pos a, Pos b){
        int res=-1;
        if(a.x>=b.x){
            res=1;
        }
        return res;
    }
}
class 2615
{
    static int[][] board=new int[19+1][19+1];
    static boolean[][][] visited = new boolean[19+1][19+1][8+1];
    static int dy[]=new int[]{-1,-1,0,1,1,1,0,-1};
    static int dx[]=new int[]{0,1,1,1,0,-1,-1,-1};
    static ArrayList<Pos> p=new ArrayList<>();
    static boolean isRange(int y, int x){
        return (y>=0 && x>=0 && y<19 && x<19);
    }
    static void Input(){
        Scanner sc=new Scanner(System.in);
        for(int i=0;i<19;++i){
            for(int j=0;j<19;++j){
                board[i][j]=Integer.parseInt(sc.next());
            }
        }
    }
    static int check(int y, int x, int num){

        for(int dir=0;dir<8;++dir){
            int cy=y,cx=x,cnt=1;
            p.clear();
            p.add(new Pos(cy,cx));
            while(true){
                cy+=dy[dir];
                cx+=dx[dir];
                if(isRange(cy,cx)==false){
                    break;
                }
                if(board[cy][cx]==num && visited[cy][cx][dir]==false){
                    // if(y==2 && x==1 && dir==3){
                    // System.out.print(cy);
                    // System.out.println(cx);
                    // }
                    visited[cy][cx][dir]=true;
                    p.add(new Pos(cy,cx));
                    ++cnt;
                }else{
                    break;
                }
            }
            if(cnt==5){
                Collections.sort(p,new Descending());
                // for(int i=0;i<5;++i){
                // 	System.out.print(p.get(i).y+" ");
                // 	System.out.println(p.get(i).x);
                // }
                return 1;
            }
        }
        return 0;
    }
    static void solve(){
        for(int i=0;i<19;++i){
            for(int j=0;j<19;++j){
                int num=0;

                if(board[i][j]==1){
                    num=check(i,j,1);

                }else if(board[i][j]==2){
                    num=check(i,j,2);
                }
                if(num==1){
                    // for(int m=0;m<5;++m){
                    // 	System.out.print(p.get(m).x);
                    // }
                    System.out.println(board[i][j]);
                    System.out.print((p.get(0).y+1)+" "+(p.get(0).x+1));
                    return;
                }

            }
        }
        System.out.print(0);
    }
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        Input();
        solve();
    }
}
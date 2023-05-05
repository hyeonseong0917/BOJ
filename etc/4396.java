/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class 4396
{
    static int N=0;
    static String [] bomb=new String[10+1],board=new String[10+1];
    static char [][] ans=new char[10+1][10+1];
    static int[] dy=new int[]{-1,-1,0,1,1,1,0,-1};
    static int[] dx=new int[]{0,1,1,1,0,-1,-1,-1};
    static void Input(){
        Scanner sc=new Scanner(System.in);
        N=Integer.parseInt(sc.next());
        for(int i=0;i<N;++i){
            String s=sc.next();
            bomb[i]=s;
        }
        for(int i=0;i<N;++i){
            String s=sc.next();
            board[i]=s;
        }
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                ans[i][j]='.';
            }
        }
    }
    static boolean isRange(int y, int x){
        return (y>=0 && x>=0 && y<N && x<N);
    }
    static void solve(){
        boolean isBomb=false;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(board[i].charAt(j)=='x'){
                    if(bomb[i].charAt(j)=='.'){
                        int cnt=0;
                        for(int k=0;k<8;++k){
                            int ny=i+dy[k];
                            int nx=j+dx[k];
                            if(isRange(ny,nx)==true && bomb[ny].charAt(nx)=='*'){
                                ++cnt;
                            }
                        }
                        ans[i][j]=(char)(cnt+'0');
                    }else{
                        isBomb=true;
                    }
                }
            }
        }
        if(isBomb==true){
            for(int i=0;i<N;++i){
                for(int j=0;j<N;++j){
                    if(bomb[i].charAt(j)=='*'){
                        ans[i][j]='*';
                    }
                }
            }
        }
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                System.out.print(ans[i][j]);
            }System.out.println();
        }
    }
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        Input();
        solve();
    }
}
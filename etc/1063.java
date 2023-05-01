/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
    public static boolean isRange(int y, int x){
        return (y>=0 && x>=0 && y<8 && x<8);
    }
    public static void move(int flag, String dir){
        //flag==0 king
        //flag==1 stone
        if(flag==0){
            if(dir.length()==1){
                if(dir.equals("R")==true){
                    kx+=1;
                }else if(dir.equals("L")==true){
                    kx-=1;
                }else if(dir.equals("B")==true){
                    ky+=1;
                }else if(dir.equals("T")==true){
                    ky-=1;
                }
            }else{
                if(dir.equals("RT")==true){
                    kx+=1;
                    ky-=1;
                }else if(dir.equals("LT")==true){
                    kx-=1;
                    ky-=1;
                }else if(dir.equals("RB")==true){
                    kx+=1;
                    ky+=1;
                }else if(dir.equals("LB")==true){
                    kx-=1;
                    ky+=1;
                }
            }

        }else{
            if(dir.length()==1){
                if(dir.equals("R")==true){
                    sx+=1;
                }else if(dir.equals("L")==true){
                    sx-=1;
                }else if(dir.equals("B")==true){
                    sy+=1;
                }else if(dir.equals("T")==true){
                    sy-=1;
                }
            }else{
                if(dir.equals("RT")==true){
                    sx+=1;
                    sy-=1;
                }else if(dir.equals("LT")==true){
                    sx-=1;
                    sy-=1;
                }else if(dir.equals("RB")==true){
                    sx+=1;
                    sy+=1;
                }else if(dir.equals("LB")==true){
                    sx-=1;
                    sy+=1;
                }
            }
        }

    }

    //1. 왕 움직임, 왕 위치 합당한지 판단
    //2. 왕의 위치와 돌의 위치 같다면 돌의 위치도 이동
    //3. 왕의 위치와 돌의 위치가 합당한지 판단, 아니라면 왕도 돌도 원래대로 되돌림

    public static void valid(String s, int oky, int okx, int osy, int osx){
        if(!isRange(ky,kx)){
            ky=oky;
            kx=okx;
            return;
        }
        if(ky==sy && kx==sx){
            move(1,s); //돌 움직임
            if(!isRange(sy,sx)){
                sy=osy;
                sx=osx;
                ky=oky;
                kx=okx;
            }
        }
    }
    public static int kx;
    public static int ky;
    public static int sx;
    public static int sy;
    public static boolean flag;
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        Scanner sc=new Scanner(System.in);
        String king=sc.next();
        String stone=sc.next();
        int N=Integer.parseInt(sc.next());
        int [][] array=new int[51][51];
        ArrayList<String> move_cmd=new ArrayList<>();
        kx=king.charAt(0)-'A';
        ky=8-Integer.parseInt(king.substring(1,2));
        sx=stone.charAt(0)-'A';
        sy=8-Integer.parseInt(stone.substring(1,2));
        // System.out.println(isRange(7,9));
        for(int i=0;i<N;++i){
            String cur_cmd=sc.next();
            move_cmd.add(cur_cmd);
        }
        // turn('R');
        // System.out.println(k_col);
        for(int i=0;i<N;++i){
            String cur_move=move_cmd.get(i);
            int origin_ky=ky;
            int origin_kx=kx;
            int origin_sy=sy;
            int origin_sx=sx;
            move(0,cur_move);
            valid(cur_move,origin_ky,origin_kx,origin_sy,origin_sx);
        }
        // System.out.println((char)('A'+1));
        char k_pos=(char)('A'+kx);
        char s_pos=(char)('A'+sx);
        String king_pos=k_pos+Integer.toString((8-ky));
        String stone_pos=s_pos+Integer.toString((8-sy));
        System.out.println(king_pos);
        System.out.println(stone_pos);
        // System.out.println(ky);
        // System.out.println(kx);
        // System.out.println(sy);
        // System.out.println(sx);
    }
}
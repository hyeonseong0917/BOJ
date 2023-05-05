/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
// import java.util.HashMap;
/* Name of the class has to be "Main" only if the class is public. */
class pos{
    int y,x;
    public pos(int y, int x){
        this.y=y;
        this.x=x;
    }

}
class 1913
{
    static int N=0, target=0;
    static final int MAX=999+1;
    static int [][] arr;
    static pos [] num_pos;
    static int dy []={-1,0,1,0};
    static int dx []={0,1,0,-1};
    static HashMap<Integer, pos> m=new HashMap<>();
    public static void main (String[] args) throws java.lang.Exception
    {
        // your code goes here
        Input();
        setNumber();
        getOutput();
        // solve();


    }
    static void Input(){
        Scanner sc=new Scanner(System.in);
        N=Integer.parseInt(sc.next());
        target=Integer.parseInt(sc.next());
        arr=new int[MAX][MAX];
    }
    static void getOutput(){
        // String [] output=new String[N];
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                sb.append(arr[i][j]).append(" ");
            }
            sb.append("\n");
            // System.out.println();
        }
        sb.append(m.get(target).y+1).append(" ").append(m.get(target).x+1);
        System.out.println(sb);
    }
    static void setNumber(){
        int y=N/2, x=N/2;
        int curNum=1;

        int step=1;
        int step_cnt=0;
        int dir=0;
        arr[y][x]=curNum;
        m.put(curNum, new pos(y,x));
        // m[curNum]=new pos(y,x);
        while(curNum<=N*N){
            if(step_cnt==2){
                step_cnt=0;
                ++step;
            }
            int cur_step=step;
            boolean flag=false;
            boolean fin=false;
            while(true){
                --cur_step;
                if(cur_step<0){
                    flag=true;
                    break;
                }

                y+=dy[dir];
                x+=dx[dir];

                ++curNum;
                m.put(curNum, new pos(y,x));
                // System.out.println(y);
                // System.out.println(x);
                arr[y][x]=curNum;
                if(curNum==N*N){
                    fin=true;
                    break;
                }
            }
            if(fin==true){
                return;
            }
            if(flag==true){
                dir=(dir+1)%4;
            }

            ++step_cnt;
        }
    }
}
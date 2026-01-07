package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    
    public static void Input() throws IOException{
        // n=Integer.parseInt(st.nextToken());
        // m=Integer.parseInt(st.nextToken());

        // // n 줄에 받는 경우
        // for(int i=0;i<n;++i){
        //     st=new StringTokenizer(br.readLine());
        //     arr[i]=Integer.parseInt(st.nextToken());
        // }
        // // 1 줄에 n개 받는경우
        // st=new StringTokenizer(br.readLine());
        // for(int i=0;i<n;++i){
        //     arr[i]=Integer.parseInt(st.nextToken());
        // }
        // n=Integer.parseInt(st.nextToken());
        // m=Integer.parseInt(st.nextToken());
        // st=new StringTokenizer(br.readLine());
        // s=st.nextToken();
        // st=new StringTokenizer(br.readLine());
        // t=st.nextToken(); 
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A,B,C,D,E;
        A=Integer.parseInt(st.nextToken());
        B=Integer.parseInt(st.nextToken());
        C=Integer.parseInt(st.nextToken());
        D=Integer.parseInt(st.nextToken());
        E=Integer.parseInt(st.nextToken());
        

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
    //         return other.cnt-this.cnt;
    //     }
    // }
    

    static void Solve(){
        int psum[][]=new int[300+1][300+1];
        psum[0][0]=board[0][0];
        // System.out.println();
        for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(i==0 && j==0) continue;
            psum[i][j]=board[i][j];
            if(i>0){
            psum[i][j]+=psum[i-1][j];
            }
            if(j>0){
            psum[i][j]+=psum[i][j-1];
            }
            if(i>0 && j>0){
            psum[i][j]-=psum[i-1][j-1];
            }
            System.out.println(i+" "+j+" "+psum[i][j]);
        }
        }
        for(int i=0;i<k;++i){
        int sy=arr.get(i).sy;
        int sx=arr.get(i).sx;
        int fy=arr.get(i).fy;
        int fx=arr.get(i).fx;
        int ans=0;
        if(sy==0 && sx==0){
            ans=psum[fy][fx];
        }else{
            if(sy==0 || sx==0){
            if(sy==0){
                ans=psum[fy][fx]-psum[fy][sx-1];
            }else{
                ans=psum[fy][fx]-psum[sy-1][fx];
            }
            }else{
            ans=psum[fy][fx]-psum[fy][sx-1]-psum[sy-1][fx]+psum[sy-1][sx-1];
            }
        }
        System.out.println(ans);
        }
    }

    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}

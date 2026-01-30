package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static int n;
    static ArrayList<Integer> v;
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
        n=Integer.parseInt(st.nextToken());
        st=new StringTokenizer(br.readLine());
        v=new ArrayList<>();
        for(int i=0;i<n;++i){
            int a=Integer.parseInt(st.nextToken());
            v.add(a);
        }
        Collections.sort(v);
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
        // k번 이상 인용된 논문이 k편 이상이고, n-k편의 논문들의 인용 횟수가 k번 이하라면?
        int ans=0;
        for(int i=0;i<n;++i){
            // n-i개 있음 i를 기준으로 본다면
            int k=n-i;
            if(i==0 || v.get(i-1)<=k){
                if(v.get(i)>=k){
                    ans=Math.max(ans,k);
                }
                
            }
        }
        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}

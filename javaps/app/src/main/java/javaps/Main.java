package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N;
    static ArrayList<Integer> v=new ArrayList<>();
    static int ans[]=new int[2000+1];
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;++i){
            
            int a=Integer.parseInt(st.nextToken());
            v.add(a);
        }
        
    }
    
    public static void Solve(){
        Collections.sort(v,Collections.reverseOrder());
        int L=0;
        int R=N-1;
        int idx=0;
        while(L<=R){
            if(idx%2==0){
                ans[L]=v.get(idx);
                ++L;
            }else{
                ans[R]=v.get(idx);
                --R;
            }
            ++idx;
        }
        long answer=ans[0]*ans[N-1];
        for(int i=1;i<N;++i){
            answer+=ans[i]*ans[i-1];
        }
        System.out.println(answer);
        for(int i=0;i<N;++i){
            System.out.print(ans[i]);
            if(i!=N-1){
                System.out.print(" ");
            }
        }
    }


    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}


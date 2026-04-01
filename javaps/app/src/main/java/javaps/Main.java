package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N,K;
    static ArrayList<Integer> v=new ArrayList<>();
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        K=Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;++i){
            int a=Integer.parseInt(st.nextToken());
            v.add(a);
        }
    }
    
    public static void Solve(){
        Collections.sort(v);
        int idx=-1;
        for(int i=0;i<N;++i){
            if(v.get(i)>=K){
                idx=i;
                break;
            }
        }
        int ans=0;
        int L=0, R=N-1;
        if(idx!=-1){
            ans=N-idx;
            R=idx-1;
        }
        while(L<R){
            int sum=v.get(L)+v.get(R);
            if(sum>=K){
                ++ans;
                ++L;
                --R;
            }else{
                ++L;
            }
        }
        if(ans==0){
            --ans;
        }
        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}


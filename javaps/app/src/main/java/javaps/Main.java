package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int T;
    static int N;
    static class Pos implements Comparable<Pos>{
        int x;
        int y;
        public Pos(int x, int y){
            this.x=x;
            this.y=y;
        }
        @Override
        public int compareTo(Pos other){
            return this.x-other.x;
        }
    }
    static ArrayList<Pos> v=new ArrayList<>();
    static int check[]=new int[15000+1];
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        T=Integer.parseInt(st.nextToken());
        while(T>0){
            st = new StringTokenizer(br.readLine());
            int S=Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            v.clear();
            for(int i=0;i<=15000;++i){
                check[i]=-1;
            }
            Pos p=new Pos(0,0);
            for(int i=0;i<S*2;++i){
                int a=Integer.parseInt(st.nextToken());
                // System.out.println(a);
                if(i%2==0){
                    p=new Pos(0,0);
                    p.x=a;
                }else{
                    p.y=a;
                    v.add(p);
                    // System.out.println(p.x+" "+p.y);
                }
            }
            // for(int i=0;i<v.size();++i){
            //     System.out.println(v.get(i).x+" "+v.get(i).y);
            // }
            Solve();
            --T;
        }   
    }
    static class Y implements Comparable<Y>{
        int val;
        public Y(int val){
            this.val=val;
        }
        @Override
        public int compareTo(Y other){
            return other.val-this.val;
        }
    }
    public static void Solve(){
        // v에 원소들이 담겼음
        Collections.sort(v);
        ArrayList<Integer> arr=new ArrayList<>();
        for(int i=0;i<v.size();++i){
            arr.add(v.get(i).y);
            // System.out.println(v.get(i).x+" "+v.get(i).y);
        }
        int L=5000, R=5000;
        int ans=0;
        for(int i=0;i<arr.size();++i){
            int cur_num=arr.get(i);
            if(L==R){
                check[R]=cur_num;
                ++R;
            }else{
                if(cur_num<check[L]){
                    check[L-1]=cur_num;
                    --L;
                }else{
                    int l=L;
                    int r=R-1;
                    int max_idx=-1;
                    while(l<=r){
                        int mid=(l+r)/2;
                        if(check[mid]<=cur_num){
                            max_idx=Math.max(max_idx,mid);
                            l=mid+1;
                        }else{
                            r=mid-1;
                        }
                    }
                    if(max_idx==-1){
                        check[R]=cur_num;
                        ++R;
                    }else{
                        check[max_idx]=cur_num;
                    }
                }
            }
        }
        ans=R-L;
        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException{
        Input();
        // Solve();
    }
}


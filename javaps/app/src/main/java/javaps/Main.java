package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N,P;
    static ArrayList<Integer> v=new ArrayList<>();
    static class Val implements Comparable<Val>{
        int val;
        public Val(int val){
            this.val=val;
        }
        @Override
        public int compareTo(Val other){
            return this.val-other.val;
        }
    }
    static PriorityQueue<Val> pq=new PriorityQueue<>();
    static int sum=0;
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        P=Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;++i){
            int a;
            a=Integer.parseInt(st.nextToken());
            v.add(a);
        }
    }
    static ArrayList<Integer> ans=new ArrayList<>();
    static void Solve(){
        int idx=-1;
        int flag=0;
        for(int i=0;i<N;++i){
            int a=v.get(i);
            idx=i;
            if(sum+a<P){
                sum+=a;
                pq.add(new Val(a));
                ans.add(-1);
            }else{
                flag=1;
                break;
            }
            
        }
        if(flag==0){
            for(int i=0;i<N;++i){
                ans.add(-1);
            }
        }else{
            for(int i=idx;i<N;++i){
                int min_num=-1;
                if(!pq.isEmpty()){
                    min_num=pq.peek().val;
                }
                if(min_num>=v.get(i) && sum>=P){
                    int ps=pq.size();
                    ans.add(ps);
                }else{
                    // min_num<pq.top()
                    while(!pq.isEmpty()){
                        min_num=pq.peek().val;
                        if((sum-min_num+v.get(i))>=P){
                            pq.poll();
                            sum-=min_num;
                        }else{
                            break;
                        }
                    }
                    pq.add(new Val(v.get(i)));
                    sum+=v.get(i);
                    int ps=pq.size();
                    ans.add(ps);
                }
            }
        }
        for(int i=0;i<N;++i){
            System.out.print(ans.get(i));
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


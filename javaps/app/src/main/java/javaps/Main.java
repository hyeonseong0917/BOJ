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
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        T=Integer.parseInt(st.nextToken());
        while(T>0){
            st = new StringTokenizer(br.readLine());
            int S=Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            v.clear();
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
        // for(int i=0;i<v.size();++i){
        //     System.out.print(arr.get(i)+" ");
        // }System.out.println();
        int ans=0;
        PriorityQueue<Y> pq=new PriorityQueue<>();
        PriorityQueue<Y> tmp=new PriorityQueue<>();
        for(int i=0;i<arr.size();++i){
            int cur_num=arr.get(i);
            if(pq.isEmpty()){
                pq.add(new Y(cur_num));
            }else{
                // pq에 cur_num보다 작은 값이 top에 있을 때까지 empty
                while(!pq.isEmpty()){
                    Y cur_top=pq.peek();
                    if(cur_top.val<=cur_num){
                        pq.poll();
                        break;
                    }else{
                        pq.poll();
                        tmp.add(cur_top);
                    }
                }
                pq.add(new Y(cur_num));
                while(!tmp.isEmpty()){
                    Y tmp_top=tmp.poll();
                    pq.add(tmp_top);
                }

            }
            if(!pq.isEmpty()){
                int ps=pq.size();
                ans=Math.max(ans,ps);
            }
        }
        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException{
        Input();
        // Solve();
    }
}


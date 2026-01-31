package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static ArrayList<Integer> v=new ArrayList<>();
    static int n;
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        
        for(int i=0;i<n;++i){
            st=new StringTokenizer(br.readLine());
            String s=st.nextToken();
            int s_len=s.length();
            if(s.charAt(s_len-1)=='2'){
                v.add(2);
            }else{
                int c=s.charAt(0)-'0';
                v.add(c);
            }
        }
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
    //         return this.cnt-other.cnt;
    //     }
    // }
    
    static class X implements Comparable<X>{
        int pizza;
        public X(int pizza){
            this.pizza=pizza;
        }
        @Override
        public int compareTo(X other){
            return other.pizza-this.pizza;
        }
    }
    static void Solve(){
        Collections.sort(v,Collections.reverseOrder());
        // 3 3 3 3 3 2 2 2 2 1 1 1 1 1
        // 제일 적게 먹은 피자를 위로 올림
        // pq에는 남은 피자의 양이 있어야함
        PriorityQueue<X> pq=new PriorityQueue<>();
        for(int i=0;i<v.size();++i){
            if(pq.isEmpty()){
                X pizza=new X(4-v.get(i));
                pq.add(pizza);
            }else{
                X curPizza=pq.peek();
                if(curPizza.pizza<v.get(i)){
                    curPizza=new X(4-v.get(i));
                    pq.add(curPizza);
                }else{
                    pq.poll();
                    curPizza.pizza-=v.get(i);
                    pq.add(curPizza);
                }
            }
        }
        int ps=pq.size();
        System.out.println(ps);
    }

    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}

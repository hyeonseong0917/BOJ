package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N,K;
    static ArrayList<Integer> v=new ArrayList<>();
    static int diff[]=new int[100000+1];
    static int psum[]=new int[100000+1];
    static HashMap<Integer,Long> check=new HashMap<>();
    static long ans=0;
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        K=Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;++i){
            int a=Integer.parseInt(st.nextToken());
            v.add(a);
            check.put(a,1L);
        }
    }
    static long getDist(int pos){
        // pos위치에서 모든 샘터까지의 합?
        long cur_dist=2023101800L;
        // 1. pos보다 작은 최대의 위치
        int L,R,max_idx,min_idx;
        L=0; R=N-1;
        max_idx=-1;
        while(L<=R){
            int mid=(L+R)/2;
            if(v.get(mid)<pos){
                max_idx=Math.max(max_idx,mid);
                L=mid+1;
            }else{
                R=mid-1;
            }
        }
        if(max_idx!=-1){
            cur_dist=pos-v.get(max_idx);
        }
        L=0; R=N-1;
        min_idx=N;
        while(L<=R){
            int mid=(L+R)/2;
            if(v.get(mid)>pos){
                min_idx=Math.min(min_idx,mid);
                R=mid-1;
            }else{
                L=mid+1;
            }
        }
        if(min_idx!=N){
            cur_dist=Math.min(cur_dist,v.get(min_idx)-pos);
        }
        return cur_dist;
    }
    
    static class ValPos implements Comparable<ValPos>{
        Long val;
        int pos;
        public ValPos(Long val, int pos){
            this.val=val;
            this.pos=pos;
        }
        @Override
        public int compareTo(ValPos other){
            return Long.compare(this.val,other.val);
        }
    }
    static void Solve(){
        Collections.sort(v);
        for(int i=1;i<N;++i){
            diff[i]=v.get(i)-v.get(i-1);
            psum[i]=psum[i-1]+diff[i];
        }
        // System.out.println(3+" "+getDist(3));
        // for(int i=-6;i<=7;++i){
        //     System.out.println(i+" "+getDist(i));
        // }
        int cnt=K;
        PriorityQueue<ValPos> pq=new PriorityQueue<>();
        for(int i=0;i<N;++i){
            int fst_pos=v.get(i)-1;
            int sed_pos=v.get(i)+1;
            if(!check.containsKey(fst_pos)){
                check.put(fst_pos,getDist(fst_pos));
                pq.add(new ValPos(getDist(fst_pos),fst_pos));
            }
            if(!check.containsKey(sed_pos)){
                check.put(sed_pos,getDist(sed_pos));
                pq.add(new ValPos(getDist(sed_pos),sed_pos));
            }

        }
        while(!pq.isEmpty() && cnt>0){
            ValPos vp=pq.poll();
            long cur_val=vp.val;
            int cur_pos=vp.pos;
            --cnt;
            // System.out.println(cur_val+" "+cur_pos+" "+cnt);
            ans+=cur_val;
            int fst_pos=cur_pos-1;
            int sed_pos=cur_pos+1;
            if(!check.containsKey(fst_pos)){
                check.put(fst_pos,getDist(fst_pos));
                pq.add(new ValPos(getDist(fst_pos),fst_pos));
            }
            if(!check.containsKey(sed_pos)){
                check.put(sed_pos,getDist(sed_pos));
                pq.add(new ValPos(getDist(sed_pos),sed_pos));
            }
        }
        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}


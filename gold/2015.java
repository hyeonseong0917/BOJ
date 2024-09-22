import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.logging.Logger;

public class Main {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n,k;
        n=sc.nextInt();
        k=sc.nextInt();
        ArrayList<Integer> v=new ArrayList<Integer>();
        for(long i=0;i<n;++i){
            Integer a;
            a=sc.nextInt();
            v.add(a);
        }
        Integer psum[]=new Integer[n+1];
        psum[0]=v.get(0);
        Map<Integer, Long> m=new HashMap<Integer, Long>();
        m.put(psum[0],1L);
        Long ans=0L;
        if(psum[0]==k){
            ++ans;
        }
        for(int i=1;i<n;++i){
            psum[i]=psum[i-1]+v.get(i);
            if(psum[i]==k){
                ++ans;
            }
            if(m.containsKey(psum[i]-k)){
                ans+=m.get(psum[i]-k);
            }
            if(m.containsKey(psum[i])){
                m.put(psum[i],m.get(psum[i])+1);
            }else{
                m.put(psum[i],1L);
            }
        }
        System.out.println(ans);
    }
}

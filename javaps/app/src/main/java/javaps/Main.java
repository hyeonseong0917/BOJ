package javaps;
import java.util.*;
import java.io.*;

public class Main {
    static Scanner sc=new Scanner(System.in);
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static String A,B,C;
    static int check[]=new int[26];
    static int visited[]=new int[10];
    static ArrayList<Integer> tmp=new ArrayList<>();
    public static void Input() throws IOException{
        st = new StringTokenizer(br.readLine());
        A=st.nextToken();
        B=st.nextToken();
        C=st.nextToken();
    }
    static ArrayList<Character> v=new ArrayList<>();
    static int finish=0;
    static int m[]=new int[26];
    // v의 i번째 문자는, tmp의 i번째 값과 매칭됨
    static void dfs(int idx){
        if(finish==1) return;
        // tmp의 idx번째 인덱스에 어떤 값을 넣을 것인지??
        int vs=v.size();
        if(idx==vs){
            // 연산 가능한지??
            int as=A.length();
            int bs=B.length();
            int cs=C.length();
            for(int i=0;i<v.size();++i){
                char c=v.get(i);
                m[c-'A']=tmp.get(i);
            }
            long fs=0, ss=0, ts=0;
            for(int i=0;i<as;++i){
                fs*=10;
                fs+=m[A.charAt(i)-'A'];
            }
            for(int i=0;i<bs;++i){
                ss*=10;
                ss+=m[B.charAt(i)-'A'];
            }
            for(int i=0;i<cs;++i){
                ts*=10;
                ts+=m[C.charAt(i)-'A'];
            }
            if((fs+ss)==ts){
                finish=1;
            }
            return;
        }
        for(int i=0;i<10;++i){
            if(visited[i]==1) continue;
            visited[i]=1;
            tmp.add(i);
            int ts=tmp.size();
            dfs(idx+1);
            tmp.remove(ts-1);
            visited[i]=0;
        }
    }
    
    public static void Solve(){
        String fst_tmp=new String("");
        int as=A.length();
        for(int i=as-1;i>=0;--i){
            fst_tmp+=A.charAt(i);
            ++check[A.charAt(i)-'A'];
        }
        // A=new String(fst_tmp);
        
        String sed_tmp=new String("");
        int bs=B.length();
        for(int i=bs-1;i>=0;--i){
            sed_tmp+=B.charAt(i);
            ++check[B.charAt(i)-'A'];
        }
        // B=new String(sed_tmp);

        String trd_tmp=new String("");
        int cs=C.length();
        for(int i=cs-1;i>=0;--i){
            trd_tmp+=C.charAt(i);
            ++check[C.charAt(i)-'A'];
        }
        // C=new String(trd_tmp);
        int cnt=0;
        for(int i=0;i<26;++i){
            if(check[i]>0){
                ++cnt;
            }
        }
        if(cnt>10){
            System.out.print("NO");
            return;
        }
        for(int i=0;i<26;++i){
            if(check[i]>0){
                char c='A';
                c+=i;
                v.add(c);
            }
        }
        // v에 있는 수들을 0~9 중에서 분배하기
        dfs(0);
        if(finish==1){
            System.out.print("YES");
        }else{
            System.out.print("NO");
        }
    }


    public static void main(String[] args) throws IOException{
        Input();
        Solve();
    }
}


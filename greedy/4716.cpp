#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


bool comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
	return abs(a.second.first-a.second.second)>abs(b.second.first-b.second.second);
}

int main() {
	// your code goes here
	int N,A,B=0;
	while(1){
		cin>>N>>A>>B;
		if(N==0 && A==0 && B==0){
			break;
		}
		vector<pair<int,pair<int,int>>> p;
		for(int i=0;i<N;++i){
			int K,DA,DB=0;
			cin>>K>>DA>>DB;
			p.push_back({K,{DA,DB}});
		}
		sort(p.begin(), p.end(), comp);
        int ans=0;
		for(int i=0;i<N;++i){
            int da=p[i].second.first;
            int db=p[i].second.second;
            int num=p[i].first;
            if(da<db){
                if(A>=num){
                    ans+=num*da;
                    A-=num;
                }else{
                    ans+=(A*da)+(num-A)*db;
                    B-=(num-A);
                    A=0;
                    
                }
            }else if(da>db){
                if(B>=num){
                    ans+=num*db;
                    B-=num;
                }else{
                    ans+=(B*db)+(num-B)*da;
                    A-=(num-B);
                    B=0;
                    
                }
            }else{
                ans+=num*da;
            }            
        }
        cout<<ans<<"\n";
		
		
	}
	return 0;
}
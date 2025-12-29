#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll c=1;
		for(ll i=0;i<30;++i){
			c*=2;
			// cout<<c<<endl;
		}
		--c;
		ll M;
		cin>>M;
		vector<ll> m;
		m.push_back(0);
		m.push_back(5);
		m.push_back(13);
		while(1){
			ll ms=m.size();
			ll cur_num=m[ms-1]+m[ms-2]+1;
			if(cur_num>=c){
				m.push_back(cur_num);
				break;
			}else{
				m.push_back(cur_num);
			}
		}
		string s="Messi Gimossi";
		if(M<=13){
			if(s[M-1]==' '){
				cout<<"Messi Messi Gimossi";
			}else{
				cout<<s[M-1];
			}
		}else{
			ll N=3;
			while(1){
				if(m[N]>=M){
					break;
				}
				++N;
			}
			// for(ll i=0;i<m.size();++i){
			// 	cout<<m[i]<<"\n";
			// }
			// m(N)
			bool flag=0;
			string ans="";
			while(1){
				// cout<<N<<" "<<M<<endl;
				if(N<=2){
					// cout<<N<<" "<<M<<endl;
					if(s[M-1]==' '){
						flag=1;
					}
					ans+=s[M-1];
					break;
				}
				ll fst_num=m[N-1];
				ll sed_num=m[N-2];
				if(fst_num+1==M){
					flag=1;
					break;
				}
				if(M>fst_num){
					M-=fst_num+1;
					N-=2;
				}else{
					// fst_num<=M
					--N;
				}
			}
			if(flag){
				cout<<"Messi Messi Gimossi";
			}else{
				cout<<ans;
			}
		}
	}
	return 0;
}
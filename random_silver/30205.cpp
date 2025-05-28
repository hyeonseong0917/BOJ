#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,m,p;
		cin>>n>>m>>p;
		vector<ll> v[n+1];
		for(ll i=0;i<n;++i){ 
			for(ll j=0;j<m;++j){
				ll a;
				cin>>a;
				v[i].push_back(a);
			}
		}
		// p=10
		// 30 7 -1 0 1 0
		// 전투력 증가는 최대한 나중에 하는게 이득
		bool flag=0;
		for(ll i=0;i<n;++i){
			// i번째 기지를 탐색. 클리어 가능한지??
			ll cnt=0;
			for(ll j=0;j<m;++j){
				if(v[i][j]==-1){
					++cnt;
				}
			}
			sort(v[i].begin(),v[i].end());
			for(ll j=0;j<m;++j){
				if(v[i][j]==-1) continue;
				if(v[i][j]<=p){
					p+=v[i][j];
				}else{
					while(cnt>0){
						--cnt;
						p*=2;
						if(p>=v[i][j]){
							break;
						}
					}
					if(p<v[i][j]){
						flag=1;
						break;
					}
					p+=v[i][j];
				}
			}
			while(cnt>0){
				--cnt;
				p*=2;
			}
			// cout<<i<<" "<<p<<" "<<flag<<endl;
		}
		
		if(flag){
			cout<<0;
		}else{
			cout<<1;
		}
	} 
	return 0;
}
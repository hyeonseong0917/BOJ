#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <deque>
using namespace std;

#define ll long long
#define pb push_back
// g[x]: 값x는 어떤 인덱스에 있는지?
vector<ll> g[1000000+1];

// F[x]: 값x는 몇 번 등장하는지?
vector<ll> F(1000000+1,0);
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> ans(n,0);
		// [개수]{인덱스1,인덱스2,인덱스3}
		// F[x]: x의 개수
		for(ll i=0;i<n;++i){
			cin>>v[i];
			++F[v[i]];
			g[v[i]].push_back(i);
		}
		vector<ll> p[n+1];
		for(ll i=1000000;i>=1;--i){
			if(F[i]){
				for(ll j=0;j<g[i].size();++j){
					p[F[i]].push_back(g[i][j]);
				}
			}
		}

		vector<ll> tmp;
		for(ll i=n;i>=1;--i){
			// i개를 가지는 요소들에 대해
			if(p[i].empty()) continue;
			for(ll j=0;j<p[i].size();++j){
				ll cur_idx=p[i][j];
				// // tmp에서 cur_idx보다 뒤에 있는 값이 있는지?
				ll L=0;
				ll R=-1;
				if(!tmp.empty()){
					R=tmp.size()-1;
				}
				ll min_idx=2023101800;
				// cout<<cur_idx<<endl;
				while(L<=R){
					// cout<<L<<" "<<R<<endl;
					ll mid=(L+R)/2;
					if(tmp[mid]>=cur_idx){
						min_idx=min(min_idx,mid);
						R=mid-1;
					}else{
						L=mid+1;
					}
				}
				if(min_idx==2023101800){
					ans[cur_idx]=-1;
				}else{
					ans[cur_idx]=v[tmp[min_idx]];
				}
			}
			for(ll j=0;j<p[i].size();++j){
				tmp.push_back(p[i][j]);
			}
			sort(tmp.begin(),tmp.end());
		}
		
		for(ll i=0;i<ans.size();++i){
			cout<<ans[i]<<" ";
		}
	}
		

	return 0;
}
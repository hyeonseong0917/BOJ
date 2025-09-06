#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.second<b.second;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll m,n;
		cin>>m>>n;
		// m개의 우주가 있음. 각 우주에는 n개의 행성 존재
		vector<ll> v[m],tmp[m];
		for(ll i=0;i<m;++i){
			for(ll j=0;j<n;++j){
				ll a;
				cin>>a;
				v[i].push_back(a);
			}
			vector<pair<ll,ll>> p;
			for(ll j=0;j<n;++j){
				p.push_back({v[i][j],j});
			}
			sort(p.rbegin(),p.rend());
			ll rank=1;
			ll cur_num=p[0].first;
			p[0].first=rank;
			for(ll j=1;j<n;++j){
				if(cur_num!=p[j].first){
					++rank;
				}
				cur_num=p[j].first;
				p[j].first=rank;
			}
			sort(p.begin(),p.end(),comp);
			for(ll j=0;j<n;++j){
				tmp[i].push_back(p[j].first);
			}
		}
		vector<vector<ll>> c;
		map<vector<ll>,ll> check;
		for(ll i=0;i<m;++i){
			vector<ll> cur_tmp=tmp[i];
			if(!check[cur_tmp]){
				c.push_back(cur_tmp);
			}
			++check[cur_tmp];
		}
		ll ans=0;
		for(ll i=0;i<c.size();++i){
			ll cur_cnt=check[c[i]];
			ans+=((cur_cnt-1)*cur_cnt)/2;
		}
		cout<<ans;
	}
	return 0;
}
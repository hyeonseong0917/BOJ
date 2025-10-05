#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<ll> check(1000000+1,0);
		vector<ll> is_prime(1000000+1,1);
		for(ll i=2;i<=sqrt(1000000);++i){
			for(ll j=i*i;j<=1000000;j+=i){
				is_prime[j]=0;
			}
		}
		vector<ll> g[n];
		for(ll i=0;i<n;++i){
			ll c=v[i];
			ll tmp_c=c;
			if(is_prime[tmp_c]){
				g[i].push_back(tmp_c);
				++check[tmp_c];
				continue;
			}
			for(ll j=2;j<=sqrt(tmp_c);++j){
				ll fst_num=j;
				ll sed_num=tmp_c/j;
				while(c%j==0){
					++check[j];
					c/=j;
					g[i].push_back(j);
				}
				if(j*j!=tmp_c && tmp_c%j==0){
					ll tj=tmp_c/j;
					while(tj%j==0){
						++check[j];
						tj/=j;
						g[i].push_back(j);
					}	
				}
			}
		}
		vector<pair<ll,ll>> p;
		ll ans_num=1, ans_cnt=0;
		for(ll i=2;i<=1000000;++i){
			ll c=check[i]/n;
			if(c){
				p.push_back({i,c});
				ans_num*=(ll)pow(i,c);
			}
		}
		
		for(ll i=0;i<n;++i){
			map<ll,ll> tmp;
			for(ll j=0;j<g[i].size();++j){
				++tmp[g[i][j]];
			}
			for(ll j=0;j<p.size();++j){
				ll cur_num=p[j].first;
				ll cur_cnt=p[j].second;
				if(cur_cnt>tmp[cur_num]){
					ans_cnt+=cur_cnt-tmp[cur_num];
				}
			}
		}
		cout<<ans_num<<" "<<ans_cnt;
	}
	return 0;
}
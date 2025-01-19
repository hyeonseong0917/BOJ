#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define ll long long

vector<ll> v[1000000+1];
vector<ll> g[5000+1];
vector<ll> q[5000+1];

int main() {
	// your code goes here
	int t=1;
	while(t--){
		ll n,m;
		cin>>n>>m;
		vector<ll> dp(n+1,1);
		vector<ll> h;
		map<ll,ll> check;
		map<ll,ll> q_check;
		for(ll i=1;i<n+1;++i){
			ll a;
			cin>>a;
			if(!check[a]){
				check[a]=1;
				h.push_back(a);
			}
			v[a].push_back(i);
			q_check[i]=a;
		}
		// q에는 높이 높은거 -> 낮은거 관계만 있고싶음
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			if(q_check[a]>q_check[b]){
				q[a].push_back(b);
			}else if(q_check[b]>q_check[a]){
				q[b].push_back(a);
			}
		}
		sort(h.rbegin(),h.rend());
		for(ll i=0;i<h.size();++i){
			ll cur_h=h[i];
			for(ll j=0;j<v[cur_h].size();++j){
				ll cur_num=v[cur_h][j];
				for(ll k=0;k<q[cur_num].size();++k){
					ll next_num=q[cur_num][k];
					dp[next_num]=max(dp[next_num],dp[cur_num]+1);
				}
			}
		}
		for(ll i=1;i<=n;++i){
			cout<<dp[i]<<"\n";
		}
	}

	return 0;
}
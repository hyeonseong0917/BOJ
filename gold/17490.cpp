#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll n,m,k;
vector<ll> v;
map<pair<ll,ll>,ll> check;
vector<vector<ll>> g;
vector<ll> visited;
ll min_dist;
void dfs(ll cur_num){
	min_dist=min(min_dist,v[cur_num]);
	for(ll i=0;i<g[cur_num].size();++i){
		ll next_num=g[cur_num][i];
		if(visited[next_num]) continue;
		visited[next_num]=1;
		dfs(next_num);
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		cin>>n>>m>>k;
		v=vector<ll>(n,0);
		g=vector<vector<ll>>(n);
		visited=vector<ll>(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			--a;
			--b;
			++check[{a,b}];
			++check[{b,a}];
		}
		if(m<=1){
			cout<<"YES";
			break;
		}
		for(ll i=0;i<n;++i){
			// i와 i-1
			ll L=(i+n-1)%n;
			// i와 i+1
			ll R=(i+n+1)%n;
			if(check[{i,R}]) continue;
			g[i].push_back(R);
			g[R].push_back(i);
		}
		// for(ll i=0;i<n;++i){
		// 	ll gs=g[i].size();
		// 	cout<<gs<<endl;
		// }
		ll ans=0;
		for(ll i=0;i<n;++i){
			if(visited[i]) continue;
			min_dist=2023101800;
			dfs(i);
			ans+=min_dist;
		}
		if(ans<=k){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
	}
	return 0;
}
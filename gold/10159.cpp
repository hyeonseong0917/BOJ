#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

ll cnt=0;
vector<ll> v[100+1],g[100+1];
map<ll,ll> check;
void dfs(ll cur_num){
	++cnt;
	for(ll i=0;i<v[cur_num].size();++i){
		if(check[v[cur_num][i]]) continue;
		++check[v[cur_num][i]];
		dfs(v[cur_num][i]);
	}
}
void r_dfs(ll cur_num){
	++cnt;
	for(ll i=0;i<g[cur_num].size();++i){
		if(check[g[cur_num][i]]) continue;
		++check[g[cur_num][i]];
		r_dfs(g[cur_num][i]);
	}
}


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n;
		cin>>m;
		
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			v[a].push_back(b);
			g[b].push_back(a);
		}
		vector<ll> ans;
		for(ll i=1;i<=n;++i){
			cnt=0;
			check.clear();
			++check[i];
			dfs(i);
			// cout<<i<<" "<<cnt<<endl;
			r_dfs(i);
			// cout<<i<<" "<<cnt<<endl;
			cout<<n-cnt+1<<"\n";
		}
	}
	return 0;
}
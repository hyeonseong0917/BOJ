#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll n;
vector<ll> v(200000+1,0);
vector<ll> g[200000+1];
bool visited[200000+1];
ll ans=0;
void dfs(ll cur_num){
	if(g[cur_num].empty()){
		return;
	}
	for(ll i=0;i<g[cur_num].size();++i){
		ll next_num=g[cur_num][i];
		if(visited[next_num]) continue;
		if(v[cur_num]!=v[next_num] && v[next_num]!=0){
			++ans;
		}
		visited[next_num]=1;
		dfs(next_num);
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n;
		for(ll i=1;i<=n;++i){
			cin>>v[i];
		}
		for(ll i=0;i<n-1;++i){
			ll a,b;
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		visited[1]=1;
		if(v[1]!=0){
			ans=1;
		}
		dfs(1);
		cout<<ans;
	}
	return 0;
}
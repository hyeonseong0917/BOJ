#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define ll long long

ll check[100000+1];
ll n,m,r;
priority_queue<ll> g[100000+1];
ll cnt=1;

void dfs(ll cur_num){
	while(!g[cur_num].empty()){
		ll next_num=g[cur_num].top()*-1;
		g[cur_num].pop();
		if(!check[next_num]){
			check[next_num]=++cnt;
			dfs(next_num);
		}
	}

}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n>>m>>r;
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			g[a].push(b*-1);
			g[b].push(a*-1);
		}
		for(ll i=1;i<=n;++i){
			check[i]=0;
		}
		check[r]=1;
		dfs(r);
		for(ll i=1;i<=n;++i){
			cout<<check[i]<<"\n";
		}
	}
	return 0;
}
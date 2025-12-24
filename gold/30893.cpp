#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll n,s,e;
vector<ll> v[100000+1];
vector<ll> visited(100000+1,0);
ll dp[100000+1][2];
ll ans=0;
// dfs(s,0)
ll dfs(ll cur_num, ll cur_play){
	// cout<<"fd"<<cur_num<<" "<<cur_play<<"\n";
	if(cur_num==e){
		return 1;
	}
	if(dp[cur_num][cur_play]!=-1) return dp[cur_num][cur_play];
	ll c;
	if(cur_play==0){
		c=0;
		for(ll i=0;i<v[cur_num].size();++i){
			ll next_num=v[cur_num][i];
			if(visited[next_num]) continue;
			visited[next_num]=1;
			c|=dfs(next_num,1);
		}
	}else{
		c=1;
		bool flag=0;
		for(ll i=0;i<v[cur_num].size();++i){
			ll next_num=v[cur_num][i];
			if(visited[next_num]) continue;
			flag=1;
			visited[next_num]=1;
			c&=dfs(next_num,0);
		}
		if(!flag){
			c=0;
		}
	}
	return dp[cur_num][cur_play]=c;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n>>s>>e;
		for(ll i=0;i<n-1;++i){
			ll a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(ll i=0;i<=n;++i){
			for(ll j=0;j<2;++j){
				dp[i][j]=-1;
			}
		}
		bool flag=0;
		visited[s]=1;
		dfs(s,0);
		if(dp[s][0]==1){
			cout<<"First";
		}else{
			cout<<"Second";
		}
	}
	return 0;
}
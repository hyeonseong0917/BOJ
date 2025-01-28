#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

vector<ll> v[1000+1];
ll cost[1000+1][1000+1];
ll dp[1000+1];
ll dfs(ll cur_num, ll parent){
	if(dp[cur_num]!=-1) return dp[cur_num];
	if(v[cur_num].size()==1 && parent!=-1){
		return dp[cur_num]=2023101800;
	}
	ll ret=0;
	for(ll i=0;i<v[cur_num].size();++i){
		ll next_num=v[cur_num][i];
		if(next_num==parent) continue;
		ret+=min(cost[cur_num][next_num],dfs(next_num,cur_num));
	}
	return dp[cur_num]=ret;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	cin>>o;
	while(o--){
		ll n,m;
		cin>>n>>m;
		for(ll i=1;i<=1000;++i){
			v[i].clear();
			dp[i]=-1;
			for(ll j=1;j<=1000;++j){
				cost[i][j]=0;
			}
		}
		for(ll i=0;i<m;++i){
			ll a,b,d;
			cin>>a>>b>>d;
			v[a].push_back(b);
			v[b].push_back(a);
			cost[a][b]=d;
			cost[b][a]=d;
		}
		cout<<dfs(1,-1)<<"\n";
		
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

vector<ll> g[100000+1];
vector<ll> dp(100000+1,0);
int dfs(ll cur_num, ll pre_num){
	if(g[cur_num].size()==1 && g[cur_num][0]==pre_num){
		return 0;
	}
	ll max_num=0;
	for(ll i=0;i<g[cur_num].size();++i){
		ll next_num=g[cur_num][i];
		if(next_num==pre_num) continue;
		max_num=max(max_num,dfs(next_num,cur_num)+(ll)1);
	}
	return dp[cur_num]=max_num;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,s,d;
		cin>>n>>s>>d;
		
		for(ll i=0;i<n-1;++i){
			ll x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(s,0);
		ll ans=0;
		for(ll i=1;i<=n;++i){
			if(i==s) continue;
			if(dp[i]>=d) ++ans;
		}
		cout<<ans*2;
	}
	return 0;
}
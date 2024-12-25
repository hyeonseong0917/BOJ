#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long


vector<vector<ll>> v;
vector<ll> visited;
vector<ll> c;
ll cnt=0;
ll sum=0;
void dfs(ll cur_num){
	for(ll i=0;i<v[cur_num].size();++i){
		ll next_num=v[cur_num][i];
		if(!visited[next_num]){
			visited[next_num]=1;
			++cnt;
			sum+=c[next_num];
			dfs(next_num);
		}

	}
}
vector<pair<ll,ll>> score;

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m,k;
		cin>>n>>m>>k;
		vector<ll> dp(k+1,0);
		for(ll i=0;i<=n;++i){
			vector<ll> tmp;
			v.push_back(tmp);
		}
		visited=vector<ll>(n+1,0);
		c.push_back(0);
		for(ll i=1;i<=n;++i){
			ll a;
			cin>>a;
			c.push_back(a);
		}
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(ll i=1;i<=n;++i){
			if(!visited[i]){
				visited[i]=1;
				sum=c[i];
				cnt=1;
				dfs(i);
				score.push_back({cnt,sum});
			}
		}
		ll ans=0;
		for(ll i=0;i<score.size();++i){
			ll cur_num=score[i].first;
			ll cur_score=score[i].second;
			for(ll j=k-1;j>=cur_num;--j){
				dp[j]=max(dp[j-cur_num]+cur_score,dp[j]);
				ans=max(ans,dp[j]);
			}
		}
		// cout<<dp[k]
		cout<<ans;
	}
	return 0;
}
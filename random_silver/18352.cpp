#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	while(t--){
		ll n,m,k,x;
		cin>>n>>m>>k>>x;
		vector<ll> v[n+1];
		ll max_dist=1222232421;
		vector<ll> dp(n+1,max_dist);
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			v[a].push_back(b);
		}
		// x에서 최단거리가 k인 곳?
		dp[x]=0;
		priority_queue<pair<ll,ll>> pq;
		pq.push({0,x});
		while(!pq.empty()){
			ll cur_num=pq.top().second;
			ll cur_dist=pq.top().first*-1;
			pq.pop();
			for(ll i=0;i<v[cur_num].size();++i){
				ll next_num=v[cur_num][i];
				if(dp[next_num]>dp[cur_num]+1){
					dp[next_num]=dp[cur_num]+1;
					pq.push({dp[next_num]*-1,next_num});
				}
			}
		}
		vector<ll> ans;
		for(ll i=1;i<=n;++i){
			// cout<<i<<" "<<dp[i]<<endl;
			if(dp[i]==k){
				ans.push_back(i);
			}
		}
		if(ans.empty()){
			cout<<-1;
		}else{
			for(ll i=0;i<ans.size();++i){
				cout<<ans[i]<<"\n";
			}
		}
	}
	return 0;
}
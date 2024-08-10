#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

const int MAX=500+1;

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v[MAX];
		vector<ll> dp(MAX,50000000+1);
		vector<ll> cost(n+1,0);
		vector<ll> tmp[MAX];
		for(ll i=0;i<n;++i){
			ll a=0;
			cin>>a;
			cost[i+1]=a;
			while(1){
				ll b;
				cin>>b;
				if(b==-1) break;
				v[i+1].push_back(b);
				tmp[b].push_back(i+1);
			}
		}
		queue<ll> q;
		for(ll i=1;i<=n;++i){
			if(v[i].empty()){
				dp[i]=cost[i];
				q.push(i);
			}
		}
		while(!q.empty()){
			ll cur_num=q.front();
			q.pop();
			for(ll i=0;i<tmp[cur_num].size();++i){
				ll next_num=tmp[cur_num][i];
				ll next_cost=cost[next_num];
				ll max_next_cost=0;
				for(ll j=0;j<v[next_num].size();++j){
					max_next_cost=max(max_next_cost, dp[v[next_num][j]]);
				}
				if(dp[next_num]>next_cost+max_next_cost){
					dp[next_num]=next_cost+max_next_cost;
					q.push(next_num);
				}
			}
		}
		for(ll i=1;i<=n;++i){
			cout<<dp[i]<<"\n";
		}
	}
	return 0;
}
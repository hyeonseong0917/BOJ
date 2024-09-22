#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

ll n;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n;
		vector<ll> v[n+1];
		vector<ll> parent(n+1,0);
		vector<ll> check(n+1,0);
		vector<ll> dp(n+1,0);
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			if(i==0) continue;
			v[a].push_back(i);
			parent[i]=a;
		}
		queue<ll> leaf;
		for(ll i=1;i<=n;++i){
			if(v[i].empty()){
				leaf.push(i);
			}
		}
		while(!leaf.empty()){
			ll cur_num=leaf.front();
			leaf.pop();
			ll next_num=parent[cur_num];
			++check[next_num];
			ll next_vs=v[next_num].size();
			if(check[next_num]==next_vs){
				leaf.push(next_num);
			}

			priority_queue<pair<ll,ll>> pq;
			for(ll i=0;i<v[next_num].size();++i){
				ll child_num=v[next_num][i];
				pq.push({dp[child_num],child_num});
			}
			ll cur_time=1;
			while(!pq.empty()){
				ll cur_dp=pq.top().first;
				ll child_num=pq.top().second;
				pq.pop();
				dp[next_num]=max(dp[next_num],dp[child_num]+cur_time);
				++cur_time;
			}
		}
		cout<<dp[0];
		
	}
	return 0;
}
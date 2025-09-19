#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v[n];
		vector<ll> check(n,0);
		vector<ll> visited(n,0);
		for(ll i=0;i<n-1;++i){
			ll a,b;
			cin>>a>>b;
			v[b].push_back(a);
			++check[a];
		}
		vector<ll> p(n,0);
		vector<ll> dp(n,0);
		
		for(ll i=0;i<n;++i){
			cin>>p[i];
			dp[i]=p[i];
		}
		queue<ll> q;
		for(ll i=0;i<n;++i){
			if(!check[i]){
				q.push(i);
			}
		}
		while(!q.empty()){
			ll cur_num=q.front();
			q.pop();
			for(ll i=0;i<v[cur_num].size();++i){
				ll next_num=v[cur_num][i];
				dp[next_num]+=max(0ll,dp[cur_num]);
				++visited[next_num];
				if(visited[next_num]==check[next_num]){
					q.push(next_num);
				}
			}
		}
		cout<<dp[0];
		// for(ll i=0;i<n;++i){
		// 	cout<<i<<" "<<dp[i]<<"\n";
		// }
	}
	return 0;
}
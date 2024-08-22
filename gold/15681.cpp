#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,r,Q;
		cin>>n>>r>>Q;
		vector<ll> v[n+1];
		vector<ll> dp(n+1,0);
		for(ll i=0;i<n-1;++i){
			ll a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		vector<ll> out_graph[n+1];
		vector<ll> in_graph[n+1];
		vector<bool> visited(n+1,0);
		queue<ll> gq;
		gq.push(r);
		visited[r]=1;
		while(!gq.empty()){
			ll cur_num=gq.front();
			gq.pop();
			for(ll i=0;i<v[cur_num].size();++i){
				ll next_num=v[cur_num][i];
				if(visited[next_num]) continue;
				visited[next_num]=1;
				out_graph[cur_num].push_back(next_num);
				in_graph[next_num].push_back(cur_num);
				gq.push(next_num);
			}
		}

		queue<ll> q;
		for(ll i=1;i<=n;++i){
			if(out_graph[i].empty()){
				q.push(i);
			}
			dp[i]=1;
		}
		vector<ll> check(n+1,0);
		while(!q.empty()){
			ll cur_num=q.front();
			q.pop();
			if(cur_num==r) break;
			ll next_num=in_graph[cur_num][0];
			
			dp[next_num]+=dp[cur_num];
			++check[next_num];
			ll out_size=out_graph[next_num].size();
			if(check[next_num]==out_size){
				q.push(next_num);
			}
		}
		for(ll i=0;i<Q;++i){
			ll a=0;
			cin>>a;
			cout<<dp[a]<<"\n";
		}
	}
	return 0;
}
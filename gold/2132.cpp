#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll n;
vector<ll> v(10000+1,0);
vector<ll> visited(10000+1,0);
vector<ll> g[10000+1];
ll sum=0;
void dfs(ll cur_num, ll cur_sum){
	sum=max(sum,cur_sum);
	for(ll i=0;i<g[cur_num].size();++i){
		ll next_num=g[cur_num][i];
		if(visited[next_num]) continue;
		visited[next_num]=1;
		dfs(next_num,cur_sum+v[next_num]);
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n;
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		for(ll i=0;i<n-1;++i){
			ll a,b;
			cin>>a>>b;
			--a;
			--b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		ll max_num=-1;
		ll max_pos=-1;
		for(ll i=0;i<n;++i){
			sum=0;
			for(ll j=0;j<n;++j){
				visited[j]=0;
			}
			++visited[i];
			dfs(i,v[i]);
			if(max_num<sum){
				max_num=sum;
				max_pos=i+1;
			}
		}
		cout<<max_num<<" "<<max_pos;
	}
	return 0;
}
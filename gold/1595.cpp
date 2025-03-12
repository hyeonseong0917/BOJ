#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

vector<pair<ll,ll>> v[10000+1];
ll n;
bool visited[10000+1];
ll max_dist=0;
ll max_node=0;
ll max_num=0;

void dfs(ll cur_num, ll cur_dist){
	if(max_dist<cur_dist){
		max_dist=cur_dist;
		max_num=max(max_num,cur_dist);
		max_node=cur_num;
	}
	for(ll i=0;i<v[cur_num].size();++i){
		ll next_num=v[cur_num][i].first;
		ll next_dist=v[cur_num][i].second;
		if(visited[next_num]) continue;
		visited[next_num]=1;
		dfs(next_num,cur_dist+next_dist);
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	ll a,b,c;
	while(cin>>a>>b>>c){
		v[a].push_back({b,c});
		v[b].push_back({a,c});
		n=max(n,max(a,b));
	}
	for(ll i=0;i<=n;++i){
		visited[i]=0;
	}
	visited[1]=1;
	dfs(1,0);
	for(ll i=0;i<=n;++i){
		visited[i]=0;
	}
	visited[max_node]=1;
	dfs(max_node,0);
	cout<<max_num;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

vector<pair<ll,ll>> g[1000+1];
vector<pair<ll,pair<ll,ll>>> tmp;
bool comp(pair<ll,pair<ll,ll>> a, pair<ll,pair<ll,ll>> b){
	return a.first>b.first;
}
vector<ll> parent(1000+1);
ll FIND(ll x){
	if(parent[x]==x) return x;
	return parent[x]=FIND(parent[x]);
}
void UNION(ll x, ll y){
	x=FIND(x);
	y=FIND(y);
	if(x!=y){
		parent[x]=y;
	}

}
ll cur_dist=2023101800;
bool visited[1000+1];
ll c,v;
void dfs(ll cur_num, ll min_num){
	if(cur_num==v){
		cur_dist=min(cur_dist,min_num);
		return;
	}
	for(ll i=0;i<g[cur_num].size();++i){
		ll next_num=g[cur_num][i].first;
		ll next_dist=g[cur_num][i].second;
		if(!visited[next_num]){
			visited[next_num]=1;
			dfs(next_num,min(next_dist,min_num));
		}
	}

}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		// p개의 지점과 w개의 길
		ll p,w;
		cin>>p>>w;
		for(ll i=0;i<p;++i){
			parent[i]=i;
		}
		
		cin>>c>>v;
		// 가장 좁은 길의 너비를 최대화하도록
		// c에서 v로 가고싶음음
		for(ll i=0;i<w;++i){
			ll x,y,z;
			cin>>x>>y>>z;
			tmp.push_back({z,{x,y}});
		}
		sort(tmp.begin(),tmp.end(),comp);

		for(ll i=0;i<w;++i){
			ll x=tmp[i].second.first;
			ll y=tmp[i].second.second;
			ll z=tmp[i].first;
			if(FIND(x)!=FIND(y)){
				UNION(x,y);
				g[x].push_back({y,z});
				g[y].push_back({x,z});
			}
		}
		visited[c]=1;
		dfs(c,2023101800);
		cout<<cur_dist;
	}
	return 0;
}
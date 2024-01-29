#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define ll long long
ll N, start_pos, fin_pos;
const ll MAX=100000+1;
vector<pair<ll,ll>> v[MAX];
bool visited[MAX];
void Input(){
	cin>>N>>start_pos>>fin_pos;
	for(ll i=0;i<N-1;++i){
		ll a,b,c;
		cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
		visited[i+1]=0;
	}
}
ll ans=0;
void dfs(ll cur_pos, ll cur_max_dist, ll cur_sum){
	if(cur_pos==fin_pos){
		ans=cur_sum-cur_max_dist;
		return;
	}
	for(ll i=0;i<v[cur_pos].size();++i){
		ll next_pos=v[cur_pos][i].first;
		ll next_dist=v[cur_pos][i].second;
		if(!visited[next_pos]){
			visited[next_pos]=1;
			dfs(next_pos, max(cur_max_dist, next_dist), cur_sum+next_dist);
		}
	}

}
void solve(){
	visited[start_pos]=1;
	dfs(start_pos, 0, 0);
	cout<<ans;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	
	return 0;
}
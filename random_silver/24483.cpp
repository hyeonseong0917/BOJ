#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
int N,M,R;
const int MAX=100000+1;
vector<ll> g[MAX];
ll depth[MAX];
ll visited_order[MAX];
void Input(){
	cin>>N>>M>>R;
	for(ll i=0;i<M;++i){
		ll u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(ll i=1;i<MAX;++i){
		sort(g[i].begin(),g[i].end());
	}
	for(ll i=0;i<MAX;++i){
		depth[i]=-1;
		visited_order[i]=0;
	}
	depth[R]=0;
	visited_order[R]=1;
}
//
ll cnt=2;
void dfs(ll cur_pos){
	for(ll i=0;i<g[cur_pos].size();++i){
		ll next_pos=g[cur_pos][i];
		if(visited_order[next_pos]==0){
			depth[next_pos]=depth[cur_pos]+1;
			visited_order[next_pos]=cnt++;
			dfs(next_pos);
		}
	}
}
void solve(){
	dfs(R);
	long long sum=0;
	for(int i=1;i<=N;++i){
		// cout<<i<<" "<<visited_order[i]<<" "<<depth[i]<<endl;
		long long k=depth[i]*visited_order[i];
		sum+=k;
	}
	cout<<sum;
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}
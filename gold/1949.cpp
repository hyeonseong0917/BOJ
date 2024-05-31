#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define ll long long

ll n;
const ll MAX=10000+1;
vector<ll> v,parent;
vector<ll> g[MAX];
vector<ll> new_graph[MAX];
bool visited[MAX];
ll dp[MAX][2];
void Input(){
	cin>>n;
	v=vector<ll>(n+1,0);
	for(ll i=1;i<=n;++i){
		cin>>v[i];
		for(ll j=0;j<2;++j){
			dp[i][j]=0;
		}
	}
	for(ll i=0;i<n-1;++i){
		ll a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}
void dfs(ll cur_node){
	visited[cur_node]=1;
	dp[cur_node][0]=0;
	dp[cur_node][1]=v[cur_node];
	for(ll i=0;i<g[cur_node].size();++i){
		ll next_node=g[cur_node][i];
		if(!visited[next_node]){
			dfs(next_node);
			dp[cur_node][0]+=max(dp[next_node][0],dp[next_node][1]);
			dp[cur_node][1]+=dp[next_node][0];
		}
	}

}

void solve(){
	dfs(1);
	cout<<max(dp[1][0],dp[1][1]);
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);	
	Input();
	solve();
	return 0;
}
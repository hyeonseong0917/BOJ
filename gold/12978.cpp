#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

vector<ll> v[100000+1];
ll dp[100000+1][2];
bool visited[100000+1];
void dfs(ll cur_num){
	dp[cur_num][1]=1;
	for(ll i=0;i<v[cur_num].size();++i){
		ll next_num=v[cur_num][i];
		if(visited[next_num]) continue;
		visited[next_num]=1;
		dfs(next_num);
		dp[cur_num][1]+=min(dp[next_num][0],dp[next_num][1]);
		dp[cur_num][0]+=dp[next_num][1];
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// dp[x][0]: x번째 노드를 칠하지 않았을 때 x를 루트로 하는 서브트리 모두 감시하기 위한 최소
		// dp[x][1]: x번째 노드를 칠했을 때 ...
		// dp[x][1]=1+min(dp[x1][0],dp[x1][1])+min(dp[])
		ll n;
		cin>>n;
		for(ll i=0;i<n-1;++i){
			ll a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
			dp[i+1][0]=0;
			dp[i+1][1]=0;
		}
		visited[1]=1;
		dfs(1);
		ll ans=min(dp[1][0],dp[1][1]);
		cout<<ans;
	}
	return 0;
}
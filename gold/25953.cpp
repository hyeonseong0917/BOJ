#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long


ll dp[1000+1][10000+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll INF=2023101800;
		ll n,t,m;
		cin>>n>>t>>m;
		for(ll i=0;i<=t;++i){
			for(ll j=0;j<=n;++j){
				dp[i][j]=INF;
			}
		}
		
		ll s,e;
		cin>>s>>e;
		// 정점은 [0,n-1]까지 있음. 정점은 최대 10000
		// 시간은 [1,t]까지 정의됨. 시간은 최대 1000
		// 각 시간마다 m개씩의 간선들이 업데이트됨
		// dp[i][j]: i시간에 j정점에 있을 때의 최소 시간
		dp[0][s]=0;
		for(ll i=1;i<=t;++i){
			// i시간에 j정점에 있는 경우인데, i시간에 아무것도 안하는 경우
			for(ll j=0;j<n;++j){
				dp[i][j]=min(dp[i][j],dp[i-1][j]);
			}
			// dp[i][x]=min(dp[i][x],dp[i-1][y]+c)
			for(ll j=0;j<m;++j){
				ll a,b,c;
				cin>>a>>b>>c;
				// a와 b를 잇는 cost가 c임
				// b와 a를 잇는 cost가 c임
				dp[i][a]=min(dp[i][a],dp[i-1][b]+c);
				dp[i][b]=min(dp[i][b],dp[i-1][a]+c);
			}
		}
		if(dp[t][e]==INF){
			dp[t][e]=-1;
		}
		cout<<dp[t][e];
	}
	return 0;
}
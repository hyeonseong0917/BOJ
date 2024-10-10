#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

const int MAX=500+1;
ll dp[MAX][MAX];
ll INF=2023101800;

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		for(ll i=0;i<MAX;++i){
			for(ll j=0;j<MAX;++j){
				if(i==j) continue;
				dp[i][j]=INF;
			}
		}
		ll n,m;
		cin>>n>>m;
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			dp[a][b]=1;
		}
		for(ll k=1;k<=n;++k){
			for(ll i=1;i<=n;++i){
				for(ll j=1;j<=n;++j){
					if(dp[i][j]>dp[i][k]+dp[k][j]){
						dp[i][j]=dp[i][k]+dp[k][j];
					}
				}
			}
		}
		ll ans=0;
		for(ll i=1;i<=n;++i){
			// i번째 사람에 대해
			bool flag=0;
			for(ll j=1;j<=n;++j){
				if(i==j) continue;
				if(dp[i][j]==INF && dp[j][i]==INF){
					flag=1;
				}
			}
			if(!flag) ++ans;
		}
		cout<<ans;
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long
ll dp[100+1][100+1];
ll INF=2023101800;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<bool> check(n,0);
		for(ll i=0;i<m;++i){
			ll a;
			cin>>a;
			check[a]=1;
		}
		for(ll i=0;i<=100;++i){
			for(ll j=0;j<=100;++j){
				dp[i][j]=INF;
			}
		}
		dp[0][0]=0;
		ll max_ticket=(n/5)*2;
		if(n%5>=3){
			++max_ticket;
		}
		for(ll i=1;i<=n;++i){
			
			if(check[i]){
				for(ll j=0;j<=max_ticket;++j){
					if(i>=1 && dp[i-1][j]!=INF){
						dp[i][j]=min(dp[i][j],dp[i-1][j]);
					}
					if(i>=3 && j>=1 && dp[i-3][j-1]!=INF){
						dp[i][j]=min(dp[i][j],dp[i-3][j-1]+25000);
					}
					if(i>=5 && j>=2 && dp[i-5][j-2]!=INF){
						dp[i][j]=min(dp[i][j],dp[i-5][j-2]+37000);
					}
					// dp[i][j]=min(dp[i][j],dp[i-1][j+1]);
				}
			}else{
				for(ll j=0;j<=max_ticket;++j){
					bool flag=0;
					if(i==100 && j==95){
						flag=1;
						cout<<"fds";
					}
					if(i>=1 && dp[i-1][j]!=INF){
						dp[i][j]=min(dp[i][j],dp[i-1][j]+10000);
						// if(flag) cout<<dp[i][j];
					}
					if(i>=3 && j>=1 && dp[i-3][j-1]!=INF){
						dp[i][j]=min(dp[i][j],dp[i-3][j-1]+25000);
						// if(flag) cout<<dp[i][j];
					}
					if(i>=5 && j>=2 && dp[i-5][j-2]!=INF){
						dp[i][j]=min(dp[i][j],dp[i-5][j-2]+37000);
						// if(flag) cout<<dp[i][j];
					}
					if(dp[i-1][j+3]!=INF){
						dp[i][j]=min(dp[i][j],dp[i-1][j+3]);
						if(flag) cout<<dp[i][j];
					}
				}
			}
			
		}
		// cout<<dp[10][3]<<endl;
		ll ans=2023101800;
		for(ll i=0;i<=max_ticket;++i){
			// cout<<i<<" "<<dp[n][i]<<endl;
			ans=min(ans,dp[n][i]);
		}
		cout<<ans;
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

ll n,m;
ll INF=-2023101800;
vector<vector<ll>> board(1000,vector<ll>(1000,0));
vector<vector<ll>> fst_dp(1000,vector<ll>(1000,INF));
vector<vector<ll>> sed_dp(1000,vector<ll>(1000,INF));

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		cin>>n>>m;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cin>>board[i][j];
			}
		}
		fst_dp[n-1][0]=board[n-1][0];
		for(ll i=n-1;i>=0;--i){
			for(ll j=0;j<m;++j){
				ll c=INF;
				if(i!=n-1){
					c=max(c,fst_dp[i+1][j]);
				}
				if(j){
					c=max(c,fst_dp[i][j-1]);
				}
				if(c==INF){
					c=0;
				}
				// if(i==1 && j==0){
				// 	cout<<c<<" "<<board[i][j]<<endl;
				// }
				fst_dp[i][j]=c+board[i][j];
			}
		}
		// cout<<fst_dp[0][1];
		sed_dp[n-1][m-1]=board[n-1][m-1];
		for(ll i=n-1;i>=0;--i){
			for(ll j=m-1;j>=0;--j){
				ll c=INF;
				if(i!=n-1){
					c=max(c,sed_dp[i+1][j]);
				}
				if(j!=m-1){
					c=max(c,sed_dp[i][j+1]);
				}
				if(c==INF){
					c=0;
				}
				sed_dp[i][j]=c+board[i][j];
			}
		}
		// cout<<sed_dp[1][1];
		ll ans=INF;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				ans=max(ans,fst_dp[i][j]+sed_dp[i][j]);
			}
		}
		cout<<ans;
	}
	return 0;
}
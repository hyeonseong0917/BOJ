#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

ll board[300][300];
ll dp[300][300][11];

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				cin>>board[i][j];
				for(ll k=0;k<10;++k){
					dp[i][j][k]=0;
				}
			}
		}
		dp[0][0][board[0][0]]=1;
		for(ll i=1;i<n;++i){
			dp[0][i][board[0][i]]=1;
			for(ll j=1;j<=10;++j){
				dp[0][i][j]+=dp[0][i-1][j];
			}
		}
		for(ll i=1;i<n;++i){
			dp[i][0][board[i][0]]=1;
			for(ll j=1;j<=10;++j){
				dp[i][0][j]+=dp[i-1][0][j];
			}
		}
		for(ll i=1;i<n;++i){
			for(ll j=1;j<n;++j){
				ll c=board[i][j];
				dp[i][j][c]=1;
				for(ll k=1;k<=10;++k){
					dp[i][j][k]+=dp[i-1][j][k]+dp[i][j-1][k]-dp[i-1][j-1][k];
				}
			}
		}
		// for(ll i=1;i<=9;++i){
		// 	cout<<i<<" "<<dp[2][2][i]<<"\n";
		// }
		// cout<<dp[2][2][6];

		
		ll q;
		cin>>q;
		while(q--){
			ll a,b,c,d;
			cin>>a>>b>>c>>d;
			--a;
			--b;
			--c;
			--d;
			ll ans=0;
			for(ll i=1;i<=10;++i){
				// i는 (a,b)랑 (c,d) 사이에 존재하는지?
				ll cur_num=dp[c][d][i];
				if(!cur_num) continue;
				ll fst_num=0;
				if(b){
					fst_num=dp[c][b-1][i];
				}
				ll sed_num=0;
				if(a){
					sed_num=dp[a-1][d][i];
				}
				ll sum=fst_num+sed_num;
				if(a && b){
					sum-=dp[a-1][b-1][i];
				}
				if(cur_num==sum) continue;
				++ans;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
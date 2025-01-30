#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

ll m,n;


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	while(1){
		cin>>m>>n;
		if(m==0 && n==0){
			break;
		}
		vector<vector<ll>> board;
		vector<vector<ll>> max_dp;
		for(ll i=0;i<m;++i){
			vector<ll> tmp;
			vector<ll> c;
			for(ll j=0;j<n;++j){
				ll a;
				cin>>a;
				tmp.push_back(a);
				c.push_back(0);
			}
			board.push_back(tmp);
			max_dp.push_back(c);
		}
		
		vector<ll> dp(m,0);
		for(ll i=0;i<m;++i){
			// max_dp[i][j]
			for(ll j=0;j<n;++j){
				if(j==0 || j==1){
					if(j==0){
						max_dp[i][j]=board[i][j];
					}else{
						max_dp[i][j]=max(max_dp[i][j-1],board[i][j]);
					}
				}else{
					max_dp[i][j]=max(max_dp[i][j-1],max_dp[i][j-2]+board[i][j]);
				}
			}
		}
		for(ll i=0;i<m;++i){
			if(i==0 || i==1){
				if(i==0){
					dp[i]=max_dp[i][n-1];
				}else{
					dp[i]=max(dp[i-1],max_dp[i][n-1]);
				}
			}else{
				dp[i]=max(dp[i-1],dp[i-2]+max_dp[i][n-1]);
			}
		}
		cout<<dp[m-1]<<"\n";
	}
	return 0;
}
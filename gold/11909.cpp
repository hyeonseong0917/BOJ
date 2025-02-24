#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

ll board[2222+1][2222+1];
ll dp[2222+1][2222+1];

int main() {
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
				dp[i][j]=2023101800;
			}
		}
		// dp[i][j]: {i,j}까지 가는데 사용한 최소 비용
		// if(board[i-1][j]>board[i][j]) -> dp[i][j]=min(dp[i][j],dp[i-1][j])
		// if(board[i-1][j]<=board[i][j]) -> dp[i][j]=min(dp[i][j],dp[i-1][j]+board[i][j]-board[i-1][j]+1)
		dp[0][0]=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				if(i+1<=n-1){
					if(board[i][j]>board[i+1][j]){
						dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
					}else{
						dp[i+1][j]=min(dp[i+1][j],dp[i][j]+board[i+1][j]-board[i][j]+1);
					}
				}
				if(j+1<=n-1){
					if(board[i][j]>board[i][j+1]){
						dp[i][j+1]=min(dp[i][j+1],dp[i][j]);
					}else{
						dp[i][j+1]=min(dp[i][j+1],dp[i][j]+board[i][j+1]-board[i][j]+1);
					}
				}
			}
		}
		cout<<dp[n-1][n-1];
	}
	return 0;
}
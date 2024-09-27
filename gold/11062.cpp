#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

ll dp[32+1][32+1][3+1];
ll dy[3]={1,1,0};
ll dx[3]={0,1,1};
ll board[32+1][32+1];
ll n;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<n);
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				cin>>board[i][j];
				for(ll k=0;k<4;++k){
					dp[i][j][k]=0;
				}
			}
		}
		if(!board[0][2]){
			dp[0][2][2]=1;
		}
		if(!board[1][2] && !board[0][2] && !board[1][1]){
			dp[1][2][1]=1;
		}
		
		for(ll i=0;i<n;++i){
			for(ll j=2;j<n;++j){
				for(ll k=0;k<3;++k){
					if(board[i][j]) continue;
					if(k==0){
						if(isRange(i-dy[0],j-dx[0]) && !board[i-dy[0]][j-dx[0]]){
							dp[i][j][0]+=dp[i-dy[0]][j-dx[0]][0];
						}
						if(isRange(i-dy[0],j-dx[0]) && !board[i-dy[0]][j-dx[0]]){
							dp[i][j][0]+=dp[i-dy[0]][j-dx[0]][1];
						}
					}else if(k==1){
						if(board[i-1][j] || board[i][j-1] || board[i-1][j-1]){
							continue;
						}
						if(isRange(i-dy[1],j-dx[1])){
							dp[i][j][1]+=dp[i-dy[1]][j-dx[1]][0];
						}
						if(isRange(i-dy[1],j-dx[1])){
							dp[i][j][1]+=dp[i-dy[1]][j-dx[1]][1];
						}
						if(isRange(i-dy[1],j-dx[1])){
							dp[i][j][1]+=dp[i-dy[1]][j-dx[1]][2];
						}
					}else{
						if(isRange(i-dy[2],j-dx[2]) && !board[i-dy[2]][j-dx[2]]){
							dp[i][j][2]+=dp[i-dy[2]][j-dx[2]][2];
						}
						if(isRange(i-dy[2],j-dx[2]) && !board[i-dy[2]][j-dx[2]]){
							dp[i][j][2]+=dp[i-dy[2]][j-dx[2]][1];
						}
					}
				}
			}
		}
		cout<<dp[n-1][n-1][0]+dp[n-1][n-1][1]+dp[n-1][n-1][2];
	}
	return 0;
}
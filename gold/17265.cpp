#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
using namespace std;

#define ll long long
#define pb push_back

char board[5+1][5+1];
ll dp[5+1][5+1],mdp[5+1][5+1];

ll calc(ll dp_num, ll board_num, char c){
	if(c=='+'){
		return dp_num+board_num;
	}
	if(c=='-'){
		return dp_num-board_num;
	}
	if(c=='*'){
		return dp_num*board_num;
	}
	return -1;
}

ll n;
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<n);
}
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};

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
				dp[i][j]=-2023101800;
				mdp[i][j]=2023101800;
			}
		}
		dp[0][0]=board[0][0]-'0';
		mdp[0][0]=board[0][0]-'0';
		for(ll i=2;i<n;++i){
			if(i%2==0){
				dp[0][i]=calc(dp[0][i-2],board[0][i]-'0',board[0][i-1]);
				mdp[0][i]=calc(mdp[0][i-2],board[0][i]-'0',board[0][i-1]);
			}
		}
		for(ll i=2;i<n;++i){
			if(i%2==0){
				dp[i][0]=calc(dp[i-2][0],board[i][0]-'0',board[i-1][0]);
				mdp[i][0]=calc(mdp[i-2][0],board[i][0]-'0',board[i-1][0]);
			}
		}
		for(ll i=1;i<n;++i){
			for(ll j=1;j<n;++j){
				if(board[i][j]=='+' || board[i][j]=='-' || board[i][j]=='*') continue;
				if(isRange(i-2,j)){
					dp[i][j]=max(dp[i][j],calc(dp[i-2][j],board[i][j]-'0',board[i-1][j]));
					mdp[i][j]=min(mdp[i][j],calc(mdp[i-2][j],board[i][j]-'0',board[i-1][j]));
				}
				if(isRange(i-1,j-1)){
					dp[i][j]=max(dp[i][j],calc(dp[i-1][j-1],board[i][j]-'0',board[i-1][j]));
					dp[i][j]=max(dp[i][j],calc(dp[i-1][j-1],board[i][j]-'0',board[i][j-1]));

					mdp[i][j]=min(mdp[i][j],calc(mdp[i-1][j-1],board[i][j]-'0',board[i-1][j]));
					mdp[i][j]=min(mdp[i][j],calc(mdp[i-1][j-1],board[i][j]-'0',board[i][j-1]));
				}
				if(isRange(i,j-2)){
					dp[i][j]=max(dp[i][j],calc(dp[i][j-2],board[i][j]-'0',board[i][j-1]));
					mdp[i][j]=min(mdp[i][j],calc(mdp[i][j-2],board[i][j]-'0',board[i][j-1]));
				}
			}
		}
		cout<<dp[n-1][n-1]<<" "<<mdp[n-1][n-1];
	}
	return 0;
}
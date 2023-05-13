#include <iostream>
using namespace std;

int N,M=0;
const int MAX=1000+1;
int board[MAX][MAX];
int dp[MAX][MAX];
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
			dp[i][j]=0;
		}
	}
	// dp[0][0]=board[0][0];
}
void solve(){
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(i>0){
				dp[i][j]=max(dp[i-1][j],dp[i][j]);
			}
			if(j>0){
				dp[i][j]=max(dp[i][j-1],dp[i][j]);
			}
			dp[i][j]+=board[i][j];
		}
	}
}
int main() {
	// your code goes here
	Input();
	solve();
	cout<<dp[N-1][M-1];
	return 0;
}
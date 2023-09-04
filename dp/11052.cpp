#include <iostream>
using namespace std;

int N,M=0;
const int PMAX=1000+1;
const int DPMAX=10000+1;
int p[PMAX];
int dp[DPMAX];
void Input(){
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>p[i];
	}
	dp[1]=p[1];
	// dp[0][0]=board[0][0];
}
void solve(){
	for(int i=2;i<=N;++i){
		for(int j=1;j<i;++j){
			dp[i]=max(dp[i],max(p[i],dp[i-j]+dp[j]));
		}
	}
	cout<<dp[N];
}
int main() {
	// your code goes here
	Input();
	solve();
	
	return 0;
}
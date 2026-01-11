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

// 1<=k<=n , k*k의 정사각형 만큼을 가져갈 수 있음
// 형곤이의 이익을 높여야 하므로 최대로 가져가는게 목적임
// n<=300, |board[i][j]|<=1000
// i,j좌표에서 길이가 k인 정사각형을 가져감
// 300*300*300*300 -> x
// dp[i][j][k]=dp[i][j][k-1]+psum[](a)+psum[](b)-board[i][j]
// a: board[i+k-1][j]에서 board[i+k-1][j+k-1]까지의 합
// b: board[i][j+k-1]에서 board[i][j+k-1]까지의 합
// a_psum[i][j]: board[i][0]에서 board[i][j]까지의 합
// b_psum[i][j]: board[0][0]에서 board[i][0]
// (0,0,1)부터 (n-1,n-1,1)까지 확인
int n;
int board[300+1][300+1];
int dp[300+1][300+1][300+1];
int a_psum[300+1][300+1];
int b_psum[300+1][300+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		cin>>n;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
			a_psum[i][j]=0;
			b_psum[i][j]=0;
			cin>>board[i][j];
			for(int k=0;k<=n;++k){
				dp[i][j][k]=0;
			}
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
			if(!j){
				a_psum[i][j]=board[i][j];
				continue;
			}
			a_psum[i][j]=a_psum[i][j-1]+board[i][j];
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
			if(!j){
				b_psum[j][i]=board[j][i];
				continue;
			}
			b_psum[j][i]=b_psum[j-1][i]+board[j][i];
			}
		}
		int ans=-1000;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
			for(int k=1;k<=n;++k){
				if(i+k-1>=n || j+k-1>=n) break;
				int a=a_psum[i+k-1][j+k-1]-a_psum[i+k-1][j]+board[i+k-1][j];
				int b=b_psum[i+k-1][j+k-1]-b_psum[i][j+k-1]+board[i][j+k-1];
				dp[i][j][k]=dp[i][j][k-1]+a+b-board[i+k-1][j+k-1];
				// cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<"\n";
				ans=max(ans,dp[i][j][k]);
			}
			}
		}
		cout<<ans;

	}
	return 0;
}

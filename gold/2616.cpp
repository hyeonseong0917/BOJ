#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

const int MAX=50000+1;
int arr[MAX];
int dp[MAX][3+1];
int psum[MAX];
int N,M;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	cin>>M;
	psum[0]=arr[0];
	for(int i=1;i<N;++i){
		psum[i]=psum[i-1]+arr[i];
	}
	for(int i=0;i<MAX;++i){
		for(int j=0;j<4;++j){
			dp[i][j]=0;
		}
	}
	dp[M-1][1]=psum[M-1];
	for(int i=M;i<N;++i){
		for(int j=1;j<=3;++j){
			if(j==1){
				dp[i][j]=max(dp[i-1][j],psum[i]-psum[i-M]);
			}else{
				dp[i][j]=max(dp[i-1][j],psum[i]-psum[i-M]+dp[i-M][j-1]);
			}
		}
	}
	int ans=0;
	for(int i=(M*3)-1;i<N;++i){
		ans=max(ans,dp[i][3]);
	}
	cout<<ans;
	return 0;
}
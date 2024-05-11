#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

int dp[2000+1][2000+1];
int main() {
	// your code goes here
	for(int i=0;i<2000+1;++i){
		for(int j=0;j<2000+1;++j){
			dp[i][j]=0;
		}
	}
	int t=1;
	while(t--){
		int N;
		cin>>N;		
		vector<int> A(N+1,0),B(N+1,0);		
		for(int i=0;i<N;++i){
			cin>>A[i];
		}
		for(int i=0;i<N;++i){
			cin>>B[i];
		}
		
		for(int i=N-1;i>=0;--i){
			for(int j=N-1;j>=0;--j){
				if(A[i]>B[j]){
					dp[i][j]=B[j]+dp[i][j+1];
				}else{
					dp[i][j]=max(dp[i+1][j],dp[i+1][j+1]);
				}
				
			}
		}
		cout<<dp[0][0];
	}

	return 0;
}
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll A,B,C;
		cin>>A>>B>>C;
		string X,Y;
		cin>>X;
		cin>>Y;
		ll xs=X.size();
		ll ys=Y.size();
		ll dp[xs+1][ys+1];
		for(ll i=0;i<xs+1;++i){
			for(ll j=0;j<ys+1;++j){
				dp[i][j]=-2023101800;
			}
		}
		if(X[0]==Y[0]){
			dp[0][0]=A;
		}else{
			dp[0][0]=max(C,B*2);
		}
		for(ll i=1;i<xs;++i){
			dp[i][0]=dp[i-1][0]+B;
			if(X[i]==Y[0]){
				dp[i][0]=max(dp[i][0],A+i*B);
			}else{
				dp[i][0]=max(dp[i][0],i*B+max(C,B*2));
			}
		}
		for(ll i=1;i<ys;++i){
			dp[0][i]=dp[0][i-1]+B;
			if(X[0]==Y[i]){
				dp[0][i]=max(dp[0][i],A+i*B);
			}else{
				dp[0][i]=max(dp[0][i],i*B+max(C,B*2));
			}
		}
		// dp[i][j]: X를 i인덱스까지, Y를 j인덱스까지 봤을 때 최댓값
		for(ll i=1;i<xs;++i){
			for(ll j=1;j<ys;++j){
				dp[i][j]=max(dp[i][j-1]+B,dp[i-1][j]+B);
				if(X[i]==Y[j]){
					dp[i][j]=max(dp[i][j],dp[i-1][j-1]+A);
				}else{
					dp[i][j]=max(dp[i][j],dp[i-1][j-1]+max(C,B*2));
					
				}
				
			}
		}
		cout<<dp[xs-1][ys-1];
		// ll ans=0;
		// for(ll i=0;i<xs;++i){
		// 	for(ll j=0;j<ys;++j){
		// 		// cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
		// 		ans=max(dp[i][j],ans);
		// 	}
		// }
		// cout<<ans;
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

vector<ll> A,B;
ll dp[1000+1][1000+1];
int main() {
	// your code goes here
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<n;++i){
		ll a=0;
		cin>>a;
		A.push_back(a);
	}
	for(ll i=0;i<m;++i){
		ll a=0;
		cin>>a;
		B.push_back(a);
	}
	// 남자 n, 여자 m
	ll sum=0;
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	
	for(ll i=0;i<1000+1;++i){
		for(ll j=0;j<1000+1;++j){
			dp[i][j]=0;
		}
	}
	for(ll i=0;i<n;++i){
		for(ll j=0;j<m;++j){
			if(i==j){
				if(i-1<0 || j-1<0){
					dp[i][j]=abs(A[i]-B[j]);	
				}else{
					dp[i][j]=dp[i-1][j-1]+abs(A[i]-B[j]);		
				}
				
			} 
			if(i>j){
				if(i-1<0 || j-1<0){
					if(i-1<0){
						dp[i][j]=abs(A[i]-B[j]);	
					}else{
						dp[i][j]=min(abs(A[i]-B[j]),dp[i-1][j]);		
					}
				}else{
					dp[i][j]=min(dp[i-1][j-1]+abs(A[i]-B[j]),dp[i-1][j]);	
				}
				
			} 
			if(i<j){
				if(i-1<0 || j-1<0){
					if(j-1<0){
						dp[i][j]=abs(A[i]-B[j]);	
					}else{
						dp[i][j]=min(abs(A[i]-B[j]),dp[i][j-1]);		
					}
				}else{
					dp[i][j]=min(dp[i-1][j-1]+abs(A[i]-B[j]),dp[i][j-1]);
				}
			} 
			// cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	cout<<dp[n-1][m-1];
	return 0;
}
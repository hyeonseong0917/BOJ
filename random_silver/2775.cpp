#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

ll dp[14+1][14+1];
void Init(){
	for(ll i=1;i<=14;++i){
		dp[0][i]=i;
	}
	for(ll i=1;i<=14;++i){
		for(ll j=1;j<=14;++j){
			dp[i][j]=0;
		}
	}
	for(ll i=1;i<=14;++i){
		for(ll j=1;j<=14;++j){
			for(ll k=1;k<=j;++k){
				dp[i][j]+=dp[i-1][k];
			}
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Init();
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		cout<<dp[n][k]<<"\n";
	}
	return 0;
}
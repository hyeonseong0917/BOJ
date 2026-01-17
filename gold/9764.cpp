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

ll dp[2000+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll mod=100999;
	for(ll i=0;i<=2000;++i){
		dp[i]=0;
	}
	dp[0]=1;
	for(ll i=1;i<=2000;++i){
		for(ll j=2000;j>=i;--j){
			dp[j]+=dp[j-i]%mod;
			dp[j]%=mod;
		}
	}
	// cout<<dp[7];
	ll o=1;
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		// n을 서로 다른 자연수의 개수로 만드는 경우의 수는 몇 개?
		cout<<dp[n]<<"\n";
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define ll long long



int main() {
	// your code goes here
	int t=1;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<ll> dp(400000+1,0);
		ll ans=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<i;++j){
				ans+=dp[v[i]-v[j]+200000];
				if(dp[v[i]-v[j]+200000]) break;
			}
			for(ll j=0;j<=i;++j){
				dp[v[i]+v[j]+200000]=1;
			}
		}
		cout<<ans<<"\n";
		
	}

	return 0;
}
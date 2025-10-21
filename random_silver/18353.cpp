#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> dp(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			dp[i]=1;
		}
		for(ll i=1;i<n;++i){
			for(ll j=0;j<i;++j){
				if(v[j]>v[i]){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			ans=max(ans,dp[i]);
		}
		cout<<n-ans;
	}
	return 0;
}
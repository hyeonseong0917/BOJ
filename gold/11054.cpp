#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
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
		vector<ll> v(n,0),l_dp(n,1), r_dp(n,1);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<1;
			break;
		}
		for(ll i=1;i<n;++i){
			for(ll j=0;j<i;++j){
				if(v[j]<v[i]){
					l_dp[i]=max(l_dp[i],l_dp[j]+1);
				}
			}
		}
		for(ll i=n-2;i>=0;--i){
			for(ll j=i+1;j<n;++j){
				if(v[j]<v[i]){
					r_dp[i]=max(r_dp[i],r_dp[j]+1);
				}
			}
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			ans=max(ans,l_dp[i]+r_dp[i]-1);
		}
		cout<<ans;
	}
	return 0;
}
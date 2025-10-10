#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<ll> fst_dp(n,0), sed_dp(n,0);
		if(v[0]==1){
			fst_dp[0]=1;
		}else{
			sed_dp[0]=1;
		}
		for(ll i=1;i<n;++i){
			if(v[i]==1){
				fst_dp[i]=fst_dp[i-1]+1;
				sed_dp[i]=max(0ll,sed_dp[i-1]-1);
			}else{
				fst_dp[i]=max(0ll,fst_dp[i-1]-1);
				sed_dp[i]=sed_dp[i-1]+1;
			}
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			ans=max(ans,max(fst_dp[i],sed_dp[i]));
		}
		cout<<ans;
	}
	return 0;
}

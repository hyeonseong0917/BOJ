#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,m,k;
        cin>>n>>m>>k;
        vector<ll> dp(n+1,20000000000000);
        vector<ll> v(n+1,0);
        for(ll i=1;i<=n;++i){
            cin>>v[i];
        }
        vector<ll> min_dp(n+1,20000000000000), max_dp(n+1,0);
        dp[0]=0;
        for(ll i=1;i<=n;++i){
            max_dp[i]=v[i];
            min_dp[i]=v[i];
            for(ll j=1;i-j>=1 && j<=m;++j){
                max_dp[i-j]=max(v[i-j],max_dp[i-j+1]);
                min_dp[i-j]=min(v[i-j],min_dp[i-j+1]);
            }
            for(ll j=1;i-j>=0 && j<=m;++j){
                    dp[i]=min(dp[i],dp[i-j]+k+j*(max_dp[i-j+1]-min_dp[i-j+1]));
                    // cout<<i<<" "<<j<<" "<<dp[i]<<endl;
            }
        }
        cout<<dp[n];
        // ll ans=20000000000000;
        // for(ll i=0;i<n;++i){
        //     ans=min(ans,dp[i]);
        // }
        // cout<<ans;
        return 0;
	} 
	return 0;
}
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
		// 1349
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		// 0 1 2 3  4
		// 3 4 6 10 24
		// 항상 a가 b로 나누어 떨어져야함
		// n<=5000, v[i]<=10^9
		ll dp[n];
		ll d[n];
		for(ll i=0;i<n;++i){
			dp[i]=n;
			d[i]=n;
		}
		dp[0]=0;
		for(ll i=1;i<n;++i){
			// dp[i]: v[i]를 마지막으로 가질 때
			ll cnt=0;
			dp[i]=i;
			for(ll j=i-1;j>=0;--j){
				if(v[i]%v[j]!=0){
					++cnt;
				}else{
					dp[i]=min(dp[i],dp[j]+i-j-1);
				}
			}
		}
		ll ans=2023101800;
		for(ll i=0;i<n;++i){
			// cout<<i<<" "<<dp[i]<<endl;
			ans=min(ans,dp[i]+n-(i+1));
		}
		cout<<ans;
	}
	return 0;
}
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
		if(n==1){
			cout<<0;
			break;
		}
		sort(v.begin(),v.end());
		ll mod=1000000007;
		// dp[i]: i번째까지 확인했을때 최댓값
		vector<ll> dp(n,0);
		// diff[i]: i번째까지 봤을때 v[j]*pow(2,i-1-j)의 합
		vector<ll> diff(n,0);
		// sum[i]: i번째까지 확인했을때 2의 거듭제곱의 합(1,1+2,1+2+4....)
		vector<ll> sum(n,0);
		ll c=1;
		for(ll i=1;i<n;++i){
			sum[i]=sum[i-1]%mod+c%mod;
			sum[i]%=mod;
			c*=2;
			c%=mod;
		}
		diff[0]=v[0];
		for(ll i=1;i<n;++i){
			diff[i]=diff[i-1]*2;
			diff[i]%=mod;
			diff[i]+=v[i];
			diff[i]%=mod;
		}

		for(ll i=1;i<n;++i){
			dp[i]=dp[i-1]%mod+((sum[i]%mod)*(v[i]%mod))%mod-diff[i-1]%mod;
			if(dp[i]<0){
				dp[i]+=mod;
			}
			dp[i]%=mod;
		}
		cout<<dp[n-1];
	}
	return 0;
}
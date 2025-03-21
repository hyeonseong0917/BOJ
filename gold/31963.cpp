#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> dp(1000000+1,0),L_dp(n,0),R_dp(n,0);
		ll ans=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// L_dp[i]: v[i]이 v[i+1]보다 커지기 위해 곱해야 하는 횟수
		for(ll i=0;i<n-1;++i){
			ll fst_num=v[i];
			ll sed_num=v[i+1];
			ll cnt=0;
			while(fst_num<=sed_num){
				fst_num*=2;
				++cnt;
			}
			L_dp[i]=cnt;
		}
		// R_dp[i]: v[i]가 v[i-1]보다 크거나 같아지기 위해
		for(ll i=n-1;i>=1;--i){
			ll fst_num=v[i];
			ll sed_num=v[i-1];
			ll cnt=0;
			while(fst_num<sed_num){
				fst_num*=2;
				++cnt;
			}
			R_dp[i]=cnt;
		}
		for(ll i=1;i<n;++i){
			if(v[i-1]<v[i]){
				dp[v[i]]=max(dp[v[i]],dp[v[i-1]]-L_dp[i-1]+1);
			}else if(v[i-1]>v[i]){
				dp[v[i]]=max(dp[v[i]],dp[v[i-1]]+R_dp[i]);
			}
			ans+=dp[v[i]];
		}
		cout<<ans;
	}	
	return 0;
}
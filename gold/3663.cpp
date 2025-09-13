#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll t;
		cin>>t;
		while(t--){
			string s;
			cin>>s;
			ll n=s.size();
			if(n==1){
				ll a=s[0]-'A';
				ll b='Z'-s[0];
				++b;
				cout<<min(a,b)<<"\n";
				continue;
			}
			bool flag=0;
			for(ll i=0;i<n;++i){
				if(s[i]!='A'){
					flag=1;
					break;
				}
			}
			if(!flag){
				cout<<0<<"\n";
				continue;
			}
			vector<ll> fst_dp(n,-1), sed_dp(n,-1);
			for(ll i=1;i<n;++i){
				fst_dp[i]=(s[i-1]=='A')?fst_dp[i-1]:i-1;
			}
			for(ll i=n-2;i>=0;--i){
				sed_dp[i]=(s[i+1]=='A')?sed_dp[i+1]:i+1;
			}
			// for(ll i=0;i<n;++i){
			// 	cout<<i<<" "<<fst_dp[i]<<"\n";
			// }
			// for(ll i=0;i<n;++i){
			// 	cout<<i<<" "<<sed_dp[i]<<"\n";
			// }
			ll min_idx=2023101800;
			ll max_idx=-1;
			for(ll i=0;i<n;++i){
				if(s[i]=='A') continue;
				min_idx=min(i,min_idx);
				max_idx=max(i,max_idx);
			}
			ll ans=min(max_idx,n-min_idx);
			for(ll i=n-1;i>=1;--i){
				if(s[i]=='A') continue;
				if(fst_dp[i]==-1) continue;
				ll sum=0;
				sum+=(n-i)*2+fst_dp[i];
				ans=min(sum,ans);
			}
			for(ll i=0;i<n-1;++i){
				if(s[i]=='A') continue;
				if(sed_dp[i]==-1) continue;
				ll sum=0;
				sum+=i*2+(n-1-sed_dp[i]+1);
				ans=min(ans,sum);
			}
			for(ll i=0;i<n;++i){
				ll a=s[i]-'A';
				ll b='Z'-s[i]+1;
				ans+=min(a,b);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
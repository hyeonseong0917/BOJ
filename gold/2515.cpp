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
		ll n,s;
		cin>>n>>s;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end());
		vector<ll> dp(n,0);
		dp[0]=v[0].second;
		for(ll i=1;i<n;++i){
			dp[i]=dp[i-1];
			ll L=0, R=i-1;
			ll max_idx=-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[i].first-v[mid].first>=s){
					max_idx=max(max_idx,mid);
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			ll c=0;
			if(max_idx!=-1){
				c=dp[max_idx];
			}
			dp[i]=max(dp[i],v[i].second+c);
		}
		cout<<dp[n-1];
	}
	return 0;
}
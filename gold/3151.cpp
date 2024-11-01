#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
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
		vector<ll> dp(n,0);
		map<ll,ll> m;
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// dp[n-1]=1;
		// m[v[n-1]]=1;
		for(ll i=n-2;i>=0;--i){
			++m[v[i]];
			// dp[i]=m[v[i]];
		}
		// for(ll i=0;i<n;++i){
		// 	cout<<dp[i]<<" ";
		// }cout<<endl;
		sort(v.begin(),v.end());
		ll ans=0;
		for(ll i=0;i<n;++i){
			for(ll j=i+1;j<n;++j){
				ll cur_num=(v[i]+v[j])*-1;
				// j+1 인덱스 이후 cur_num이 몇 개?
				ll L=j+1, R=n-1;
				ll min_idx=2023101800;
				while(L<=R){
					ll mid=(L+R)/2;
					if(v[mid]>cur_num){
						R=mid-1;
					}else if(v[mid]<cur_num){
						L=mid+1;
					}else{
						min_idx=min(min_idx,mid);
						R=mid-1;
					}
				}
				L=j+1, R=n-1;
				ll max_idx=-2023101800;
				while(L<=R){
					ll mid=(L+R)/2;
					if(v[mid]>cur_num){
						R=mid-1;
					}else if(v[mid]<cur_num){
						L=mid+1;
					}else{
						max_idx=max(max_idx,mid);
						L=mid+1;
					}
				}
				if(max_idx==-2023101800 || min_idx==2023101800) continue;
				ans+=(max_idx-min_idx+1);
				
			}
		}
		cout<<ans;
	}
	return 0;
}
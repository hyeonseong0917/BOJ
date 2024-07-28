#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> r_dp(n,0), l_dp(n,0);
		vector<ll> psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		psum[0]=v[0];
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i];
		}
		ll ans=0;
		
		r_dp[n-2]=psum[n-2]-v[n-2]*2;
		for(ll i=n-2;i>=0;--i){
			r_dp[i]=max(r_dp[i+1],psum[i]-v[i]*2);
		}
		l_dp[1]=psum[1]+v[1];
		for(ll i=2;i<n;++i){
			l_dp[i]=min(l_dp[i-1],psum[i]+v[i]);
		}
		for(ll i=0;i<n;++i){
			// i번째가 꿀통
			ll fst_num=0, sed_num=0, trd_num=0;
			if(i>=2){
				fst_num=max(fst_num,psum[i]-v[0]+psum[i]-l_dp[i-1]);
			}
			if(i>0 && i<n-1){
				sed_num=max(sed_num,psum[n-1]-psum[i]+v[i]-v[n-1]+psum[i]-v[0]);	
			}
			if(i<=n-3){
				trd_num=max(trd_num,psum[n-1]-v[n-1]-psum[i]+v[i]+r_dp[i+1]);
			}
			ans=max(ans,max(fst_num,max(sed_num,trd_num)));
			// if(i==0) cout<<ans<<endl;
		}
		cout<<ans;
	}
	
	return 0;
}
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
		// 1130
		// 정비를 받지 않고 미리 정한 거리를 초과하여 갈 수 없도록
		// 정비하는데 걸리는 시간을 가장 적게 하려고 함
		ll max_dist;
		cin>>max_dist;
		ll n;
		cin>>n;
		vector<ll> v(n+1,0), p(n,0);
		ll sum=0;
		for(ll i=0;i<n+1;++i){
			cin>>v[i]; // max_dist보다 작음
			sum+=v[i];
		}
		for(ll i=0;i<n;++i){
			cin>>p[i];
		}
		if(sum<=max_dist){
			cout<<0<<"\n";
			cout<<0;
			break;
		}
		// 정비하는데 걸리는 시간을 최소로 하면서 목적지에 도착하려고함
		// 0   1  2   3  4  5
		// 100 30 100 40 50 60 거리
		// 5   10 4   11 7 시간

		// n<=100
		vector<ll> dp(n,2222222222);
		dp[0]=p[0];
		for(ll i=1;i<n;++i){
			ll cur_dist=0;
			for(ll j=i;j>=0;--j){
				cur_dist+=v[j];
				if(cur_dist>max_dist){
					break;
				}
				if(j==0){
					dp[i]=min(dp[i],p[i]);
				}else{
					dp[i]=min(dp[i],p[i]+dp[j-1]);
				}
			}
			// cout<<i<<" "<<dp[i]<<endl;
		}
		ll cur_dist=0;
		ll ans=2222222222;
		for(ll i=n-1;i>=0;--i){
			cur_dist+=v[i+1];
			if(cur_dist>max_dist){
				break;
			}
			ans=min(ans,dp[i]);
		}
		cout<<ans<<"\n";
		vector<ll> c;
		for(ll j=n-1;j>=0;--j){
			if(dp[j]==ans){
				c.push_back(j+1);
				ans-=p[j];
			}
		}
		ll cs=c.size();
		cout<<cs<<"\n";
		sort(c.begin(),c.end());
		for(ll i=0;i<cs;++i){
			cout<<c[i]<<" ";
		}
	}
	return 0;
}
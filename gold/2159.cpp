#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

ll dy[5]={-1,0,1,0,0};
ll dx[5]={0,1,0,-1,0};
bool isRange(ll y, ll x){
	return (y>=1 && x>=1 && y<=100000 && x<=100000);
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		ll x,y;
		cin>>y>>x;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.pb({a,b});
		}
		// y번째 좌표에 배달을 완료하기 위한 최솟값?
		// dp[{y,x}]=min(dp[v[i-1]의상하좌우]+저 위치에서 거리)
		// dp[y]=min(dp[y-1])
		map<pair<ll,ll>,ll> dp;
		dp[{v[0].first,v[0].second}]=abs(v[0].first-y)+abs(v[0].second-x);
		ll u=dp[{v[0].first,v[0].second}];
		for(ll i=0;i<4;++i){
			ll ny=v[0].first+dy[i];
			ll nx=v[0].second+dx[i];
			if(!isRange(ny,nx)) continue;
			// cout<<ny<<" "<<nx<<endl;
			dp[{ny,nx}]=abs(ny-y)+abs(nx-x);
			u=min(u,dp[{ny,nx}]);
		}
		if(n==1){
			cout<<u;
			break;
		}
		ll ans=1000000000000000+1;
		for(ll i=1;i<n;++i){
			ll cy=v[i].first;
			ll cx=v[i].second;
			for(ll j=0;j<5;++j){
				ll ccy=cy+dy[j];
				ll ccx=cx+dx[j];
				if(!isRange(ccy,ccx)) continue;
				ll c=1000000000000000+1;
				for(ll k=0;k<5;++k){
					ll ny=v[i-1].first+dy[k];
					ll nx=v[i-1].second+dx[k];
					if(!isRange(ny,nx)) continue;
					c=min(c,dp[{ny,nx}]+abs(ny-ccy)+abs(nx-ccx));
				}
				if(i==n-1){
					ans=min(ans,c);
				}
				dp[{ccy,ccx}]=c;	
			}
		}
		// cout<<dp[{7,2}]<<endl;
		cout<<ans;
	}
	return 0;
}
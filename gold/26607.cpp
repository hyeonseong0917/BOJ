#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define ll long long


bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.first>b.first;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,k,x;
		cin>>n>>k>>x;
		vector<pair<ll,ll>> v;
		vector<ll> psum(n,0);
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
			if(i==0){
				psum[0]=v[0].first;
			}else{
				psum[i]=psum[i-1]+v[i].first;
			}
		}
		ll dp[2][k+1][psum[n-1]+1];
		
		for(ll i=0;i<2;++i){
			for(ll j=0;j<=k;++j){
				for(ll p=0;p<=psum[n-1];++p){
					dp[i][j][p]=0;
					// cout<<i<<" "<<j<<" "<<p<<" "<<dp[i][j][p]<<endl;
				}
			}
		}
		dp[0][1][v[0].first]=1;
		for(ll i=1;i<n;++i){
			// dp[i%2][j][k]
			for(ll j=0;j<=k;++j){
				for(ll p=0;p<=psum[i];++p){
					dp[i%2][1][v[i].first]=1;
					if(p>=v[i].first && j){
						dp[i%2][j][p]|=dp[(i+1)%2][j-1][p-v[i].first];
					}
					dp[i%2][j][p]|=dp[(i+1)%2][j][p];
					// cout<<"i: "<<i<<" j: "<<j<<" p: "<<p<<" dp: "<<dp[i%2][j][p]<<endl;
				}
			}
			// if(i==2){
			// 	cout<<dp[0][2][4]<<endl;
			// }
		}
		ll ans=0;
		for(ll i=0;i<=psum[n-1];++i){
			if(dp[0][k][i] || dp[1][k][i]){
				ll a=i;
				ll b=k*x-a;
				ans=max(ans,a*b);
			}
			
		}
		cout<<ans;
		
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

#define ll long long

ll dp[100+1][100000+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			for(ll j=0;j<=100000;++j){
				dp[i][j]=2023101800;
			}
		}
		if(k==0){
			cout<<0;
			break;
		}
		sort(v.begin(),v.end());
		dp[0][v[0]]=1;
		for(ll i=1;i<n;++i){
			dp[i][v[i]]=1;
			for(ll j=1;j<=100000;++j){
				dp[i][j]=min(dp[i][j],dp[i-1][j]);
				if(j>=v[i]){
					dp[i][j]=min(dp[i][j],dp[i-1][j-v[i]]+1);
				}
			}
		}
		ll ans=2023101800;
		for(ll i=0;i<n;++i){
			ans=min(ans,dp[i][k]);
		}
		if(ans==2023101800){
			ans=-1;
		}
		cout<<ans;
	}
	return 0;
}
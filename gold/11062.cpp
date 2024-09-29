#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

ll dp[1000+1][1000+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll t;
		cin>>t;
		while(t--){
			for(ll i=0;i<=1000;++i){
				for(ll j=0;j<=1000;++j){
					dp[i][j]=0;
				}
			}
			ll n;
			cin>>n;
			vector<ll> v(n,0);
			for(ll i=0;i<n;++i){
				cin>>v[i];
			}
			if(n==1){
				cout<<v[0]<<"\n";
				continue;
			}
			bool is_odd=0;
			if(n%2==1){
				is_odd=1;
				for(ll i=0;i<n;++i){
					dp[i][i]=v[i];
				}
			}
			for(ll i=1;i<=n-1;++i){
				for(ll j=0;j+i<=n-1;++j){
					if(!is_odd){
						if(i%2==1){
							dp[j][j+i]=max(v[j]+dp[j+1][j+i],v[j+i]+dp[j][j+i-1]);
						}else{
							dp[j][j+i]=min(dp[j+1][j+i],dp[j][j+i-1]);
						}
					}else{
						if(i%2==0){
							dp[j][j+i]=max(v[j]+dp[j+1][j+i],v[j+i]+dp[j][j+i-1]);
						}else{
							dp[j][j+i]=min(dp[j+1][j+i],dp[j][j+i-1]);
						}
					}
					
				}
				
			}
			cout<<dp[0][n-1]<<"\n";
			
			
		}
	}
	return 0;
}
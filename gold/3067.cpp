#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

ll dp[10000+1][20+1]={0,};

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	cin>>o;
	while(o--){
		for(ll i=0;i<10000+1;++i){
			for(ll j=0;j<20+1;++j){
				dp[i][j]=0;
			}
		}
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll m;
		cin>>m;
		for(ll i=0;i<n;++i){
			dp[0][i]=1;
		}
		ll a=0;
		while(1){
			a+=v[0];
			if(a>m){
				break;
			}
			dp[a][0]=1;
		}
		for(ll i=1;i<n;++i){
			for(ll j=1;j<=m;++j){
				// dp[j][i]+=dp[j][i-1];
				for(ll k=0;k<=m;++k){
					if(j-v[i]*k<0){
						break;
					}
					dp[j][i]+=dp[j-v[i]*k][i-1];
				}
			}
		}
		cout<<dp[m][n-1]<<"\n";
	}
	return 0;
}
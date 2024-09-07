#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	while(t--){
		ll n;
		cin>>n;
		string s[n+1];
		for(ll i=0;i<n;++i){
			cin>>s[i];
		}
		vector<ll> f[n+1];
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				if(s[i][j]=='N') continue;
				f[i].push_back(j);
			}
		}
		vector<ll> dp(n+1,0);
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				if(i==j) continue;
				if(s[i][j]=='Y'){
					++dp[i];
					continue;
				}
				bool is_same=0;
				for(ll k=0;k<f[i].size();++k){
					for(ll p=0;p<f[j].size();++p){
						if(f[i][k]==f[j][p]){
							is_same=1;
							break;
						}
					}
				}
				if(is_same) ++dp[i];
			}
		}
		
		ll ans=0;
		for(ll i=0;i<n;++i){
			ans=max(ans,dp[i]);
		}
		cout<<ans;
	}
	return 0;
}
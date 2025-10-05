#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		vector<vector<ll>> dp;
		for(ll i=0;i<n;++i){
			vector<ll> tmp;
			for(ll j=0;j<2;++j){
				tmp.push_back(0);
			}
			dp.push_back(tmp);
		}
		dp[1][0]=v[1]-v[0];
		dp[2][1]=v[2]-v[0];
		for(ll i=3;i<n;++i){
			if(i%2==1){
				dp[i][0]=dp[i-2][0]+v[i]-v[i-1];
			}else{
				dp[i][1]=min(dp[i-2][1]+v[i]-v[i-1],dp[i-3][0]+v[i]-v[i-2]);
			}
		}
		cout<<dp[n-1][1];
	}
	return 0;
}
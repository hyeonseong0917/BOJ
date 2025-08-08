#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>t;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<ll> dp(n,0);
		for(ll i=1;i<n;++i){
			dp[i]=2023101800;
			for(ll j=0;j<i;++j){
				if(j+v[j]<i) continue;
				dp[i]=min(dp[i],dp[j]+1);
			}
		}
		if(dp[n-1]==2023101800){
			cout<<-1;
		}else{
			cout<<dp[n-1];
		}
	} 
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		ll n;
		cin>>n;
		if(n==0){
			cout<<"NO";
			break;
		}
		vector<ll> dp(20+1);
		dp[0]=1;
		for(ll i=1;i<=19;++i){
			dp[i]=dp[i-1]*i;
		}
		for(ll i=19;i>=0;--i){
			if(n>=dp[i]){
				n-=dp[i];
			}
		}
		if(!n){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
	} 
	return 0;
}
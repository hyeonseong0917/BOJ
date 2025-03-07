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
		// bca
		// b c a bb bc ba cb cc ca
		string s,t;
		cin>>s;
		cin>>t;
		// t를 몇 번의 시도로 만들 수 있는지??
		ll mod=900528;
		ll n=s.size();
		ll m=t.size();
		map<char,ll> check;
		for(ll i=0;i<n;++i){
			check[s[i]]=i;
		}
		// 길이가 m보다 작은거 배제하기
		ll ans=0;
		vector<ll> dp(max(n,m)+1,1);
		for(ll i=1;i<=max(n,m);++i){
			dp[i]=(dp[i-1]*n)%mod;
			dp[i]%=mod;
		}
		for(ll i=1;i<m;++i){
			ans+=dp[i];
			ans%=mod;
		}
		for(ll i=0;i<m;++i){
			ll c=1;
			c*=dp[m-1-i];
			c%=mod;
			c*=check[t[i]];
			c%=mod;
			ans+=c;
			ans%=mod;
		}
		++ans;
		ans%=mod;
		cout<<ans;
		// 
	}
	return 0;
}
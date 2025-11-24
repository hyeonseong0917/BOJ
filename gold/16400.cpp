#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// N은 4만이하
		ll n;
		cin>>n;
		// n원을 만들 수 있는 가짓수?
		ll mod=123456789;
		vector<ll> dp(40000+1,0);
		vector<ll> check(40000+1,0);
		check[1]=1;
		for(ll i=2;i<=n;++i){
			if(check[i]) continue;
			for(ll j=i*i;j<=n;j+=i){
				++check[j];
			}
		}
		// dp[n]: n원을 만들 수 있는 가짓수?
		// dp[x]=dp[x-i]+1
		vector<ll> tmp;
		for(ll i=2;i<=n;++i){
			if(!check[i]){
				tmp.push_back(i);
			}
		}
		dp[0]=1;
		for(ll i=0;i<tmp.size();++i){
			for(ll j=tmp[i];j<=n;++j){
				dp[j]+=dp[j-tmp[i]]%mod;
				dp[j]%=mod;
			}
		}
		cout<<dp[n];

	}
	return 0;
}
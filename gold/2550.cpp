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
	while(o--){
		ll n;
		cin>>n;
		vector<ll> a(n,0) ,b(n,0);
		vector<ll> check(n+1,0);
		vector<ll> dp(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
			check[b[i]]=i;
		}
		dp[0]=1;
		ll x=1;
		for(ll i=1;i<n;++i){
			dp[i]=1;
			for(ll j=0;j<i;++j){
				if(check[a[j]]<check[a[i]]){
					dp[i]=max(dp[i],1+dp[j]);
				}
			}
			x=max(x,dp[i]);
		}
		cout<<x<<"\n";
		vector<ll> tmp;
		for(ll i=n-1;i>=0;--i){
			if(dp[i]==x){
				tmp.push_back(a[i]);
				--x;
			}
		}
		sort(tmp.begin(),tmp.end());
		for(ll i=0;i<tmp.size();++i){
			cout<<tmp[i]<<" ";
		}
	}
	return 0;
}
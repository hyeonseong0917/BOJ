#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
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
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll a,b,c;
		c=v[n-1];
		ll ans=-2023101800;
		for(ll i=0;i<n-1;++i){
			ll a=v[i];
			ll b=v[i+1];
			ans=max(ans,a-2*b+c);
		}
		a=v[0];
		for(ll i=1;i<n-1;++i){
			ll b=v[i];
			ll c=v[i+1];
			ans=max(ans,abs(-a-c+2*b));
		}
		cout<<ans;
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	// cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		vector<ll> psum(n,0);
		vector<ll> lpsum(n,0);
		lpsum[0]=v[0];
		psum[n-1]=v[n-1];
		for(ll i=n-2;i>=0;--i){
			psum[i]=psum[i+1]+v[i];
		}
		for(ll i=1;i<n;++i){
			lpsum[i]=lpsum[i-1]+v[i];
		}
		ll ans=psum[0];
		for(ll i=n-1;i>=0;--i){
			ll R=(ll)psum[i]*(n-i);
			ll c=0;
			if(i){
				c=lpsum[i-1];
			}
			ans=max(ans,R+c);
		}
		cout<<ans;
	}
	return 0;
}
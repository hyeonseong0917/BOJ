#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
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
		ll ans=0;
		for(ll i=0;i<n-1;++i){
			ll w=v[i+1]+v[i];
			ll h=abs(v[i+1]-v[i]);
			ans+=(w*w)+(h*h);
		}
		cout<<ans;
	}
	return 0;
}
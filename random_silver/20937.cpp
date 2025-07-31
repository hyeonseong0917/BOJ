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
		vector<ll> v(n,0);
		vector<ll> c(50000+1,0);
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			++c[a];
		}
		ll ans=0;
		for(ll i=1;i<=50000;++i){
			ans=max(ans,c[i]);
		}
		cout<<ans;

	} 
	return 0;
}
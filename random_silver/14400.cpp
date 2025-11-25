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
		vector<ll> x,y;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			x.push_back(a);
			y.push_back(b);
		}
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		// 1 2 3 4 5 6
		ll mid_x=x[n/2];
		ll mid_y=y[n/2];
		ll ans=0;
		for(ll i=0;i<n;++i){
			ans+=abs(mid_x-x[i])+abs(mid_y-y[i]);
		}
		cout<<ans;
	} 
	return 0;
}
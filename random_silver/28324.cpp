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
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll ans=0;
		// 2 3 1
		// 2 2 1

		// 1 2 3
		//     3

		// 1 4 3
		// 1 4 3


		// 23 7 1 5
		//  3 2 1 1
		ll last_val=1;
		ans+=1;
		for(ll i=n-2;i>=0;--i){
			ans+=min(last_val+1,v[i]);
			last_val=min(last_val+1,v[i]);
		}
		cout<<ans;
	} 
	return 0;
}
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
		ll pre=-1;
		for(ll i=0;i<n;++i){
			if(pre<=v[i]){
				++ans;
				
			}
			pre=v[i];
		}
		cout<<ans;
		return 0;
	} 
	return 0;
}
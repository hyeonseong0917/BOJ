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
		vector<ll> v[n+1];
		ll ans=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<7;++j){
				ll a;
				cin>>a;
				v[i].push_back(a);
			}
			ll sum=0;
			ll c=max(v[i][0],v[i][1]);
			sum+=c;
			vector<ll> tmp;
			for(ll j=2;j<7;++j){
				tmp.push_back(v[i][j]);
			}
			sort(tmp.rbegin(),tmp.rend());
			sum+=tmp[0];
			sum+=tmp[1];
			ans=max(ans,sum);
		}
		cout<<ans;

	} 
	return 0;
}
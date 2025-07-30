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
	// cin>>o;
	while(o--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		priority_queue<ll> a,b;
		for(ll i=0;i<n-1;++i){
			a.push(v[i]);
		}
		b.push(v[n-1]);
		ll ans=v[n-1]+v[0]*(n-1);
		while(a.size()>1){
			ll a_top=a.top();
			// cout<<a_top<<endl;
			a.pop();
			b.push(a_top);

			ll as=a.size();
			ll bs=b.size();
			// cout<<as*v[0]+bs*a_top<<endl;
			ans=max(ans,as*v[0]+bs*a_top);
			// cout<<ans<<endl;
		}
		// cout<<ans;
		cout<<(k+ans-1)/ans;
	}	
	return 0;
}
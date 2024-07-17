#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		if(n%2==1){
			ll ans=v[n-1];
			ll L=0;
			ll R=n-2;
			while(L<R){
				ans=max(ans,v[L]+v[R]);
				++L;
				--R;
			}
			cout<<ans;
		}else{
			ll ans=0;
			ll L=0;
			ll R=n-1;
			while(L<R){
				ans=max(ans,v[L]+v[R]);
				++L;
				--R;
			}
			cout<<ans;
		}
	}
	return 0;
}
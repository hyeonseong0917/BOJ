#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
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
		map<ll,ll> m;
		vector<ll> v;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		ll ans=2023101800;
		for(ll i=0;i<n;++i){
			for(ll j=i+3;j<n;++j){
				ll L=i+1;
				ll R=j-1;
				ll big_sum=v[i]+v[j];
				while(L<R){
					if(big_sum>v[L]+v[R]){
						ans=min(ans,abs(v[L]+v[R]-big_sum));
						++L;
					}else{
						ans=min(ans,abs(v[L]+v[R]-big_sum));
						--R;
					}
				}
				// cout<<i<<" "<<j<<" "<<ans<<endl;
			}
		}
		cout<<ans;
	}
	return 0;
}
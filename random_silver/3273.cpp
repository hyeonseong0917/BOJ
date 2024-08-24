#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
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
		ll x;
		cin>>x;
		sort(v.begin(),v.end());
		ll L=0, R=n-1;
		ll ans=0;
		while(L<R){
			if(v[L]+v[R]>x){
				--R;
			}else{
				if(v[L]+v[R]==x){
					++ans;
				}
				++L;
			}
		}
		cout<<ans;

	}
	return 0;
}
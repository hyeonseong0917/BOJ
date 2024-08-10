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
	ll o=1;
	while(o--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll L=0, R=n-1;
		ll ans=0;
		while(L<R){
			if(v[L]+v[R]<=k){
				++ans;
				++L;
				--R;
			}else{
				--R;
			}
		}
		cout<<ans;
	}
	
	return 0;
}
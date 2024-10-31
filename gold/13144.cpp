#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll L=0, R=0;
		ll ans=n;
		map<ll,ll> m;
		++m[v[0]];
		while(L<=R && L<n){
			// cout<<L<<" "<<R<<" "<<ans<<endl;
			if(R==n-1 || m[v[R+1]]){
				// 전진할 수 없음
				if(L==R){
					--m[v[L]];
					++L;
					++R;
					++m[v[L]];
				}else{
					--m[v[L]];
					++L;
					// ++m[v[L]];
					ans+=R-L;
				}
				
			}else{
				// 전진 가능
				++R;
				++m[v[R]];
				++ans;
			}
		}
		cout<<ans;
	}
	return 0;
}
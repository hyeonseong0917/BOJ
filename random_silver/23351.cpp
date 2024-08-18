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
		ll n,k,a,b;
		cin>>n>>k>>a>>b;
		vector<ll> v(n,k);
		ll cnt=0;
		ll idx=0;
		while(1){
			bool flag=0;
			for(ll i=0;i<n;++i){
				if(v[i]<=0){
					flag=1;
					break;
				}
			}
			if(flag) break;
			for(ll i=idx;i<idx+a;++i){
				v[i]+=b;
			}
			for(ll i=0;i<n;++i){
				--v[i];
			}
			idx+=a;
			idx%=n;
			++cnt;
		}
		cout<<cnt;
	}
	return 0;
}
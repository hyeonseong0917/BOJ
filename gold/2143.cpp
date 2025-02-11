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
	ll o=1;
	while(o--){
		ll T;
		cin>>T;
		ll n;
		cin>>n;
		vector<ll> a(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		ll m;
		cin>>m;
		vector<ll> b(m,0);
		for(ll j=0;j<m;++j){
			cin>>b[j];
		}
		map<ll,ll> check;
		vector<ll> a_psum(n,0), b_psum(m,0);
		a_psum[0]=a[0];
		b_psum[0]=b[0];
		for(ll i=1;i<n;++i){
			a_psum[i]=a_psum[i-1]+a[i];
		}
		for(ll i=1;i<m;++i){
			b_psum[i]=b_psum[i-1]+b[i];
		}
		for(ll i=0;i<n;++i){
			for(ll j=i;j<n;++j){
				++check[a_psum[j]-a_psum[i]+a[i]];
			}
		}
		ll ans=0;
		for(ll i=0;i<m;++i){
			for(ll j=i;j<m;++j){
				ans+=check[T-(b_psum[j]-b_psum[i]+b[i])];
			}
		}
		cout<<ans;
	} 
	return 0;
}
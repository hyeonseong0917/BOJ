#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long
int main() {
	
	// your code goes here
	// 1 9 
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n,q;
		cin>>n>>q;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		vector<ll> psum(n,0);
		psum[0]=v[0];
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i];
		}
		for(ll i=0;i<q;++i){
			ll a,b;
			cin>>a>>b;
			--a;
			--b;
			cout<<psum[b]-psum[a]+v[a]<<"\n";
		}
	}
	

	

	return 0;
}
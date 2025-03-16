#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back



int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;	
	while(t--){	
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			psum[i]=(i==0)?v[i]:psum[i-1]+v[i];
		}
		if(n==1){
			cout<<v[0];
			continue;
		}
		ll ans=2023101800;
		ans=min(psum[n-1]-psum[0],psum[n-2]);
		for(ll i=0;i+2<n;++i){
			// n-1
			// i+1
			// n-i-2
			ans=min(ans,psum[i]+psum[n-1]-psum[i+2]+v[i+2]);
		}
		cout<<ans;

	}
	return 0;
}
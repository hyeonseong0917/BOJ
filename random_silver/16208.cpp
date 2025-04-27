#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll cur_len=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			cur_len+=v[i];
		}
		sort(v.begin(),v.end());
		ll ans=0;
		
		for(ll i=0;i<n;++i){
			ans+=(v[i]*(cur_len-v[i]));
			cur_len-=v[i];
		}
		cout<<ans;
	}
} 
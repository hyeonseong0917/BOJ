#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		deque<ll> dq[n+1];
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			dq[i].push_back(a);
		}
		
		ll m;
		cin>>m;
		vector<ll> ans;
		for(ll i=0;i<m;++i){
			ll a;
			cin>>a;
			
		}

	}
	return 0;
}
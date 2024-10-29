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
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<ll> diff;
		for(ll i=0;i<n-1;++i){
			diff.push_back(v[i+1]-v[i]);
		}
		sort(diff.begin(),diff.end());
		reverse(diff.begin(),diff.end());
		map<ll,ll> m;
		for(ll i=0;i<k-1;++i){
			++m[diff[i]];
		}
		ll ans=1;
		for(ll i=0;i<n-1;++i){
			if(m[v[i+1]-v[i]]){
				--m[v[i+1]-v[i]];
				++ans;
			}else{
				ans+=v[i+1]-v[i];
			}
		}
		cout<<ans;
	}

	return 0;
}
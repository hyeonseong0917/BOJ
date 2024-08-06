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
		sort(v.begin(),v.end());
		ll ans=-1;
		for(ll i=n-1;i>=2;--i){
			if(v[i]<v[i-1]+v[i-2]){
				ans=v[i]+v[i-1]+v[i-2];
				break;
			}
		}
		cout<<ans;

	}
	return 0;
}
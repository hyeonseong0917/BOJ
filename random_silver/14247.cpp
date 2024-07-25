#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long


bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.second<b.second;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> h(n,0), a(n,0);
		for(ll i=0;i<n;++i){
			cin>>h[i];
		}
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			v.push_back({h[i],a[i]});
		}
		sort(v.begin(),v.end(),comp);
		ll sum=0;
		for(ll i=0;i<n;++i){
			sum+=v[i].first+v[i].second*i;
			// cout<<sum<<endl;
		}
		cout<<sum;
	}
	
	return 0;
}
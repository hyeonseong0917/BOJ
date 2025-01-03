#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back

bool fst_comp(pair<pair<ll,ll>,ll> a, pair<pair<ll,ll>,ll> b){
	return a.first.first>b.first.first;
}

bool sed_comp(pair<pair<ll,ll>,ll> a, pair<pair<ll,ll>,ll> b){
	return a.first.second>b.first.second;
}

bool trd_comp(pair<pair<ll,ll>,ll> a, pair<pair<ll,ll>,ll> b){
	return a.second>b.second;
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,k;
		cin>>n>>k;
		vector<pair<pair<ll,ll>,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v.push_back({{a+b,a+c},b+c});
		}
		sort(v.begin(),v.end(),fst_comp);
		ll ans=0;
		ll fst_sum=0;
		ll sed_sum=0;
		ll trd_sum=0;
		for(ll i=0;i<k;++i){
			fst_sum+=v[i].first.first;
		}
		sort(v.begin(),v.end(),sed_comp);
		for(ll i=0;i<k;++i){
			sed_sum+=v[i].first.second;
		}
		sort(v.begin(),v.end(),trd_comp);
		for(ll i=0;i<k;++i){
			trd_sum+=v[i].second;
		}
		ans=max(trd_sum,max(fst_sum,sed_sum));
		cout<<ans;

	}
	return 0;
}
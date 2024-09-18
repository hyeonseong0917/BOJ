#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

bool comp(pair<pair<string,ll>,pair<ll,ll>> a, pair<pair<string,ll>,pair<ll,ll>> b){
	if(a.first.second==b.first.second){
		if(a.second.first==b.second.first){
			if(a.second.second==b.second.second){
				return a.first.first<b.first.first;
			}
			return a.second.second>b.second.second;
		}
		return a.second.first<b.second.first;
	}
	return a.first.second>b.first.second;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		vector<pair<pair<string,ll>,pair<ll,ll>>> v;
		ll n=0;
		cin>>n;
		for(ll i=0;i<n;++i){
			string s;
			ll a,b,c;
			cin>>s;
			cin>>a;
			cin>>b;
			cin>>c;
			v.push_back({{s,a},{b,c}});
		}
		sort(v.begin(),v.end(),comp);
		for(ll i=0;i<n;++i){
			cout<<v[i].first.first<<"\n";
		}
	}
	return 0;
}
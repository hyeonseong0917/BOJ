#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<pair<ll,pair<ll,ll>>> v;
		for(ll i=0;i<n;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v.push_back({a,{b,c}});
		}
		sort(v.begin(),v.end());
		ll start=v[0].first;
		ll fin=v[0].second.first;
		ll cost=v[0].second.second;
		vector<pair<ll,pair<ll,ll>>> ans;
		for(ll i=1;i<n;++i){
			if(fin<v[i].first){
				ans.push_back({start,{fin,cost}});
				start=v[i].first;
				fin=v[i].second.first;
				cost=v[i].second.second;
			}else{
				fin=max(fin,v[i].second.first);
				cost=min(cost,v[i].second.second);
			}
		}
		ans.push_back({start,{fin,cost}});
		ll as=ans.size();
		cout<<as<<"\n";
		for(ll i=0;i<as;++i){
			cout<<ans[i].first<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<"\n";
		}
	}
	return 0;
}
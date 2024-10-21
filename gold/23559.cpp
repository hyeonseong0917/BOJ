#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long
bool comp(pair<ll,pair<ll,ll>> a, pair<ll,pair<ll,ll>> b){
	if(a.first==b.first){
		return a.second.first>b.second.first;
	}
	return a.first>b.first;
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,x;
		cin>>n>>x;
		vector<pair<ll,pair<ll,ll>>> v;
		ll ans=0;
		// 5000의 개수를 구해보자
		ll max_cnt=(x/1000-n)/4;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			if(a<=b){
				ans+=b;
				x-=1000;
				continue;
			}
			v.push_back({a-b,{a,b}});
		}
		sort(v.begin(),v.end(),comp);
		for(ll i=0;i<v.size();++i){
			if(x>=5000 && max_cnt){
				x-=5000;
				ans+=v[i].second.first;
				--max_cnt;
			}else{
				ans+=v[i].second.second;
			}
		}
		cout<<ans;

	}
	return 0;
}
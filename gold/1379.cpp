#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

bool comp(pair<ll,pair<ll,ll>> a, pair<ll,pair<ll,ll>> b){
	return a.second.first<b.second.first;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<pair<ll,pair<ll,ll>>> v;
		for(ll i=0;i<n;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v.push_back({a,{b,c}});
		}
		sort(v.begin(),v.end(),comp);
		priority_queue<pair<ll,ll>> pq;
		ll cnt=1;
		map<ll,ll> ans;
		for(ll i=0;i<n;++i){
			ll a=v[i].first;
			ll s=v[i].second.first;
			ll f=v[i].second.second;
			if(pq.empty()){
				pq.push({-1*f,cnt});
				ans[a]=cnt;
			}else{
				ll cur_finish=pq.top().first*-1;
				if(cur_finish<=s){
					ll cur_room_num=pq.top().second;
					pq.pop();
					pq.push({f*-1, cur_room_num});
					ans[a]=cur_room_num;
				}else{
					++cnt;
					pq.push({f*-1, cnt});
					ans[a]=cnt;
				}
			}
		}
		cout<<cnt<<"\n";
		for(ll i=1;i<=n;++i){
			cout<<ans[i]<<"\n";
		}
	}
	return 0;
}
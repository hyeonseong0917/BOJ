#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll get_mil_time(string a){
	ll hour_time=stoll(a.substr(0,2));
	ll minute_time=stoll(a.substr(3,2));
	ll second_time=stoll(a.substr(6,2));
	ll mil_time=stoll(a.substr(9,3));
	second_time=second_time*1000;
	minute_time=minute_time*60*1000;
	hour_time=hour_time*60*60*1000;
	return mil_time+second_time+minute_time+hour_time;
}
bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second<b.second;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			string a,b;
			cin>>a;
			cin>>b;
			// a는 몇 밀리초인지?
			ll at=get_mil_time(a);
			ll bt=get_mil_time(b);
			v.push_back({at,bt});
		}
		// 시작점과 끝점이 있을때
		// 어떻게 해야 공간을 최소로 쓸까??
		// 시작점 기준으로 sort?
		sort(v.begin(),v.end());
		priority_queue<ll> pq;
		ll ans=1;
		pq.push(v[0].second*-1);
		for(ll i=1;i<n;++i){
			while(!pq.empty()){
				ll cur_num=pq.top()*-1;
				if(cur_num<=v[i].first){
					pq.pop();
				}else{
					break;
				}
			}
			pq.push(v[i].second*-1);
			ll ps=pq.size();
			ans=max(ans,ps);
		}
		cout<<ans;
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// 
	while(t--){
		// 1127
		// 1번부터 N번째 집까지 존재
		// 각 집의 위치
		// 내놓는 시간
		ll n;
		cin>>n;
		vector<ll> x(n,0),y(n,0);
		for(ll i=0;i<n;++i){
			cin>>x[i];
		}
		for(ll i=0;i<n;++i){
			cin>>y[i];
		}
		vector<pair<ll,ll>> v;
		v.push_back({0,0});
		for(ll i=0;i<n;++i){
			v.push_back({x[i],y[i]});
		}
		// 모든 물건을 다 회수해서 0까지 돌아오는데 걸리는 시간
		// 0 2  5 7 10
		// 0 20 4 16 11
		// 1. x[i]<y[i]이면 기다리기? 아니면 돌아올 때 기다리기?
		ll cur_time=0;
		vector<ll> check(n+1,0);
		cur_time=max(v[n].first,v[n].second);
		for(ll i=n-1;i>=0;--i){
			cur_time+=v[i+1].first-v[i].first;
			cur_time=max(cur_time,v[i].second);
		}
		cout<<cur_time;
	} 
	return 0;
}
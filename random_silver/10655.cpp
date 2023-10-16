#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int N;
vector<pair<ll,ll>> v;
ll taxi(pair<ll,ll> a, pair<ll,ll> b){
	return (abs(a.first-b.first)+abs(a.second-b.second));
}
ll dist=0;
void Input(){
	cin>>N;
	
	for(int i=0;i<N;++i){
		ll x,y;
		cin>>x>>y;
		v.push_back({x,y});

	}
	for(int i=1;i<N;++i){
		ll cur_dist=dist;
		dist+=taxi(v[i],v[i-1]);
	}

}
void solve(){
	ll ans=dist;
	for(int i=1;i<N-1;++i){
		//i번째 지점을 제외
		ll cur_dist=dist;
		cur_dist-=taxi(v[i],v[i-1]);
		cur_dist-=taxi(v[i],v[i+1]);
		cur_dist+=taxi(v[i-1],v[i+1]);

		ans=min(ans,cur_dist);
	}
	cout<<ans;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	return 0;
}
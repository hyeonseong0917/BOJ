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
	ll o=1;
	while(o--){
		// 집은 0번부터 M번까지
		// 집 사이 거리 1키로
		// 상근이는 0번집에 사는중, M번 집으로 가야함
		// N명이 타려고 함
		// A: 2->8, B: 6->4
		// 모두 데려다주고, M번 집으로 가기 위해 이동하는 거리 최솟값

		ll n,m;
		cin>>n>>m;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			if(a>b){
				v.push_back({b,a});
			}
		}
		ll ans=m;
		if(v.empty()){
			cout<<ans;
			break;
		}
		sort(v.begin(),v.end());
		ll L=0, R=0;
		for(ll i=0;i<v.size();++i){
			if(v[i].first>R){
				ans+=(R-L)*2;
				L=v[i].first;
				R=v[i].second;
			}else{
				// v[i].first<R
				R=max(R,v[i].second);
			}
		}
		ans+=(R-L)*2;
		cout<<ans;
		// n=2, m=10
		// 2 8
		// 6 4
	}
	return 0;
}
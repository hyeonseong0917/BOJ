#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if(a.first+a.second==b.first+b.second){
		return a.second>b.second;
	}
	return a.second+a.first>b.second+b.first;
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
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		// a+b순으로 내림차순 정렬 -> 스타팅포인트 기준 왼쪽만 확인하면 됨.
		// 왜냐하면 오른쪽은 어차피 i번째가 i+1번째보다 무조건 크기때문에 비교할 필요 없음
		// 왼쪽 비교를 수행했을때 더 작은지만 확인하면됨. 왼쪽 비교로 ok면 오른쪽 비교도 무조건 ok임

		sort(v.begin(),v.end(),comp);
		// L 제일 왼쪽으로 뻗은 좌표
		ll L=v[0].first-v[0].second;
		ll ans=1;
		for(ll i=1;i<n;++i){
			ll l=v[i].first-v[i].second;
			ll r=v[i].first+v[i].second;
			if(v[i].first<L){
				// i번째 스타팅포인트가 L(현재까지 제일 왼쪽으로 뻗은 좌표)보다 작다면 무조건 가능
				++ans;
			}else{
				// i번째 스타팅포인트가 L보다는 크거나 같음(범위 안에 있음)
				if(l<L){
					// i번째 스타팅포인트에서 왼쪽으로 뻗었을때 L보다 작으면 가능함
					++ans;
				}
			}
			// L은 가능했던 가능하지 않았던 갱신해야함
			L=min(l,L);
		}
		cout<<ans;

	}
	return 0;
}
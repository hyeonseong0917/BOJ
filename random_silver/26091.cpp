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
	// cin>>t;
	while(t--){
		// 팀원 2명
		// 팀의 능력치 m이상
		// n명이 견학중, n명으로 최대한 많은 팀을 만들고 싶으
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll L=0, R=n-1;
		ll ans=0;
		while(L<R){
			if(v[L]+v[R]>=m){
				++ans;
				++L;
				--R;
			}else{
				++L;
			}
		}
		cout<<ans;
	} 
	return 0;
}
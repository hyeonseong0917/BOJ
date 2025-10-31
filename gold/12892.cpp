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
		ll n,d;
		cin>>n>>d;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end());
		vector<ll> psum(n,0);
		psum[0]=v[0].second;
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i].second;
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			// i번째 가져갈 때
			ll L=i+1, R=n-1;
			// i번째가 가장 작은 선물이라고 가정한다면
			// 최대의 인덱스를 구한다
			ll max_idx=i;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid].first<v[i].first+d){
					max_idx=max(max_idx,mid);
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			if(max_idx==i){
				ans=max(ans,v[i].second);
			}else{
				ans=max(ans,psum[max_idx]-psum[i]+v[i].second);
			}
			
		}
		cout<<ans;
	}
	return 0;
}
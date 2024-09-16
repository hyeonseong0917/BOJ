#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		vector<ll> psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			psum[i]=i==0?v[i]:psum[i-1]+v[i];
		}
		// m개의 블루레이에 모든 동영상을 넣어야됨
		// 블루레이의 길이 중 가장 최소 길이
		ll L=1, R=psum[n-1];
		ll ans=1222232421;
		while(L<=R){
			ll mid=(L+R)/2;
			// mid로 블루레이의 길이를 책정했을 때, m개로 나눌 수 있는지?
			ll cur_sum=0;
			ll cur_cnt=1;
			bool flag=0;
			for(ll i=0;i<n;++i){
				if(cur_sum+v[i]<=mid){
					cur_sum+=v[i];
				}else{
					cur_sum=v[i];
					if(cur_sum>mid){
						flag=1;
						break;
					}
					++cur_cnt;
				}
			}
			if(flag){
				L=mid+1;
				continue;
			}
			if(cur_cnt<=m){
				ans=min(ans,mid);
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		cout<<ans;

	}
	return 0;
}
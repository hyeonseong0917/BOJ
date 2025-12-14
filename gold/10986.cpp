#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			v[i]%=m;
		}
		vector<ll> psum(n,0);
		psum[0]=v[0];
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i];
			psum[i]%=m;
		}
		// psum_idx[x]: psum y에 대해, 어떤 인덱스들을 가지고있는지?
		vector<ll> psum_idx[m];
		for(ll i=0;i<n;++i){
			psum_idx[psum[i]].push_back(i);
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			ll b=(psum[i]-v[i]+m)%m;
			if(psum_idx[b].empty()) continue;
			ll ps=psum_idx[b].size();
			ll L=0, R=ps-1;
			// i보다 크거나 같은 값의 개수를 구한다
			// i보다 크거나 같은 최소 인덱스를 구한다
			ll min_idx=ps;
			while(L<=R){
				ll mid=(L+R)/2;
				if(psum_idx[b][mid]>=i){
					min_idx=min(min_idx,mid);
					R=mid-1;
				}else{
					L=mid+1;
				}
			}
			ans+=ps-min_idx;
			// cout<<i<<" "<<ps-min_idx<<endl;
		}
		cout<<ans;
	}
	return 0;
}
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
		ll d,n,m;
		cin>>d>>n>>m;
		vector<ll> v;
		v.push_back(0);
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			v.push_back(a);
		}
		v.push_back(d);
		sort(v.begin(),v.end());
		ll L=0, R=d;
		ll ans=0;
		while(L<=R){
			ll mid=(L+R)/2;
			// 최소 점프 길이가 mid일 때, 해당 조건 통과 가능?
			ll cnt=0;
			ll sum=0;
			for(ll i=1;i<v.size();++i){
				sum+=v[i]-v[i-1];
				if(sum<mid){
					++cnt;
				}else{
					sum=0;
				}
			}
			// cout<<mid<<endl;
			if(cnt<=m){
				ans=max(ans,mid);
				L=mid+1;
			}else{
				if(cnt<m){
					L=mid+1;
				}else{
					// cnt>m
					R=mid-1;
				}
			}
		}
		cout<<ans;
		
		
	}
	return 0;
}
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
	ll t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		vector<ll> A(n,0), B(m,0);
		for(ll i=0;i<n;++i){
			cin>>A[i];
		}
		for(ll i=0;i<m;++i){
			cin>>B[i];
		}
		sort(B.begin(),B.end());
		ll ans=0;
		for(ll i=0;i<n;++i){
			ll a=A[i];
			ll L=0, R=m-1;
			// a보다 작은 최대의 인덱스 구하기
			ll max_idx=-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(B[mid]<a){
					max_idx=max(max_idx,mid);
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			ans+=(max_idx+1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
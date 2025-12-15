#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
#include <stack>
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
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			// a보다 크거나 같은 최소의 인덱스
			ll min_idx=n;
			ll L=0, R=n-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid]>=a){
					min_idx=min(min_idx,mid);
					R=mid-1;
				}else{
					L=mid+1;
				}
			}
			// b보다 작거나 같은 최대의 인덱스
			ll max_idx=-1;
			L=0, R=n-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid]<=b){
					max_idx=max(max_idx,mid);
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			if(min_idx==n || max_idx==-1){
				cout<<0<<"\n";
			}else{
				ll ans=max(0ll,max_idx-min_idx+1);
				cout<<ans<<"\n";
			}
		}
		return 0;
	} 
	return 0;
}
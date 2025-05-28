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
		// 3 2 1
		// 1 3 4 2
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll idx=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<0;
			continue;
		}
		ll L=1, R=n-1;
		ll ans=n-1;
		while(L<=R){
			ll mid=(L+R)/2;
			// mid를 v[0]으로, 
			bool flag=0;
			vector<ll> tmp;
			for(ll i=0;i<n;++i){
				if(v[i]<=mid) continue;
				tmp.push_back(v[i]);
			}
			for(ll i=0;i<tmp.size()-1;++i){
				if(tmp[i]+1!=tmp[i+1]){
					flag=1;
					break;
				}
			}
			if(flag){
				L=mid+1;
			}else{
				ll c=mid;
				if(c==v[0]){
					--c;
				}
				ans=min(ans,c);
				R=mid-1;
			}
		}
		cout<<ans;
	} 
	return 0;
}
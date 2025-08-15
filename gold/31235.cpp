#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll L=1, R=n;
		ll ans=n;
		while(L<=R){
			// cout<<L<<" "<<R<<endl;
			ll mid=(L+R)/2;
			bool flag=0;
			vector<ll> tmp;
			ll max_num=0;
			ll max_idx=-1;
			for(ll i=0;i<mid;++i){
				if(max_num<=v[i]){
					max_idx=i;
					max_num=v[max_idx];
				}
			}
			for(ll i=mid;i<n;++i){
				if(max_num<=v[i]){
					max_num=v[i];
					max_idx=i;
					continue;
				}
				if(i-max_idx+1>mid){
					flag=1;
					break;
				}
			}
			if(flag){
				L=mid+1;
			}else{
				ans=min(ans,mid);
				R=mid-1;
			}
		}
		cout<<ans;

	}
	return 0;
}
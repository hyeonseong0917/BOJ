#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,x;
		cin>>n>>x;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll L=1, R=n;
		ll ans=R;
		while(L<=R){
			ll mid=(L+R)/2;
			priority_queue<ll> pq;
			for(ll i=0;i<mid;++i){
				pq.push(0);
			}
			bool flag=0;
			for(ll i=0;i<n;++i){
				ll cur_num=pq.top()*-1;
				pq.pop();
				if(cur_num+v[i]<=x){
					pq.push((cur_num+v[i])*-1);
				}else{
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
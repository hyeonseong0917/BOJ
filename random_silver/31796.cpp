#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll L=1, R=n;
		ll ans=2023101800;
		while(L<=R){
			ll mid=(L+R)/2;
			// mid개로 가능한지?
			priority_queue<ll> pq;
			ll ps=0;
			for(ll i=0;i<n;++i){
				if(i==0){
					pq.push(v[i]*-1);
					++ps;
				}else{
					ll pt=pq.top()*-1;
					if(pt*2<=v[i]){
						while(!pq.empty()){
							pt=pq.top()*-1;
							pq.pop();
							if(pt*2>v[i]){
								break;
							}
						}
						if(pq.empty()){
							pq.push(v[i]*-1);
							++ps;
						}
					}
				}
			}
			if(ps>mid){
				L=mid+1;
			}else{
				R=mid-1;
				ans=min(ans,mid);
			}
		}
		cout<<ans;
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		priority_queue<ll> pq;
		for(ll i=0;i<n;++i){
			ll a=0;
			cin>>a;
			if(a==0) continue;
			pq.push(a*-1);
		}
		// 32 32 64 64 64 256 256 256 512 512 512
		ll ans=0;
		while(!pq.empty()){
			ll ps=pq.size();
			if(ps==1){
				ans=max(ans,pq.top()*-1);
				break;
			}
			ll fst_num=pq.top()*-1;
			pq.pop();
			ll sed_num=pq.top()*-1;
			pq.pop();
			if(fst_num==sed_num){
				pq.push(fst_num*2*-1);
				ans=max(ans,fst_num*2*-1);
			}else{
				pq.push(sed_num*-1);
				ans=max(ans,sed_num*-1);
			}
		}
		cout<<ans;
	}
	
	return 0;
}
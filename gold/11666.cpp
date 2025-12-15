#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
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
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end());
		ll cnt=1;
		priority_queue<ll> pq;
		pq.push((v[0].first+v[0].second)*-1);
		for(ll i=1;i<n;++i){
			// ll c=pq.top()*-1;
			ll cur_start=v[i].first;
			ll cur_len=v[i].second;
			while(!pq.empty()){
				ll c=pq.top()*-1;
				if(c+m+1<=cur_start){
					pq.pop();
				}else{
					if(c<=cur_start && cur_start<=c+m){
						pq.pop();
						pq.push((cur_start+cur_len)*-1);
						break;
					}else{
						++cnt;
						pq.push((cur_start+cur_len)*-1);
						break;
					}
				}
			}
			if(pq.empty()){
				++cnt;
				pq.push((cur_start+cur_len)*-1);
			}
			// if(c+m+1<=cur_start){
			// 	pq.pop();
			// 	++cnt;
			// 	pq.push((cur_start+cur_len)*-1);
			// }else{
			// 	if(c<=cur_start && cur_start<=c+m){
			// 		pq.pop();
			// 		pq.push((cur_start+cur_len)*-1);
			// 	}else{
			// 		// cur_start<c
			// 		pq.push((cur_start+cur_len)*-1);
			// 		++cnt;
			// 	}
			// }
		}
		cout<<n-cnt;
	}
	return 0;
}
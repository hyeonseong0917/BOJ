#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long




int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		vector<pair<ll,ll>> p;
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			p.push_back({a,b});
		}
		sort(p.begin(),p.end());
		priority_queue<ll> pq;
		ll idx=0;
		ll ans=0;
		// [2,6,7,8,9]
		// [0,3]
		// [2,5]
		// [4,9]
		// [8,13]
		for(ll i=0;i<n;++i){
			// v[i]에 대해 어디까지?
			while(idx<=m-1){
				if(p[idx].first<=v[i]){
					pq.push(p[idx].second*-1);
					++idx;
				}else{
					break;
				}
			}
			while(!pq.empty()){
				ll cur_num=pq.top()*-1;
				pq.pop();
				if(v[i]<=cur_num){
					++ans;
					break;
				}
			}
		}
		cout<<ans;
	}

	return 0;
}
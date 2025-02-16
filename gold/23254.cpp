#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=1;
	while(t--){
		ll n,m;
		cin>>n>>m;
		priority_queue<pair<ll,ll>> pq;
		vector<ll> a(m,0), b(m,0);
		ll ans=0;
		for(ll i=0;i<m;++i){
			cin>>a[i];
		}
		for(ll i=0;i<m;++i){
			cin>>b[i];
		}
		for(ll i=0;i<m;++i){
			pq.push({min(b[i],100-a[i]),a[i]*-1});
		}
		ll cnt=24*n;
		while(!pq.empty() && cnt){
			ll cur_w=pq.top().first;
			ll cur_score=pq.top().second*-1;
			pq.pop();
			if(cur_score==100){
				ans+=100;
				continue;
			}
			cur_score+=cur_w;
			--cnt;
			cur_score=min(cur_score,100ll);
			pq.push({min(cur_w,100-cur_score),cur_score*-1});
		}
		while(!pq.empty()){
			ans+=pq.top().second*-1;
			pq.pop();
		}
		cout<<ans;
	}

	return 0;
}
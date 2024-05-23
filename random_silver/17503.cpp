#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;


#define ll long long
bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first>b.first;

}
int main() {
	
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int t=1;
	while(t--){
		ll N,M,K;
		cin>>N>>M>>K;
		vector<pair<ll,ll>> v;
		ll L=(ll)pow(2,31);
		ll R=0;
		for(ll i=0;i<K;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
			L=min(L,b);
			R=max(R,b);
		}
		sort(v.begin(),v.end(),comp);
		ll max_sum=0;
		for(ll i=0;i<N;++i){
			max_sum+=v[i].first;			
		}
		if(max_sum<M){
			cout<<-1;
			break;
		}
		ll ans=R;
		bool flag=0;
		while(L<=R){
			ll mid=(L+R)/2;
			// 도수 레벨을 mid로 설정했을 때 합을 M이상으로 할 수 있을까?
			priority_queue<ll> pq;
			for(ll i=0;i<K;++i){
				if(v[i].second>mid) continue;
				if(pq.empty() || pq.size()<N){
					pq.push(-1*v[i].first);
				}else{
					if(v[i].first>pq.top()*-1){
						pq.pop();
						pq.push(-1*v[i].first);
					}
				}
			}
			ll sum=0;
			if(pq.size()!=N){
				L=mid+1;
				continue;
			}
			while(!pq.empty()){
				sum+=pq.top()*-1;
				pq.pop();
			}
			if(sum>=M){
				flag=1;
				ans=min(ans,mid);
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		if(!flag){
			cout<<-1;
		}else{
			cout<<ans;
		}
	}
	
	return 0;
}
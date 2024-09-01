#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		ll n,m,k;
		cin>>n>>m>>k;
		ll max_size=max(n,m);
		queue<pair<pair<ll,ll>,pair<ll,ll>>> q[max_size+1];
		for(ll i=1;i<=n;++i){
			ll a,b;
			cin>>a>>b;
			if(i%m==0){
				q[m].push({{a,b},{m*-1,i*-1}});
			}else{
				q[i%m].push({{a,b},{(i%m)*-1,i*-1}});
			}
		}
		priority_queue<pair<pair<ll,ll>,pair<ll,ll>>> pq;
		for(ll i=1;i<=m;++i){
			if(q[i].empty()) continue;
			pair<pair<ll,ll>,pair<ll,ll>> p=q[i].front();
			q[i].pop();
			pq.push(p);
		}
		ll cnt=0;
		while(!pq.empty()){
			ll line_num=pq.top().second.first*-1;
			ll cur_num=pq.top().second.second*-1;
			pq.pop();
			// cout<<line_num<<" "<<cur_num<<" "<<cnt<<endl;
			if(cur_num==k+1){
				break;
			}
			++cnt;
			ll c=line_num%m;
			if(c==0) c=m;
			if(q[c].empty()) continue;
			pq.push(q[c].front());
			q[c].pop();
		}
		cout<<cnt;
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
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
		vector<ll> v(n+1,0), p(n+1,0);
		vector<ll> g[n+1];
		p[1]=1;
		for(ll i=2;i<=n;++i){
			cin>>p[i];
			// i의 부모는 p[i]
			g[p[i]].push_back(i);
		}
		// v[i]: i의 값
		for(ll i=1;i<=n;++i){
			cin>>v[i];
		}
		priority_queue<pair<ll,ll>> pq;
		// 값,노드이름
		vector<ll> check(n+1,0);
		ll cnt=1;
		// check[1]=cnt;
		pq.push({v[1],1});
		while(!pq.empty()){
			ll cur_val=pq.top().first;
			ll cur_num=pq.top().second;
			check[cur_num]=cnt++;
			pq.pop();
			for(ll i=0;i<g[cur_num].size();++i){
				ll next_num=g[cur_num][i];
				ll next_val=v[next_num];
				pq.push({next_val,next_num});
			}
		}
		vector<pair<ll,ll>> pp;
		// check[x]: x번 노드를 check[x]번째에 방문
		for(ll i=1;i<=n;++i){
			// cout<<i<<" "<<check[i]<<endl;
			pp.push_back({check[i],i});
		}
		sort(pp.begin(),pp.end());
		ll sum=0;
		for(ll i=0;i<n;++i){
			// cout<<i<<" "<<pp[i].second<<endl;
			sum+=v[pp[i].second];
			cout<<sum<<"\n";
		}
	}
	return 0;
}
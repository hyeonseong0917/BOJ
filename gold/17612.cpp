#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

vector<ll> g[100000+1];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 1540
		// n명의 고객들
		// k개의 계산대가 있음
		// 두 계산대에서 기다리는 시간 같음 -> 가장 번호 작은 곳
		// 같은 시간에 계산 끝났다면 높은 번호 손님 순서대로 빠져나감
		ll n,k;
		cin>>n>>k;
		vector<pair<ll,ll>> v;
		vector<ll> check(1000000+1,0);
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			// 고객 id, 구입한 물건 수
			v.push_back({a,b});
			// id가 a인 사람은 b의 시간이 걸림
			check[a]=b;
		}
		// k개의 계산대가 있음
		// 가장 빨리 마칠 수 있는 계산대로 안내함
		// 두 계산대의 대기 시간 같다면 가장 번호 작은 곳으로
		priority_queue<pair<ll,ll>> pq;
		for(ll i=1;i<=k;++i){
			pq.push({0,i*-1});
		}
		// 대기시간,계산대번호,
		// g[x]={123,124,125..}
		vector<ll> calc_num(1000000+1,0);
		for(ll i=0;i<n;++i){
			// i번째 고객을 넣어야함
			ll cur_id=v[i].first;
			ll cur_time=v[i].second;

			// 현재 계산할 계산대
			ll wait_time=pq.top().first*-1;
			ll wait_num=pq.top().second*-1;
			pq.pop();
			wait_time+=cur_time;
			pq.push({wait_time*-1,wait_num*-1});
			g[wait_num].push_back(cur_id);
			calc_num[cur_id]=wait_num;
		}
		map<ll,priority_queue<pair<ll,ll>>> m;
		for(ll i=1;i<=k;++i){
			ll fin_time=0;
			for(ll j=0;j<g[i].size();++j){
				fin_time+=check[g[i][j]];
				m[fin_time].push({calc_num[g[i][j]],g[i][j]});
				// cout<<i<<" "<<fin_time<<endl;
			}
		}
		ll ans=0;
		ll idx=1;
		for(ll i=1;i<=2000000;++i){
			while(!m[i].empty()){
				ll cur_num=m[i].top().second;
				// cout<<i<<" "<<cur_num<<endl;
				m[i].pop();
				ans+=idx*cur_num;
				++idx;
			}
		}
		// cout<<idx<<endl;
		cout<<ans;

	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// 1. 우선순위 값이 제일 큰 프로세스
		// 2. 우선순위 제일 큰거 여러개라면 id가 가장 작은거
		// 1초 지난 후 ids제외 우선순위 +1,
		// 프로세스 id가 ids인 프로세스의 필요시간 -1
		ll t,n;
		cin>>t>>n;
		// pid, 실행 마치는데 필요한 시간 bi, 초기 우선순위 ci
		priority_queue<pair<ll,pair<ll,ll>>> pq;
		for(ll i=0;i<n;++i){
			ll a,b,c;
			// id, 실행시간, 초기 우선순위
			cin>>a>>b>>c;

			// 우선순위,id,실행시간
			pq.push({c,{a*-1,b}});
		}
		while(t-- && !pq.empty()){
			ll cur_id=pq.top().second.first*-1;
			ll cur_prior=pq.top().first;
			ll cur_time=pq.top().second.second;
			pq.pop();
			cout<<cur_id<<"\n";
			--cur_prior;
			--cur_time;
			if(cur_time==0) continue;
			pq.push({cur_prior,{cur_id*-1,cur_time}});
		}

	}
	return 0;
}
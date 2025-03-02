#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

#define ll long long

ll V,M;
vector<pair<ll,ll>> v[100+1];
vector<ll> j_dist(100+1,2023101800);
vector<ll> s_dist(100+1,2023101800);
ll J,S;
void jd(ll cur_start){
	j_dist[cur_start]=0;
	priority_queue<pair<ll,ll>> pq;
	pq.push({0,cur_start});
	while(!pq.empty()){
		ll cur_dist=pq.top().first*-1;
		ll cur_pos=pq.top().second;
		pq.pop();
		for(ll i=0;i<v[cur_pos].size();++i){
			ll next_pos=v[cur_pos][i].first;
			ll next_dist=v[cur_pos][i].second;
			if(next_dist+cur_dist<j_dist[next_pos]){
				j_dist[next_pos]=next_dist+cur_dist;
				pq.push({j_dist[next_pos]*-1,next_pos});
			}
		}
	}
}
void sd(ll cur_start){
	s_dist[cur_start]=0;
	priority_queue<pair<ll,ll>> pq;
	pq.push({0,cur_start});
	while(!pq.empty()){
		ll cur_dist=pq.top().first*-1;
		ll cur_pos=pq.top().second;
		pq.pop();
		for(ll i=0;i<v[cur_pos].size();++i){
			ll next_pos=v[cur_pos][i].first;
			ll next_dist=v[cur_pos][i].second;
			if(next_dist+cur_dist<s_dist[next_pos]){
				s_dist[next_pos]=next_dist+cur_dist;
				pq.push({s_dist[next_pos]*-1,next_pos});
			}
		}
	}
}

int main() {
	// your code goes here
	int t=1;
	while(t--){
		cin>>V>>M;
		for(ll i=0;i<M;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v[a].push_back({b,c});
			v[b].push_back({a,c});
		}
		cin>>J>>S;
		jd(J);
		sd(S);
		// 1. J와 S가 아닌 점들 중 각 dist의 합이 최소인 값 찾기
		// 2. 최소인 값을 가지는 점들 K 찾기
		// 3. K인 점들 중에서 JDIST가 더 크면 제외
		// 4. 현재까지 후보인 K들을 오름차순 정렬 후 최솟값 찾기
		ll min_dist=2023101800;
		for(ll i=1;i<=V;++i){
			if(i==J || i==S) continue;
			min_dist=min(min_dist,j_dist[i]+s_dist[i]);
		}
		if(min_dist==2023101800){
			cout<<-1;
			break;
		}
		// cout<<min_dist<<"\n";
		vector<pair<ll,ll>> tmp;
		for(ll i=1;i<=V;++i){
			if(i==J || i==S) continue;
			if(s_dist[i]<j_dist[i]) continue;
			if(s_dist[i]+j_dist[i]==min_dist){
				// cout<<i<<endl;
				tmp.push_back({j_dist[i],i});
			}
		}
		// tmp[i]인 점들은 min_dist임
		sort(tmp.begin(),tmp.end());
		if(tmp.empty()){
			cout<<-1;
		}else{
			cout<<tmp[0].second;
		}
	}

	return 0;
}
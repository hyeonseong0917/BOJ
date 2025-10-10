#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

vector<ll> parent;
ll FIND(ll a){
	if(a==parent[a]){
		return a;
	}
	return parent[a]=FIND(parent[a]);
}
void UNION(ll a, ll b){
	a=FIND(a);
	b=FIND(b);
	if(a!=b){
		parent[a]=b;
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m,k;
		cin>>n>>m>>k;
		// house[a]: a위치에 발전소가 있음
		vector<ll> house(n+1,0);
		for(ll i=0;i<k;++i){
			ll a;
			cin>>a;
			++house[a];
		}
		vector<pair<ll,pair<ll,ll>>> v;
		for(ll i=0;i<m;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v.push_back({c,{a,b}});
		}
		parent=vector<ll>(n+1,0);
		for(ll i=1;i<=n;++i){
			parent[i]=i;
		}
		sort(v.begin(),v.end());
		ll node_cnt=n-k;
		ll cur_cnt=0;
		ll cost=0;
		vector<ll> check(n+1,0);
		for(ll i=0;i<m;++i){
			if(cur_cnt==node_cnt){
				break;
			}
			ll cur_dist=v[i].first;
			ll cur_pos=v[i].second.first;
			ll next_pos=v[i].second.second;
			if(house[cur_pos] && house[next_pos]) continue;
			if(!house[cur_pos] && !house[next_pos]){
				// 둘 다 충전소가 아님
				// cur_pos와 next_pos의 조상이 같은지??
				ll cur_pos_root=FIND(cur_pos);
				ll next_pos_root=FIND(next_pos);
				if(cur_pos_root==next_pos_root) continue;
				if(house[cur_pos_root] && house[next_pos_root]) continue;
				if(house[cur_pos_root]){
					UNION(next_pos,cur_pos);
				}else{
					UNION(cur_pos,next_pos);
				}
				++cur_cnt;
				cost+=cur_dist;
			}else{
				// 한 곳은 충전소임
				// next_pos를 충전소로 고정
				ll tmp_pos=cur_pos;
				if(house[cur_pos]){
					cur_pos=next_pos;
					next_pos=tmp_pos;
				}
				ll cur_pos_root=FIND(cur_pos);
				if(house[cur_pos_root]) continue;
				UNION(cur_pos,next_pos);
				++cur_cnt;
				cost+=cur_dist;
			}
			
		}
		cout<<cost;
	}
	return 0;
}

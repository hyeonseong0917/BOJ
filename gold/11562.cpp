#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll n,m;
vector<ll> v[250+1];
// r[x]: x에 일방통행으로 이어지는 길
vector<ll> r[250+1];

ll dist[251][251];
ll check[251];
void BFS(ll start_num){
	dist[start_num][start_num]=0;
	for(ll i=0;i<=250;++i){
		check[i]=2023101800;
	}
	check[start_num]=0;
	queue<ll> q;
	q.push(start_num);
	while(!q.empty()){
		ll cur_num=q.front();
		q.pop();
		for(ll i=0;i<v[cur_num].size();++i){
			ll next_num=v[cur_num][i];
			if(check[next_num]>check[cur_num]){
				check[next_num]=check[cur_num];
				q.push(next_num);
			}
		}
		for(ll i=0;i<r[cur_num].size();++i){
			ll next_num=r[cur_num][i];
			if(check[next_num]>check[cur_num]+1){
				check[next_num]=check[cur_num]+1;
				q.push(next_num);
			}
		}
	}
	for(ll i=1;i<=n;++i){
		dist[start_num][i]=check[i];
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		for(ll i=0;i<=250;++i){
			for(ll j=0;j<=250;++j){
				dist[i][j]=2023101800;
			}
		}
		cin>>n>>m;
		for(ll i=0;i<m;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			if(c==1){
				v[a].push_back(b);
				v[b].push_back(a);
			}else{
				v[a].push_back(b);
				r[b].push_back(a);
			}
		}
		// 1에서 n까지 있다
		for(ll i=1;i<=n;++i){
			// i에서 다익스트라 해서 dist[i][j]를 채운다
			// dist[i][j]: i에서 j까지 가기 위해 최소로 추가로 놓아야 하는 다리의 수
			BFS(i);
		}
		ll K;
		cin>>K;
		while(K--){
			ll a,b;
			cin>>a>>b;
			// a와 b를 잇는데 최소 몇 개의 일방통행 길을 양방으로 만들어야 하는지?
			if(a==b){
				cout<<0<<"\n";
			}else{
				cout<<dist[a][b]<<"\n";
			}
		}
	}
	return 0;
}
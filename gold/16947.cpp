#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long

ll n;
vector<ll> v[3000+1];
vector<ll> visited(3000+1);
bool is_cycle=0;
// 사이클이 있는지 어떻게 찾아야????
queue<ll> q;
vector<ll> cycle_node;
void dfs(ll cur_num, ll pre_num){
	if(is_cycle) return;
	for(ll i=0;i<v[cur_num].size();++i){
		ll next_num=v[cur_num][i];
		if(visited[next_num] && next_num!=pre_num){
			is_cycle=1;
			q.push(cur_num);
			map<ll,ll> check;
			check[cur_num]=1;
			while(!q.empty()){
				ll node=q.front();
				q.pop();
				cycle_node.push_back(node);
				
				for(ll i=0;i<v[node].size();++i){
					ll next_node=v[node][i];
					if(visited[next_node] && next_node!=next_num && !check[next_node]){
						check[next_node]=1;
						q.push(next_node);
					}
				}
			}
			cycle_node.push_back(next_num);
			break;
		}
		if(!visited[next_num]){
			visited[next_num]=1;
			dfs(next_num,cur_num);
			visited[next_num]=0;
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){	
		cin>>n;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		visited[1]=1;
		dfs(1,1);
		ll cs=cycle_node.size();
		// cout<<cs<<endl;
		map<ll,ll> is_cycle;
		for(ll i=0;i<cs;++i){
			// cout<<cycle_node[i]<<endl;
			++is_cycle[cycle_node[i]];
		}
		
		for(ll i=1;i<=n;++i){
			if(is_cycle[i]){
				cout<<0<<" ";
			}else{
				// i부터 is_cycle 마주칠 때까지
				queue<pair<ll,ll>> q;
				q.push({i,0}); // {현재 위치, 거리}
				for(ll j=1;j<=n;++j){
					visited[j]=0;
				}
				visited[i]=1;
				while(!q.empty()){
					ll cur_num=q.front().first;
					ll cur_dist=q.front().second;
					q.pop();
					if(is_cycle[cur_num]){
						cout<<cur_dist<<" ";
						break;
					}
					for(ll i=0;i<v[cur_num].size();++i){
						ll next_num=v[cur_num][i];
						if(!visited[next_num]){
							visited[next_num]=1;
							q.push({next_num,cur_dist+1});
						}
					}
				}
			}
		}
	}
	return 0;
}
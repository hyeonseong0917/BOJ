#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

int N,M;
int beg,fin;
const int MAX=1000+1;
int INF=1222232421;
int dist[MAX];
vector<pair<int,int>> v[MAX];
void Init(){
	for(int i=0;i<MAX;++i){
		v[i].clear();
	}
	for(int i=0;i<MAX;++i){
		dist[i]=INF;
	}
}
void Input(){
	cin>>N>>M;
	for(int i=0;i<M;++i){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back({b,c});
	}
	cin>>beg>>fin;
}
int ans_dist;
vector<int> ans_vector;

void dijkstra(int cur_beg, int cur_fin){
	dist[cur_beg]=0;
	priority_queue<pair<int,pair<int,vector<int>>>> pq;
	vector<int> init_vector;
	init_vector.push_back(cur_beg);
	pq.push({0,{cur_beg,init_vector}});
	while(!pq.empty()){
		int cur_dist=pq.top().first*-1;
		int cur_pos=pq.top().second.first;
		vector<int> cur_dist_vector=pq.top().second.second;
		if(cur_pos==cur_fin){
			ans_dist=cur_dist;
			for(int i=0;i<cur_dist_vector.size();++i){
				ans_vector.push_back(cur_dist_vector[i]);
			}
			return;
		}
		pq.pop();
		for(int i=0;i<v[cur_pos].size();++i){
			int next_pos=v[cur_pos][i].first;
			int next_dist=v[cur_pos][i].second;
			if(dist[next_pos]>dist[cur_pos]+next_dist){
				dist[next_pos]=dist[cur_pos]+next_dist;
				cur_dist_vector.push_back(next_pos);
				pq.push({dist[next_pos]*-1,{next_pos,cur_dist_vector}});
				cur_dist_vector.pop_back();
			}
		}
	}

}
void solve(){
	dijkstra(beg,fin);
	cout<<ans_dist<<"\n";
	cout<<ans_vector.size()<<"\n";
	for(int i=0;i<ans_vector.size();++i){
		cout<<ans_vector[i]<<" ";
	}
}
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Init();
	Input();
	solve();
	return 0;
}
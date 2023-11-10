#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long


const int MAX=2000+1;
int INF=122232421;
// s->g/h->h/g->x
int s_to_x[MAX]; //s에서 x까지 가는 모든 거리 저장
int g_to_x[MAX]; //g에서 x까지 가는 모든 거리 저장
int h_to_x[MAX]; //h에서 x까지 가는 모든 거리 저장
int tmp[MAX];

vector<int> dest, ans;
vector<pair<int,int>> graph[MAX];
int n=0,T=0,m=0,t=0;
int s,g,h;

void init(){
	dest.clear();
	ans.clear();
	for(int i=0;i<MAX;++i){
		graph[i].clear();
		s_to_x[i]=INF;
		g_to_x[i]=INF;
		h_to_x[i]=INF;
	}
}

void dijkstra(int start, int flag){
	if(flag==0){
		for(int i=0;i<MAX;++i){
			tmp[i]=s_to_x[i];
		}
	}else if(flag==1){
		for(int i=0;i<MAX;++i){
			tmp[i]=g_to_x[i];
		}
	}else{
		for(int i=0;i<MAX;++i){
			tmp[i]=h_to_x[i];
		}
	}
	priority_queue<pair<int,int>> pq;
	pq.push({0,start});
	tmp[start]=0;
	while(!pq.empty()){
		int cur_dist=pq.top().first*-1;
		int cur_pos=pq.top().second;
		pq.pop();
		for(int i=0;i<graph[cur_pos].size();++i){
			int next_pos=graph[cur_pos][i].first;
			int next_dist=graph[cur_pos][i].second;
			if(tmp[next_pos]>cur_dist+next_dist){
				tmp[next_pos]=cur_dist+next_dist;
				pq.push({tmp[next_pos]*-1,next_pos});
			}
		}
	}
	if(flag==0){
		for(int i=0;i<MAX;++i){
			s_to_x[i]=tmp[i];
		}
	}else if(flag==1){
		for(int i=0;i<MAX;++i){
			g_to_x[i]=tmp[i];
		}
	}else{
		for(int i=0;i<MAX;++i){
			h_to_x[i]=tmp[i];
		}
	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>T;
	while(T--){
		int g_to_h=INF;
		cin>>n>>m>>t;
		cin>>s>>g>>h;
		init();
		for(int i=0;i<m;++i){
			int a,b,d;
			cin>>a>>b>>d;
			graph[a].push_back({b,d});
			graph[b].push_back({a,d});
		}
		for(int i=0;i<graph[g].size();++i){
			if(graph[g][i].first==h){
				g_to_h=graph[g][i].second;
			}else if(graph[h][i].first==g){
				g_to_h=graph[h][i].second;
			}
		}
		for(int i=0;i<t;++i){
			int x=0;
			cin>>x;
			dest.push_back(x);
		}
		dijkstra(s,0);
		dijkstra(g,1);
		g_to_h=g_to_x[h];
		dijkstra(h,2);
		sort(dest.begin(),dest.end());
		for(int i=0;i<t;++i){
			int cur_dest=dest[i];
			if(s_to_x[cur_dest]==s_to_x[g]+g_to_h+h_to_x[cur_dest]){
				cout<<cur_dest<<" ";
			}else if(s_to_x[cur_dest]==s_to_x[h]+g_to_h+g_to_x[cur_dest]){
				cout<<cur_dest<<" ";
			}
			
		}
		
		// for(int i=0;i<ans.size();++i){
		// 	cout<<ans[i]<<" ";
		// }
		cout<<"\n";
	}
	
	return 0;
}
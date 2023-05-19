#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 100000+1;

int N, M,s,e;
int parent[MAX];
vector<int> graph[MAX];
vector<pair<int,pair<int,int>>> v;
bool comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
	return a.first>b.first;
}
int Find(int num){
	if(num==parent[num]){
		return num;
	}
	int next=Find(parent[num]);
	parent[num]=next;
	return next;
}
void Union(int a, int b){
	int a=Find(a);
	int b=Find(b);
	if(a>b){
		parent[a]=b;
	}else{
		parent[b]=Find(a);
	}
	
}
bool visited[MAX];
int BFS(int start){
	queue<int> q;
	q.push(start);
	
	visited[start]=1;
	while(!q.empty()){
		int curPos=q.front();
		// cout<<curPos<<" "<<e<<endl;
		if(curPos==e){
			return 1;
		}
		q.pop();
		for(int i=0;i<graph[curPos].size();++i){
			int next=graph[curPos][i];
			// cout<<curPos<<" "<<next<<endl;
			if(!visited[next]){
				visited[next]=1;
				q.push(next);
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin>>N>>M;
	cin>>s>>e;
	for (int i = 1; i <= N; ++i){
		parent[i] = i;
	} 
	
	for (int i = 0; i < M; ++i){
		int a,b,c=0;
		cin>>a>>b>>c;
		v.push_back({c,{a,b}});
	}
	sort(v.begin(),v.end(),comp);
	int ans=122232421;
	for(int i=0;i<M;++i){
		int a=v[i].second.first;
		int b=v[i].second.second;
		int c=v[i].first;
		graph[a].push_back(b);
		graph[b].push_back(a);
		
		if(Find(a)!=Find(b)){
			Union(a,b);
			ans=min(ans,c);
			// memset(visited,0,sizeof(visited));	
			if(BFS(s)==1){
				cout<<ans;
				break;
			}
		}
	}
	// cout<<ans;
    return 0;
}
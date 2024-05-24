#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long


int N,M;
int teleport[100+1];
bool visited[100+1];
void Input(){
	cin>>N>>M;
	for(int i=0;i<100+1;++i){
		teleport[i]=i;
	}
	for(int i=0;i<N+M;++i){
		int a,b;
		cin>>a>>b;
		teleport[a]=b;
	}
}
int BFS(){
	queue<pair<int,int>> q;
	q.push({1,0});
	visited[1]=1;
	while(!q.empty()){
		int cur_pos=q.front().first;
		int cur_cnt=q.front().second;
		if(cur_pos==100){
			return cur_cnt;
		}
		q.pop();
		for(int i=1;i<=6;++i){
			if(cur_pos+i>100) continue;
			int next_pos=teleport[cur_pos+i];
			if(visited[next_pos]) continue;
			visited[next_pos]=1;
			q.push({next_pos,cur_cnt+1});
		}
	}
	return -1;
}

void solve(){
	cout<<BFS();
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();

	return 0;
}
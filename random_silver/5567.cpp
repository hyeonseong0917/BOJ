#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

int N,M;
const int MAX=500+1;
vector<int> g[MAX];
bool visited[MAX];
void Input(){
	cin>>N;
	cin>>M;
	for(int i=0;i<M;++i){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}
int ans=0;
map<int,int> m;
void dfs(int cur_num, int cnt){
	if(cnt==0){
		if(!m[cur_num]){
			m[cur_num]=1;
			++ans;
		}
		return;
	}
	for(int i=0;i<g[cur_num].size();++i){
		int next_num=g[cur_num][i];
		if(visited[next_num]) continue;
		visited[next_num]=1;
		dfs(next_num, cnt-1);
		visited[next_num]=0;
	}
}
void solve(){
	visited[1]=1;
	dfs(1,1);
	for(int i=0;i<MAX;++i){
		visited[i]=0;
	}
	visited[1]=1;
	dfs(1,2);
	cout<<ans;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	return 0;
}
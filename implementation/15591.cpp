#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,Q;
const int MAX=5000+1;
vector<pair<int,int>> G[MAX];
int U[MAX][MAX];
bool visited[MAX];
vector<pair<int,int>> ans;
void Input(){
	cin>>N>>Q;
	for(int i=0;i<N-1;++i){
		int p,q,r;
		cin>>p>>q>>r;
		G[p].push_back({q,r});
		G[q].push_back({p,r});
	}
	for(int i=0;i<Q;++i){
		int k,v;
		cin>>k>>v;
		ans.push_back({k,v});
	}
}
void dfs(int initPos, int curPos, int minNum){
	for(int i=0;i<G[curPos].size();++i){
		int nextPos=G[curPos][i].first;
		int cost=G[curPos][i].second;
		if(!visited[nextPos]){
			visited[nextPos]=1;
			U[initPos][nextPos]=min(minNum,cost);
			dfs(initPos,nextPos,min(minNum,cost));
		}
	}
}
void solve(){
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			U[i][j]=0;
		}
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			visited[j]=0;
		}
		visited[i]=1;
		dfs(i,i,1000000000+1);
	}
	for(int i=0;i<ans.size();++i){
		int curUsado=ans[i].first;
		int curNum=ans[i].second;
		int cnt=0;
		for(int j=1;j<=N;++j){
			if(curNum==j) continue;
			if(U[curNum][j]>=curUsado){
				++cnt;
			}
		}
		cout<<cnt<<"\n";
	}
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}
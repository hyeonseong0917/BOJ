#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M=0;
const int MAX=2000+1;
vector<int> graph[MAX];
bool visited[MAX];
void Input(){
	cin>>N>>M;
	for(int i=0;i<M;++i){
		int a,b=0;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}
bool flag=0;
void dfs(int curNum, int cnt){
	// cout<<curNum<<" "<<cnt<<endl;
	if(cnt==4){
		flag=1;
		return;
	}
	visited[curNum]=1;
	for(int i=0;i<graph[curNum].size();++i){
		int s=graph[curNum][i];
		if(!visited[s]){
			visited[s]=1;
			dfs(s,cnt+1);
			
		}
	}
	visited[curNum]=0;
}
void solve(){
	visited[0]=1;
	for(int i=0;i<N;++i){
		dfs(i,0);
		if(flag==1){
			cout<<1;
			return;
		}
	}
	cout<<0;
	
	// for(int i=0;i<N;++i){
	// 	if(!visited[i]){
	// 		visited[i]=1;
	// 		dfs(i);
	// 	}
	// }
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}
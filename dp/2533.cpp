#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
const int MAX=1000000+1;
vector<int> graph[MAX];
bool visited[MAX];
int dp[MAX][2];
void Input(){
	cin>>N;
	for(int i=0;i<N-1;++i){
		int a,b=0;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i=1;i<=N;++i){
		dp[i][0]=0;
		dp[i][1]=0;
	}
}
void dfs(int curNum){
	dp[curNum][0]=1;
	visited[curNum]=1;
	for(int i=0;i<graph[curNum].size();++i){
		int nextNum=graph[curNum][i];
		if(!visited[nextNum]){
			visited[nextNum]=1;
			dfs(nextNum);
			dp[curNum][1]+=dp[nextNum][0];
			dp[curNum][0]+=min(dp[nextNum][0],dp[nextNum][1]);
		}
	}
}
void solve(){
	visited[1]=1;
	dfs(1);
}
int main() {
	// your code goes here
	Input();
	solve();
	cout<<min(dp[1][0],dp[1][1]);
	return 0;
}
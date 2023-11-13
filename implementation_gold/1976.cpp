#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int N;
int M;
const int MAX=200+1;
int board[MAX][MAX];
bool visited[MAX];
vector<int> plan;

void Input(){
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			cin>>board[i][j];
		}
	}
	for(int i=0;i<M;++i){
		int a=0;
		cin>>a;
		plan.push_back(a);
	}
}
bool tmp_flag=0;
void dfs(int cur_pos, int fin_pos){
	if(cur_pos==fin_pos){
		tmp_flag=1;
		return;
	}
	for(int i=1;i<=N;++i){
		if(i==cur_pos) continue;
		if(visited[i]) continue;
		if(board[cur_pos][i]==0) continue;
		visited[i]=1;
		dfs(i,fin_pos);
	}
}

void solve(){
	bool flag=1;	
	for(int i=0;i<plan.size()-1;++i){
		int cur_pos=plan[i];
		int next_pos=plan[i+1];
		tmp_flag=0;
		for(int j=1;j<=N;++j){
			visited[j]=0;
		}
		visited[cur_pos]=1;
		dfs(cur_pos,next_pos);
		if(!tmp_flag){
			flag=0;
			break;
		}
	}
	if(flag){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	
	return 0;
}
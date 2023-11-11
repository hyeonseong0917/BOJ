#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

char board[5+1][5+1];
int ans=0;
map<string,int> m;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
void Input(){
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			cin>>board[i][j];
		}
	}
}
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<5 && x<5);
}

void dfs(int y, int x, string s){
	if(s.size()==6){
		if(!m[s]){
			++m[s];
			++ans;
		}
		return;
	}
	for(int i=0;i<4;++i){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(!isRange(ny,nx)) continue;
		dfs(ny,nx,s+board[ny][nx]);
	} 

}


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			dfs(i,j,""+board[i][j]);		
		}
	}
	
	cout<<ans;
	return 0;
}
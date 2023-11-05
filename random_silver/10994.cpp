#include <iostream>
using namespace std;

int N;
char board[400+1][400+1];

void dfs(int y, int x, int cnt){
	if(cnt==1){
		board[y][x]='*';
		return;
	}
	for(int i=y;i<y+cnt;++i){
		board[i][x]='*';
	}
	for(int i=x;i<x+cnt;++i){
		board[y][i]='*';
	}
	for(int i=y;i<y+cnt;++i){
		board[i][x+cnt-1]='*';
	}
	for(int i=x;i<x+cnt;++i){
		board[y+cnt-1][i]='*';
	}
	dfs(y+2,x+2,cnt-4);
}

int main() {
	// your code goes here
	cin>>N;
	for(int i=0;i<400+1;++i){
		for(int j=0;j<400+1;++j){
			board[i][j]=' ';
		}
	}
	dfs(0,0,1+4*(N-1));
	for(int i=0;i<1+4*(N-1);++i){
		for(int j=0;j<1+4*(N-1);++j){
			cout<<board[i][j];
		}cout<<"\n";
	}
	return 0;
}
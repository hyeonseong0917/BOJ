#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int board[3+1][3+1];
int N;

void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
		}
	}
}
string solve(){
	queue<pair<int,int>> q;
	q.push({0,0});
	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		int s=board[y][x];
		if(s==-1){
			return "HaruHaru";
		}
		if(s==0){
			continue;
		}
		if(x+s<N){
			q.push({y,x+s});
		}
		if(y+s<N){
			q.push({y+s,x});
		}
	}
	return "Hing";
}

int main() {
	// your code goes here
	Input();
	cout<<solve();
	return 0;
}
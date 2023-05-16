#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//1548
const int MAX=200+1;
int N,K,S,targetY,targetX;
int board[MAX][MAX];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
vector<pair<int,pair<int,int>>> virus;
bool comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
	return a.first<b.first;
}
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
void Input(){
	cin>>N>>K;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
			if(board[i][j]!=0){
				virus.push_back({board[i][j],{i,j}});
			}
		}
	}
	sort(virus.begin(), virus.end(), comp);
	cin>>S>>targetY>>targetX;
}
void BFS(){
	queue<pair<int,pair<int,int>>> q;
	// bool visited[MAX][MAX];
	for(int i=0;i<virus.size();++i){
		q.push(virus[i]);
		// visited[virus[i].second.first][virus[i].second.second]=1;
	}
	while(S--){
		queue<pair<int,pair<int,int>>> pq;
		while(!q.empty()){
			int num=q.front().first;
			int y=q.front().second.first;
			int x=q.front().second.second;
			q.pop();
			for(int i=0;i<4;++i){
				int ny=y+dy[i];
				int nx=x+dx[i];
				if(isRange(ny,nx) && board[ny][nx]==0){
					board[ny][nx]=num;
					pq.push({num,{ny,nx}});
				}
			}
		}
		while(!pq.empty()){
			q.push(pq.front());
			pq.pop();
		}
	}
	// for(int i=0;i<N;++i){
	// 	for(int j=0;j<N;++j){
	// 		cout<<board[i][j]<<" ";
	// 	}cout<<endl;
	// }
	cout<<board[targetY-1][targetX-1];
}
int main() {
	// your code goes here
	Input();
	BFS();
	return 0;
}
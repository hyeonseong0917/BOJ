#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
const int MAX=50+1;
char board[MAX][MAX];
bool visited[MAX][MAX];
int cnt_save[MAX][MAX];
int wall_num=0;
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
			cnt_save[i][j]=0;
			if(board[i][j]=='0'){
				++wall_num;
			}
		}
	}
	
}
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
int BFS(){
	queue<pair<int,pair<int,int>>> q;
	q.push({0,{0,0}});
	visited[0][0]=1;
	cnt_save[0][0]=0;
	while(!q.empty()){
		int cnt=q.front().first;
		int y=q.front().second.first;
		int x=q.front().second.second;
		q.pop();
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(isRange(ny,nx)){
				int cur_cnt=cnt;
				if(board[ny][nx]=='0'){
					++cur_cnt;
				}
				if(!visited[ny][nx]){
					// cout<<cur_cnt<<endl;
					q.push({cur_cnt,{ny,nx}});
					visited[ny][nx]=1;
					cnt_save[ny][nx]=cur_cnt;
				}else{
					// cout<<cnt_save[ny][nx]<<endl;
					if(cnt_save[ny][nx]>cur_cnt){
						cnt_save[ny][nx]=cur_cnt;
						q.push({cur_cnt,{ny,nx}});
					}
				}
			}
		}
		
	}
	return cnt_save[N-1][N-1];
}
int main() {
	// your code goes here
	Input();
	cout<<BFS();
	return 0;
}
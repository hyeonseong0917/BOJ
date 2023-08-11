#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

vector<vector<vector<int>>> v;
map<vector<vector<vector<int>>>,int> m;
int cnt=122232421;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int z,int y,int x){
	return (z>=0 && y>=0 && x>=0 && z<5 && y<5 && x<5);
}
void Input(){
	vector<vector<int>> double_tmp;
	vector<int> tmp;
	for(int i=1;i<=25;++i){
		tmp.clear();
		for(int j=0;j<5;++j){
			int a=0;
			cin>>a;
			tmp.push_back(a);
		}
		double_tmp.push_back(tmp);
		if(i%5==0){
			v.push_back(double_tmp);
			double_tmp.clear();
		}
	}
}

vector<vector<int>> clock_turn(vector<vector<int>> cur_board){
	vector<vector<int>> next_board;
	for(int i=0;i<5;++i){
		vector<int> tmp;
		for(int j=0;j<5;++j){
			tmp.push_back(cur_board[4-j][i]);
		}
		next_board.push_back(tmp);
	}
	return next_board;
}

int bfs(vector<vector<vector<int>>> cur_board){
	if(cur_board[0][0][0]!=1){
		return -1;
	}
	bool visited[5][5][5];
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			for(int k=0;k<5;++k){
				visited[i][j][k]=0;
			}
		}
	}
	queue<pair<pair<int,int>,pair<int,int>>> q; //{z,y},{x,cnt};
	q.push({{0,0},{0,0}});
	visited[0][0][0]=1;
	
	while(!q.empty()){
		int z=q.front().first.first;
		int y=q.front().first.second;
		int x=q.front().second.first;
		int c=q.front().second.second;
		// cout<<z<<" "<<y<<" "<<x<<" "<<c<<endl;
		
		q.pop();
		if(z==4 && y==4 && x==4){
			return c;
		}
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			// if(z==1 && ny==1 && nx==2){
			// 	cout<<isRange(z,ny,nx)<<" "<<"he"<<" "<<visited[z][ny][nx]<<endl;
			// }
			if(!isRange(z,ny,nx)) continue;
			if(!visited[z][ny][nx] && cur_board[z][ny][nx]==1){
				visited[z][ny][nx]=1;
				q.push({{z,ny},{nx,c+1}});
			}
		}
		if(isRange(z-1,y,x) && !visited[z-1][y][x] && cur_board[z-1][y][x]==1){
			visited[z-1][y][x]=1;
			q.push({{z-1,y},{x,c+1}});
		}
		if(isRange(z+1,y,x) && !visited[z+1][y][x] && cur_board[z+1][y][x]==1){
			visited[z+1][y][x]=1;
			q.push({{z+1,y},{x,c+1}});
		}
	}
	return -1;
}
vector<vector<vector<vector<int>>>> ans;
bool check[5+1]={0,};

int h=0;
bool flag=0;
void dfs(vector<vector<vector<int>>> cur_board, int h){
	if(h==5){
		int cur_cnt=bfs(cur_board);
		
		if(cur_cnt!=-1){
			
			cnt=min(cnt,cur_cnt);
			return;
		}	
	}
	for(int i=0;i<5;++i){
		if(!check[i]){
			check[i]=1;
			cur_board[h]=v[i];
			for(int j=0;j<4;++j){
				cur_board[h]=clock_turn(cur_board[h]);
				dfs(cur_board,h+1);
			}
			check[i]=0;
		}
	}
	
	
	
	
}

int main() {
	// your code goes here
	Input();
	vector<vector<vector<int>>> a;
	a=v;
	dfs(a,0);
	if(cnt==122232421){
		cout<<-1;
	}else{
		cout<<cnt;	
	}
	
	// cout<<bfs(v);
	return 0;
}
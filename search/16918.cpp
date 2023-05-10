#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//1330
int R,C,N;
const int MAX=200+1;
char board[MAX][MAX];
char initBoard[MAX][MAX];
vector<pair<int,int>> pos;
void Input(){
	cin>>R>>C>>N;
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			cin>>board[i][j];
			initBoard[i][j]=board[i][j];
			// if(board[i][j]=='O'){
			// 	pos.push_back({i,j});
			// }
		}
	}
}

void Install(){
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			if(board[i][j]=='O'){
				pos.push_back({i,j});
			}
		}
	}
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			if(board[i][j]=='.'){
				board[i][j]='O';
			}
		}
	}
}
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<R && x<C);
}
void Bomb(){
	// cout<<pos.size();
	for(int i=0;i<pos.size();++i){
		int y=pos[i].first;
		int x=pos[i].second;
		board[y][x]='.';
		for(int j=0;j<4;++j){
			int ny=y+dy[j];
			int nx=x+dx[j];
			if(isRange(ny,nx)){
				board[ny][nx]='.';
			}
		}
	}
	
	pos.clear();
}
int cnt=1;
void solve(){
	if(N%2==0){
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				cout<<"O";
			}cout<<"\n";
		}
		return;
	}else if(N%4==1){
		vector<pair<int, int>> bombs;
		for (int x = 0; x < R; x++)
		{
			for (int y = 0; y < C; y++)
			{
				if (board[x][y] == 'O') {
					bombs.push_back(make_pair(x, y));
				}
			}
		}

		while (!bombs.empty())
		{
			int cur_x = bombs.back().first;
			int cur_y = bombs.back().second;
			bombs.pop_back();

			for (int j = 0; j < 4; j++)
			{
				int next_x = cur_x + dx[j];
				int next_y = cur_y + dy[j];

				if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C && board[next_x][next_y] == '.') {
					board[next_x][next_y] = 'O';
				}
			}
		}

		for (int x = 0; x < R; x++)
		{
			for (int y = 0; y < C; y++)
			{
				if (board[x][y] == '.') {
					bombs.push_back(make_pair(x, y));
				}
			}
		}

		while (!bombs.empty())
		{
			int cur_x = bombs.back().first;
			int cur_y = bombs.back().second;
			bombs.pop_back();

			for (int j = 0; j < 4; j++)
			{
				int next_x = cur_x + dx[j];
				int next_y = cur_y + dy[j];

				if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C && board[next_x][next_y] == 'O') {
					board[next_x][next_y] = '.';
				}
			}
		}
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				cout<<initBoard[i][j];
			}cout<<"\n";
		}
		return;
	}else if(N%4==3){
		Install();
		Bomb();
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				cout<<board[i][j];
			}cout<<"\n";
		}	
	}
	
	// for(int i=0;i<R;++i){
	// 	for(int j=0;j<C;++j){
	// 		cout<<board[i][j];
	// 	}cout<<"\n";
	// }
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);
	Input();
	solve();
	return 0;
}
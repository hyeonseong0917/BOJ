#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long
const int MAX=10+1;
string board[MAX];
bool check[MAX][MAX];
// 모든 좌표 확인 -> X면 3면 4면이 바다에 둘러쌓여 있는지? -> 둘러쌓여 있다면 check 해제
// check되어있는 곳 좌표 pair에 모으고 sort -> 좌표[0]~좌표[-1]돌면서 보드 출력

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int R,C;
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<R && x<C);
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		
		cin>>R>>C;
		for(int i=0;i<R;++i){
			cin>>board[i];
			for(int j=0;j<C;++j){
				if(board[i][j]=='X'){
					check[i][j]=1;
				}
			}
		}
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				if(!check[i][j]) continue;
				int cnt=0;
				for(int k=0;k<4;++k){
					int ny=i+dy[k];
					int nx=j+dx[k];
					if(!isRange(ny,nx) || board[ny][nx]=='.'){
						++cnt;
					}
				}
				if(cnt>=3){
					check[i][j]=0;
				}
			}
		}
		int min_y=200;
		int min_x=200;
		int max_y=-200;
		int max_x=-200;
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				if(check[i][j]){
					min_y=min(min_y,i);
					min_x=min(min_x,j);
					max_y=max(max_y,i);
					max_x=max(max_x,j);
				}
			}
		}
		
		for(int i=min_y;i<=max_y;++i){
			for(int j=min_x;j<=max_x;++j){
				if(check[i][j]){
					cout<<board[i][j];	
				}else{
					cout<<".";
				}
			}
			cout<<"\n";	
			
		}
	}
	

	

	return 0;
}
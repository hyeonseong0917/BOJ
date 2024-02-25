#include <iostream>
using namespace std;

int dy[8]={-1,-1,-1,0,0,1,1,1};
int dx[8]={-1,0,1,-1,1,-1,0,1};
int R,C;
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<R && x<C);
}
const int MAX=100+1;
char board[MAX][MAX];
int main() {
	// your code goes here
	while(1){
		cin>>R>>C;
		if(R==0 && C==0){
			break;
		}
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				cin>>board[i][j];
			}
		}
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				if(board[i][j]!='.') continue;
				int cnt=0;
				for(int k=0;k<8;++k){
					int ny=i+dy[k];
					int nx=j+dx[k];
					if(!isRange(ny,nx)) continue;
					if(board[ny][nx]=='*'){
						++cnt;
					}
				}
				board[i][j]=(cnt+'0');
			}
		}
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				cout<<board[i][j];
			}cout<<"\n";
		}
	}
	return 0;
}
#include <iostream>
using namespace std;

const int MAX=100+1;
char board[MAX][MAX];
int ans[MAX][MAX];
int main() {
	// your code goes here
	int H,W;
	cin>>H>>W;
	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j){
			cin>>board[i][j];
			ans[i][j]=-1;
			if(board[i][j]=='c'){
				ans[i][j]=0;
			}
		}
	}
	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j){
			if(board[i][j]=='c'){
				int ny=i;
				int nx=j+1;
				int cnt=1;
				while(nx<W && board[ny][nx]=='.'){
					ans[ny][nx]=cnt++;
					++nx;
				}
			}
		}
	}
	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j){
			cout<<ans[i][j]<<" ";
		}cout<<"\n";
	}
	
	return 0;
}
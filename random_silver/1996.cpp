#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int N;
const int MAX=1000+1;
char board[MAX][MAX];
char ans[MAX][MAX];
int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,1,1,1,0,-1,-1,-1};
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
		}
	}
}
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
void solve(){
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			int cnt=0;
			if(board[i][j]!='.'){
				ans[i][j]='*';
				continue;
			}
			for(int k=0;k<8;++k){
				int ny=i+dy[k];
				int nx=j+dx[k];
				if(!isRange(ny,nx)) continue;
				if(board[ny][nx]!='.'){
					cnt+=(board[ny][nx]-'0');
				}
			}
			if(cnt>=10){
				ans[i][j]='M';
			}else{
				char c=cnt+'0';
				ans[i][j]=c;	
			}
			
		}
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cout<<ans[i][j];
		}cout<<endl;
	}
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	return 0;
}
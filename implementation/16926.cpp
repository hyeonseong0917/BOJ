#include <iostream>
using namespace std;
int N,M,R;
const int MAX=300+1;
int board[MAX][MAX];
void Input(){
	cin>>N>>M>>R;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
		}
	}
}
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
int ny,nx;
int preNum,nextNum;
int N_step,M_step;
void dfs(int dir){
	int cur_step=0;
	if(dir%2==0){
		cur_step=N_step;
	}else{
		cur_step=M_step;
	}
	while(cur_step--){
		
		ny+=dy[dir];
		nx+=dx[dir];
		
		// cout<<ny<<" "<<nx<<endl;
		nextNum=board[ny][nx];
		board[ny][nx]=preNum;
		preNum=nextNum;
		
	}
	
	
}
void turn(){
	int y=0,x=0;
	N_step=N-1;
	M_step=M-1;
	while(1){
		if(N_step<=0 || M_step<=0){
			break;
		}
		ny=y;
		nx=x;
		preNum=board[ny][nx];
		dfs(0);
		dfs(1);
		dfs(2);
		dfs(3);
		++y;
		++x;
		
		N_step-=2;
		M_step-=2;
	}
}
void solve(){
	for(int i=0;i<R;++i){
		turn();
		
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cout<<board[i][j]<<" ";
		}cout<<endl;
	}
}
int main() {
	// your code goes here
	Input();
	// turn();
	solve();
	return 0;
}
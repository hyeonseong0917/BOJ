#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,x,y,k;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int board[20+1][20+1]={0,};
int L[1]={0},R[1]={0},F[1]={0},B[1]={0},U[1]={0},D[1]={0};

bool isRange(int x, int y){
	return (y>=0 && x>=0 && x<N && y<M);
}
int curX=0, curY=0;
void solve(int x, int y, int dir){
	if(!isRange(x+dx[dir],y+dy[dir])){
		return;
	}
	curX=x+dx[dir];
	curY=y+dy[dir];
	// cout<<curX<<" "<<curY<<endl;
	int curNum=board[curX][curY];
	// cout<<curNum<<endl;
	int TL[1]={L[0]},TR[1]={R[0]},TF[1]={F[0]},TB[1]={B[0]},TU[1]={U[0]},TD[1]={D[0]};
	// cout<<"curX:"<<curX<<" "<<"curY: "<<curY<<endl;
	// cout<<board[curX][curY]<<"\n";
	// cout<<board[1][3]<<"\n";
	if(dir==0){
		U[0]=TL[0];
		D[0]=TR[0];
		if(curNum==0){
			board[curX][curY]=D[0];
		}else{
			// cout<<"hello";
			D[0]=curNum;
			board[curX][curY]=0;
		}
		// cout<<D[0]<<"\n";
		R[0]=TU[0];
		L[0]=TD[0];
	}else if(dir==1){
		D[0]=TL[0];
		if(curNum==0){
			board[curX][curY]=D[0];
		}else{
			D[0]=curNum;
			board[curX][curY]=0;
		}
		U[0]=TR[0];
		L[0]=TU[0];
		R[0]=TD[0];
	}else if(dir==2){
		U[0]=TF[0];
		D[0]=TB[0];
		if(curNum==0){
			board[curX][curY]=D[0];
		}else{
			D[0]=curNum;
			board[curX][curY]=0;	
		}
		B[0]=TU[0];
		F[0]=TD[0];
	}else if(dir==3){
		D[0]=TF[0];
		if(curNum==0){
			board[curX][curY]=D[0];
		}else{
			D[0]=curNum;
			board[curX][curY]=0;
		}
		U[0]=TB[0];
		F[0]=TU[0];
		B[0]=TD[0];
	}
	cout<<U[0]<<"\n";
	// cout<<endl;
}

int main() {
	// your code goes here
	cin>>N>>M>>x>>y>>k;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
		}
	}
	curX=x;
	curY=y;
	for(int i=0;i<k;++i){
		int dir=0;
		cin>>dir;
		solve(curX,curY,dir-1);
	}
	return 0;
}
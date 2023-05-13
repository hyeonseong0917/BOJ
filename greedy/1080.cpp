#include <iostream>
using namespace std;
int N,M=0;
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
int main() {
	// your code goes here
	
	cin>>N>>M;
	char first_board[50+1][50+1], second_board[50+1][50+1];
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>first_board[i][j];
		}
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>second_board[i][j];
		}
	}
	
	int cnt=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(first_board[i][j]!=second_board[i][j] && isRange(i+2,j+2)){
				++cnt;
				for(int k=0;k<3;++k){
					for(int p=0;p<3;++p){
						int ny=i+k;
						int nx=j+p;
						if(isRange(ny,nx)){
							if(first_board[ny][nx]=='1'){
								first_board[ny][nx]='0';
							}else{
								first_board[ny][nx]='1';
							}
						}
					}
				}
			}
		}
	}
	bool flag=1;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(first_board[i][j]!=second_board[i][j]){
				flag=0;
				break;
			}
		}
	}
	if(flag){
		cout<<cnt;	
	}else{
		cout<<-1;
	}
	
	return 0;
}
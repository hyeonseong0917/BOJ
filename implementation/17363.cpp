#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int N,M=0;
	cin>>N>>M;
	char board[100+1][100+1];
	char new_board[100+1][100+1];
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
		}
	}
	for(int i=0;i<M;++i){
		for(int j=0;j<N;++j){
			new_board[M-i-1][j]=board[j][i];
		}
	}
	for(int i=0;i<M;++i){
		for(int j=0;j<N;++j){
			char c=new_board[i][j];
			if(c=='-'){
				new_board[i][j]='|';
			}else if(c=='|'){
				new_board[i][j]='-';
			}else if(c=='/'){
				new_board[i][j]='\\';
			}else if(c=='\\'){
				new_board[i][j]='/';
			}else if(c=='^'){
				new_board[i][j]='<';
			}else if(c=='<'){
				new_board[i][j]='v';
			}else if(c=='v'){
				new_board[i][j]='>';
			}else if(c=='>'){
				new_board[i][j]='^';
			}
		}
	}
	for(int i=0;i<M;++i){
		for(int j=0;j<N;++j){
			cout<<new_board[i][j];
		}cout<<"\n";
	}
	return 0;
}
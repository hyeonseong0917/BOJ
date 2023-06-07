#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,R=0;
const int MAX=100+1;
int board[MAX][MAX];
vector<int> v;
void Input(){
	cin>>N>>M>>R;
	
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
		}
	}
	for(int i=0;i<R;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}
}
void turn(int num){
	int new_board[MAX][MAX];
	for(int i=0;i<MAX;++i){
		if(board[i][0]==0){
			N=i;
			break;
		}
	}
	for(int i=0;i<MAX;++i){
		if(board[0][i]==0){
			M=i;
			break;
		}
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			new_board[i][j]=board[i][j];
		}
	}
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			board[i][j]=0;
		}
	}
	if(num==1){
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				board[i][j]=new_board[N-1-i][j];
			}
		}
	}else if(num==2){
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				board[i][j]=new_board[i][M-1-j];
			}
		}
	}else if(num==3){
		for(int i=0;i<M;++i){
			for(int j=0;j<N;++j){
				board[i][j]=new_board[N-j-1][i];
			}
		}
	}else if(num==4){
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				board[i][j]=0;
			}
		}
		for(int i=0;i<M;++i){
			for(int j=0;j<N;++j){
				board[i][j]=new_board[j][M-i-1];
			}
		}
	}else if(num==5 || num==6){
		int first_board[MAX/2 +1][MAX/2 +1];
		int second_board[MAX/2 +1][MAX/2 +1];
		int third_board[MAX/2 +1][MAX/2 +1];
		int fourth_board[MAX/2 +1][MAX/2 +1];
		for(int i=0;i<N/2;++i){
			for(int j=0;j<M/2;++j){
				first_board[i][j]=new_board[i][j];
			}
		}
		for(int i=0;i<N/2;++i){
			for(int j=0;j<M/2;++j){
				second_board[i][j]=new_board[i][j+M/2];
			}
		}
		for(int i=0;i<N/2;++i){
			for(int j=0;j<M/2;++j){
				third_board[i][j]=new_board[i+N/2][j+M/2];
			}
		}
		for(int i=0;i<N/2;++i){
			for(int j=0;j<M/2;++j){
				fourth_board[i][j]=new_board[i+N/2][j];
			}
		}
		if(num==5){
			for(int i=0;i<N/2;++i){
				for(int j=0;j<M/2;++j){
					board[i][j]=fourth_board[i][j];
					board[i][j+M/2]=first_board[i][j];
					board[i+N/2][j+M/2]=second_board[i][j];
					board[i+N/2][j]=third_board[i][j];
				}
			}
		}else{
			for(int i=0;i<N/2;++i){
				for(int j=0;j<M/2;++j){
					board[i][j]=second_board[i][j];
					board[i][j+M/2]=third_board[i][j];
					board[i+N/2][j+M/2]=fourth_board[i][j];
					board[i+N/2][j]=first_board[i][j];
				}
			}
		}
	}
}
void solve(){
	for(int i=0;i<v.size();++i){
		turn(v[i]);
	}
	for(int i=0;i<MAX;++i){
		if(board[i][0]==0){
			N=i;
			break;
		}
	}
	for(int i=0;i<MAX;++i){
		if(board[0][i]==0){
			M=i;
			break;
		}
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
	solve();
	
	return 0;
}
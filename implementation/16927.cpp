#include <iostream>
#include <vector>
using namespace std;

const int MAX=300+1;
int board[MAX][MAX];
int tmp_board[MAX][MAX];
int N,M,R;
void Input(){
	cin>>N>>M>>R;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
			tmp_board[i][j]=board[i][j];
		}
	}
}

void turn(){
	
}
void solve(){
	int first_N=N;
	int first_M=M;
	int y=0,x=0;
	while(1){
		if(first_N<2 || first_M<2){
			break;
		}
		int MOD=(first_N*first_M)-((first_N-2)*(first_M-2));
		
		int turn_num=R%(MOD);
		
		for(int i=0;i<turn_num;++i){
			
			int tmp_y=y;
			int tmp_x=x;
			//----
			for(int j=tmp_x+1;j<tmp_x+first_M;++j){
				board[tmp_y+first_N-1][j]=tmp_board[tmp_y+first_N-1][j-1];
			}
			
			//|||||
			for(int j=tmp_y+1;j<tmp_y+first_N;++j){
				// board[j][tmp_x+first_M-1]=tmp_board[j-1][tmp_x+first_M-1];
				board[j][tmp_x]=tmp_board[j-1][tmp_x];
			}
			
			//----역순
			for(int j=tmp_x+first_M-1;j>tmp_x;--j){
				board[tmp_y][j-1]=tmp_board[tmp_y][j];
			}
			
			//|||| 역순
			for(int j=tmp_y+first_N-1;j>tmp_y;--j){
				board[j-1][tmp_x+first_M-1]=tmp_board[j][tmp_x+first_M-1];
			}
			// for(int j=0;j<N;++j){
			// 	for(int k=0;k<M;++k){
			// 		cout<<board[j][k]<<" ";
			// 	}cout<<endl;
			// }
			for(int j=tmp_x;j<tmp_x+first_M;++j){
				tmp_board[tmp_y][j]=board[tmp_y][j];
			}
			for(int j=tmp_y;j<tmp_y+first_N;++j){
				tmp_board[j][tmp_x+first_M-1]=board[j][tmp_x+first_M-1];
			}
			for(int j=tmp_x+first_M-1;j>=tmp_x;--j){
				tmp_board[tmp_y+first_N-1][j]=board[tmp_y+first_N-1][j];
			}
			for(int j=tmp_y+first_N-1;j>=tmp_y;--j){
				tmp_board[j][tmp_x]=board[j][tmp_x];
			}
			
			// for(int j=0;j<N;++j){
			// 	for(int k=0;k<M;++k){
			// 		cout<<board[j][k]<<" ";
			// 	}cout<<endl;
			// }cout<<endl;
			// for(int j=0;j<N;++j){
			// 	for(int k=0;k<M;++k){
			// 		cout<<tmp_board[j][k]<<" ";
			// 	}cout<<endl;
			// }cout<<endl;
			// return;
			
		}
		first_N-=2;
		first_M-=2;
		y+=1;
		x+=1;
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
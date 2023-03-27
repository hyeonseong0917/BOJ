#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N=0;
const int MAX=20+1;
int board[MAX][MAX]={0,};
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
			
		}
	}
}
void turn(int dir){ //dir 방향으로 turn
	int check[20+1][20+1]={0};
	for(int i=0;i<20+1;++i){
		for(int j=0;j<20+1;++j){
			check[i][j]=0;
		}
	}
	int ny=0,nx=0;
	if(dir==0){
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				int curNum=board[j][i];
				ny=j,nx=i;
				if(curNum!=0){
					while(1){
						// if(i==2) cout<<j<<" "<<i<<" "<<ny<<" "<<nx;
						ny+=dy[dir];
						nx+=dx[dir];
						// if(i==2) cout<<" "<<ny<<" "<<nx<<endl;
						if(!isRange(ny,nx)){
							
							break;
						}
						
						if(board[ny][nx]==0){
							board[ny][nx]=curNum;
							board[ny-dy[dir]][nx-dx[dir]]=0;
						}else if(board[ny][nx]==curNum){
							if(check[ny][nx]==0){
								check[ny][nx]=1;
								board[ny][nx]=curNum*2;
								board[ny-dy[dir]][nx-dx[dir]]=0;
							}else{
								break;
							}
						}else{
							break;
						}
					}
					
				}
			}
		}
	}else if(dir==1){
		for(int i=0;i<N;++i){
			for(int j=N-1;j>=0;--j){
				int curNum=board[j][i];
				ny=j,nx=i;
				if(curNum!=0){
					while(1){
						// if(i==2) cout<<j<<" "<<i<<" "<<ny<<" "<<nx;
						ny+=dy[dir];
						nx+=dx[dir];
						// if(i==2) cout<<" "<<ny<<" "<<nx<<endl;
						if(!isRange(ny,nx)){
							
							break;
						}
						
						if(board[ny][nx]==0){
							board[ny][nx]=curNum;
							board[ny-dy[dir]][nx-dx[dir]]=0;
						}else if(board[ny][nx]==curNum){
							if(check[ny][nx]==0){
								check[ny][nx]=1;
								board[ny][nx]=curNum*2;
								board[ny-dy[dir]][nx-dx[dir]]=0;
							}else{
								break;
							}
						}else{
							break;
						}
					}
				}
			}
		}
	}else if(dir==2){
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				int curNum=board[i][j];
				ny=i,nx=j;
				if(curNum!=0){
					while(1){
						// if(i==0) cout<<i<<" "<<j<<" "<<ny<<" "<<nx;
						ny+=dy[dir];
						nx+=dx[dir];
						// if(i==0) cout<<" "<<ny<<" "<<nx<<endl;
						if(!isRange(ny,nx)){
							
							break;
						}
						
						if(board[ny][nx]==0){
							board[ny][nx]=curNum;
							board[ny-dy[dir]][nx-dx[dir]]=0;
						}else if(board[ny][nx]==curNum){
							if(check[ny][nx]==0){
								check[ny][nx]=1;
								board[ny][nx]=curNum*2;
								board[ny-dy[dir]][nx-dx[dir]]=0;
							}else{
								break;
							}
						}else{
							break;
						}
					}
				}
			}
		}
	}else if(dir==3){
		for(int i=0;i<N;++i){
			for(int j=N-1;j>=0;--j){
				int curNum=board[i][j];
				ny=i,nx=j;
				if(curNum!=0){
					while(1){
						// if(i==2) cout<<j<<" "<<i<<" "<<ny<<" "<<nx;
						ny+=dy[dir];
						nx+=dx[dir];
						// if(i==2) cout<<" "<<ny<<" "<<nx<<endl;
						if(!isRange(ny,nx)){
							
							break;
						}
						
						if(board[ny][nx]==0){
							board[ny][nx]=curNum;
							board[ny-dy[dir]][nx-dx[dir]]=0;
						}else if(board[ny][nx]==curNum){
							if(check[ny][nx]==0){
								check[ny][nx]=1;
								board[ny][nx]=curNum*2;
								board[ny-dy[dir]][nx-dx[dir]]=0;
							}else{
								break;
							}
						}else{
							break;
						}
					}
				}
			}
		}
	}
}
//dfs(0,5)
int minNum=-12232421;
vector<int> v;
void dfs(int cnt){
	if(cnt==0){ //31303
		// if(v[0]==3 && v[1]==1 && v[2]==3 && v[3]==0 && v[4]==3){
		// 	for(int i=0;i<N;++i){
		// 		for(int j=0;j<N;++j){
		// 			cout<<board[i][j]<<" ";
		// 		}cout<<endl;
		// 	}
		// }	
		// cout<<minNum<<endl;
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				minNum=max(minNum,board[i][j]);
			}
		}
		return;
	}
	int tmpBoard[MAX][MAX];
	for(int j=0;j<N;++j){
		for(int k=0;k<N;++k){
			tmpBoard[j][k]=board[j][k];
		}
	}
	for(int i=0;i<4;++i){
		
		turn(i);
		v.push_back(i);//31303
		// if(cnt==5 && v[0]==3){
		// 		for(int m=0;m<N;++m){
		// 		for(int u=0;u<N;++u){
		// 			cout<<board[m][u]<<" ";
		// 		}cout<<endl;
		// 	}
		// }
		// if(cnt==4){cout<<i<<endl;
		// 	for(int m=0;m<N;++m){
		// 		for(int u=0;u<N;++u){
		// 			cout<<board[m][u]<<" ";
		// 		}cout<<endl;
		// 	}
		// }
		dfs(cnt-1);
		for(int j=0;j<N;++j){
			for(int k=0;k<N;++k){
				board[j][k]=tmpBoard[j][k];
			}
		}
		v.pop_back();
		
	}
}


int main() {
	// your code goes here
	Input();
	// for(int i=0;i<N;++i){
	// 	for(int j=0;j<N;++j){
	// 		cout<<board[i][j];
	// 	}cout<<endl;
	// }
	// turn(0);
	// turn(2);
	dfs(5);
	cout<<minNum;
	// for(int i=0;i<N;++i){
	// 	for(int j=0;j<N;++j){
	// 		cout<<board[i][j]<<" ";
	// 	}cout<<endl;
	// }
	// dfs(5);
	// cout<<minNum;
	// cout<<minNum;
	// turn(3);
	// turn(1);
	// turn(3);
	// turn(0);
	// turn(3);
	// turn(1);
	// turn(1);
	// turn(1);
	// turn(3);
	// turn(3);
	// for(int i=0;i<N;++i){
	// 	for(int j=0;j<N;++j){
	// 		cout<<board[i][j]<<" ";
	// 	}cout<<endl;
	// }
	return 0;
}
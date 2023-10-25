#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

const int MAX=100+1;
ll dp[MAX][MAX][4+1];
ll board[MAX][MAX][4+1];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main() {
	// your code goes here
	int N,M;
	// 가로 크기 N , 세로 크기 M
	cin>>N>>M;
	int K=0;
	cin>>K;
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			for(int k=0;k<5;++k){
				dp[i][j][k]=0;
				board[i][j][k]=0;	
			}
			
		}
	}
	for(int i=0;i<=M;++i){
		dp[0][i][0]=1;
	}
	for(int i=0;i<=N;++i){
		dp[i][0][1]=1;
	}
	int cnt=1;
	for(int i=0;i<K;++i){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		pair<int,int> first_pos=make_pair(a,b);
		pair<int,int> second_pos=make_pair(c,d);
		// 1.first_pos<second_pos
		if(first_pos>second_pos){
			pair<int,int> tmp;
			tmp=second_pos;
			second_pos=first_pos;
			first_pos=tmp;
		}
		int x=first_pos.first;
		int y=first_pos.second;
		int xx=second_pos.first;
		int yy=second_pos.second;
		// cout<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
		for(int i=0;i<4;++i){
			int nx=x+dx[i];
			int ny=y+dy[i];

			if(ny==yy && nx==xx){
				// cout<<nx<<" "<<ny<<" "<<i<<" "<<(i+2)%4<< endl;	
				board[x][y][i]=1;
				board[nx][ny][(i+2)%4]=1;
			}
		}
	}
	// cout<<board[0][0][0]<<" "<<board[0][1][2]<<endl;
	// cout<<board[5][6][1]<<" "<<board[6][6][3]<<endl;
	dp[0][0][1]=1;
	dp[0][0][0]=1;
	for(int i=0;i<N;++i){
		if(board[i][0][1]==1){
			for(int j=i+1;j<=N;++j){
				dp[j][0][1]=0;
			}
			break;
		}
	}
	for(int i=0;i<M;++i){
		if(board[0][i][0]==1){
			for(int j=i+1;j<=M;++j){
				dp[0][j][0]=0;
			}
			break;
		}
	}
	// for(int i=0;i<N;++i){
	// 	for(int j=0;j<M;++j){
	// 		for(int k=0;k<2;++k){
	// 			if(i==0 || j==0){
	// 				cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<"\n";
	// 			}	
	// 		}
			
	// 	}
	// }
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			//i,j와 i-1,j를 살펴봄
			if(!(board[i][j][3]==1 && board[i-1][j][1]==1)){
				dp[i][j][1]+=(dp[i-1][j][1]+dp[i-1][j][0]);
			}
			//i,j와 i,j-1를 살펴봄
			if(!(board[i][j][2]==1 && board[i][j-1][0]==1)){
				dp[i][j][0]+=(dp[i][j-1][1]+dp[i][j-1][0]);
			}
		}
	}
	// for(int i=0;i<=N;++i){
	// 	for(int j=0;j<=M;++j){
	// 		cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
	// 	}cout<<"\n";
	// }
	cout<<dp[N][M][0]+dp[N][M][1]; 
	// cout<<dp[2][3]<<"\n";
	// cout<<dp[N-1][M-1];
	return 0;
}
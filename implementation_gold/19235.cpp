#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define ll long long

int N;
vector<pair<int,pair<int,int>>> v;
int board[10][10];
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		int t,a,b;
		cin>>t>>a>>b;
		v.push_back({t,{a,b}});
	}
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			board[i][j]=0;
		}
	}
}
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int cnt=0;
bool isRange(int x, int y){
	return (x>=0 && y>=0 && x<10 && y<10);
}
int g_num=1;
int b_num=1;
int green_gravity(){
	for(int i=8;i>=4;--i){
		for(int j=0;j<4;++j){
			if(board[i][j]!=0 && board[i+1][j]==0){
				int t=-1;
				// 1번 타입인지
				bool is_same=0;
				for(int k=0;k<4;++k){
					int nx=i+dx[k];
					int ny=j+dy[k];
					if(isRange(nx,ny)){
						if(board[i][j]==board[nx][ny]){
							is_same=1;
						}
					}
				}
				if(!is_same){
					t=1;
				}
				// 2번 타입인지
				if(j!=3){
					if(board[i][j]==board[i][j+1]){
						t=2;
					}
				}
				// 3번 타입인지
				if(board[i-1][j]==board[i][j]){
					t=3;
				}
				if(t==1){
					board[i+1][j]=board[i][j];
					board[i][j]=0;
					return 1;
				}else if(t==2){
					if(board[i+1][j]==0 && board[i+1][j+1]==0){
						board[i+1][j]=board[i][j];
						board[i+1][j+1]=board[i][j];
						board[i][j]=0;
						board[i][j+1]=0;
						return 1;
					}
				}else if(t==3){
					board[i+1][j]=board[i][j];
					board[i-1][j]=0;
					return 1;
				}
			}
		}
	}
	return 0;
}
int green_bomb(){
	// green bomb check
	while(1){
		if(!green_gravity()){
			break;
		}
	}
	vector<int> del_num;
	for(int i=9;i>=6;--i){
		bool flag=0;
		for(int j=0;j<4;++j){
			if(board[i][j]==0){
				flag=1;
				break;
			}
		}
		if(!flag){
			del_num.push_back(i);
		}
	}
	if(!del_num.empty()){
		if(del_num.size()==1){
			++cnt;
			for(int j=0;j<4;++j){
				board[del_num[0]][j]=0;
			}
			for(int j=del_num[0]-1;j>=4;--j){
				for(int k=0;k<4;++k){
					board[j+1][k]=board[j][k];
					board[j][k]=0;
				}
			}
			return 1;
		}else{
			cnt+=2;
			for(int j=0;j<4;++j){
				board[del_num[0]][j]=0;
				board[del_num[1]][j]=0;
			}
			for(int j=del_num[1]-1;j>=4;--j){
				for(int k=0;k<4;++k){
					board[j+1][k]=board[j][k];
					board[j][k]=0;
				}
			}
			for(int j=del_num[0]-1;j>=4;--j){
				for(int k=0;k<4;++k){
					board[j+1][k]=board[j][k];
					board[j][k]=0;
				}
			}
			return 1;
		}
	}
	// 4번째 5번째 줄에 블럭 있는지?
	int check=0;
	for(int j=0;j<4;++j){
		if(board[4][j]!=0){
			++check;
			break;
		}
	}
	for(int j=0;j<4;++j){
		if(board[5][j]!=0){
			++check;
			break;
		}
	}
	if(check==1){
		for(int j=0;j<4;++j){
			board[9][j]=0;
		}
		for(int j=9;j>=5;--j){
			for(int k=0;k<4;++k){
				board[j][k]=board[j-1][k];
				board[j-1][k]=0;
			}
		}
		return 1;
	}
	if(check==2){
		for(int j=0;j<4;++j){
			board[9][j]=0;
		}
		for(int j=0;j<4;++j){
			board[8][j]=0;
		}
		for(int j=9;j>=5;--j){
			for(int k=0;k<4;++k){
				board[j][k]=board[j-2][k];
				board[j-2][k]=0;
			}
		}
		return 1;
	}
	return 0;
}
int blue_gravity(){
	for(int i=8;i>=4;--i){
		for(int j=0;j<4;++j){
			if(board[j][i]!=0 && board[j][i+1]==0){
				int t=-1;
				// 1번 타입인지
				bool is_same=0;
				for(int k=0;k<4;++k){
					int nx=j+dx[k];
					int ny=i+dy[k];
					// if(board[j][i]==5){
					// 	cout<<board[nx][ny]<<"fsd"<<isRan<<endl;
					// }
					if(isRange(nx,ny)){

						if(board[j][i]==board[nx][ny]){
							is_same=1;
						}
					}
				}
				if(!is_same){
					t=1;
				}
				// 3번 타입인지
				if(j!=3){
					if(board[j][i]==board[j+1][i]){
						t=3;
					}
				}
				// 2번 타입인지
				if(board[j][i-1]==board[j][i]){
					t=2;
				}
				// cout<<b_num<<" "<<j<<" "<<i<<" "<<t<<endl;
				// if(b_num==5){
				// 	cout<<t<<endl;
				// }
				if(t==1){
					board[j][i+1]=board[j][i];
					board[j][i]=0;
					return 1;
				}else if(t==2){
					board[j][i+1]=board[j][i];
					board[j][i-1]=0;
					return 1;
					
				}else if(t==3){
					if(board[j][i+1]==0 && board[j+1][i+1]==0){
						board[j][i+1]=board[j][i];
						board[j+1][i+1]=board[j+1][i];
						board[j][i]=0;
						board[j+1][i]=0;
						return 1;
					}
				}
			}
		}
	}
	return 0;	
}
int blue_bomb(){
	// blue bomb check
	while(1){
		if(!blue_gravity()){
			break;
		}
	}
	vector<int> del_num;
	for(int i=9;i>=6;--i){
		bool flag=0;
		for(int j=0;j<4;++j){
			if(board[j][i]==0){
				flag=1;
				break;
			}
		}
		if(!flag){
			// i번째 줄 삭제
			del_num.push_back(i);
		}
	}
	if(!del_num.empty()){
		if(del_num.size()==1){
			++cnt;
			for(int j=0;j<4;++j){
				board[j][del_num[0]]=0;
			}
			for(int j=del_num[0]-1;j>=4;--j){
				for(int k=0;k<4;++k){
					board[k][j+1]=board[k][j];
					board[k][j]=0;
				}
			}
			return 1;
		}else{
			cnt+=2;
			for(int j=0;j<4;++j){
				board[j][del_num[0]]=0;
				board[j][del_num[1]]=0;
			}
			for(int j=del_num[1]-1;j>=4;--j){
				for(int k=0;k<4;++k){
					board[k][j+1]=board[k][j];
					board[k][j]=0;
				}
			}
			for(int j=del_num[0]-1;j>=4;--j){
				for(int k=0;k<4;++k){
					board[k][j+1]=board[k][j];
					board[k][j]=0;
				}
			}
			return 1;
		}
	}
	// 4번째 5번째 줄에 블럭 있는지?
	int check=0;
	for(int j=0;j<4;++j){
		if(board[j][4]!=0){
			++check;
			break;
		}
	}
	for(int j=0;j<4;++j){
		if(board[j][5]!=0){
			++check;
			break;
		}
	}
	if(check){
		if(check==1){
			for(int j=0;j<4;++j){
				board[j][9]=0;
			}
			for(int j=9;j>=5;--j){
				for(int k=0;k<4;++k){
					board[k][j]=board[k][j-1];
					board[k][j-1]=0;
				}
			}	
		}else{
			for(int j=0;j<4;++j){
				board[j][9]=0;
				board[j][8]=0;
			}
			for(int j=9;j>=5;--j){
				for(int k=0;k<4;++k){
					board[k][j]=board[k][j-2];
					board[k][j-2]=0;
				}
			}	

		}
		
		return 1;
	}
	return 0;	
}


void green_drop(int t, int x, int y){
	int nx=x;
	int ny=y;
	if(t==1){
		while(1){
			if(!isRange(nx,ny) || board[nx][ny]!=0){
				// cout<<nx<<" "<<ny<<endl;
				board[nx-1][ny]=g_num;
				// cout<<board[9][1]<<endl;
				break;
			}
			++nx;
		}
	}else if(t==2){
		while(1){
			if(!isRange(nx,ny) || board[nx][ny]!=0 || board[nx][ny+1]!=0){
				board[nx-1][ny]=g_num;
				board[nx-1][ny+1]=g_num;
				break;
			}
			++nx;
		}
	}else{
		while(1){
			if(!isRange(nx,ny) || board[nx][ny]!=0){
				board[nx-1][ny]=g_num;
				board[nx-2][ny]=g_num;
				break;
			}
			++nx;
		}
	}
	++g_num;
}
void blue_drop(int t, int x, int y){
	int nx=x;
	int ny=y;
	if(t==1){
		while(1){
			if(!isRange(nx,ny) || board[nx][ny]!=0){
				board[nx][ny-1]=b_num;
				break;
			}
			++ny;
		}
	}else if(t==2){
		while(1){
			if(!isRange(nx,ny) || board[nx][ny]!=0){
				board[nx][ny-1]=b_num;
				board[nx][ny-2]=b_num;
				break;
			}
			++ny;
		}
	}else{
		while(1){
			if(!isRange(nx,ny) || board[nx][ny]!=0 || board[nx+1][ny]!=0){
				board[nx][ny-1]=b_num;
				board[nx+1][ny-1]=b_num;
				break;
			}
			++ny;
		}
	}
	++b_num;
}
void solve(){
	for(int i=0;i<N;++i){
		int t=v[i].first;
		int x=v[i].second.first;
		int y=v[i].second.second;
		// while(1){
		// 	if(!green_bomb()){
		// 		break;
		// 	}
		// }
		// while(1){
		// 	if(!blue_bomb()){
		// 		break;
		// 	}
		// }
		green_drop(t,x,y);
		blue_drop(t,x,y);
		while(1){
			if(!green_bomb()){
				break;
			}
		}
		while(1){
			if(!blue_bomb()){
				break;
			}
		}
		// cout<<i<<" "<<cnt<<endl;
		// for(int j=0;j<10;++j){
		// 	for(int k=0;k<10;++k){
		// 		cout<<board[j][k]<<" ";
		// 	}cout<<"\n";
		// }cout<<"\n";
	}
	
	// for(int j=0;j<10;++j){
	// 		for(int k=0;k<10;++k){
	// 			cout<<board[j][k]<<" ";
	// 		}cout<<"\n";
	// 	}cout<<"\n";
	cout<<cnt<<"\n";
	int g_cnt=0, b_cnt=0;
	for(int i=6;i<=9;++i){
		for(int j=0;j<4;++j){
			if(board[i][j]!=0){
				++g_cnt;
			}
		}
	}
	for(int i=6;i<=9;++i){
		for(int j=0;j<4;++j){
			if(board[j][i]!=0){
				++b_cnt;
			}
		}
	}
	cout<<g_cnt+b_cnt;

}


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	return 0;
}
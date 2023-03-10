#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int MAX=10+1;
int N,M,C;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
char s[4]={'U','R','D','L'};
string board[MAX];
pair<int,int> red,blue,fin;
map<string,int> m;
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>board[i];
		for(int j=0;j<M;++j){
			if(board[i][j]=='R'){
				red={i,j};
			}
			if(board[i][j]=='B'){
				blue={i,j};
			}
			if(board[i][j]=='O'){
				fin={i,j};
			}
		}
	}
}
int Turn(char direction){
	for(int i=0;i<4;++i){
		if(s[i]==direction){
			int by=blue.first;
			int bx=blue.second;
			bool isRed=0;
			while(1){
				if(!isRange(by,bx)){
					by-=dy[i];
					by-=dx[i];
					break;
				}
				if(board[by+dy[i]][bx+dx[i]]=='R'){
					isRed=1;
					int ry=red.first;
					int rx=red.second;
					while(1){
						if(isRed==1){
							break;
						}
						if(!isRange(ry,rx)){
							ry-=dy[i];
							ry-=dx[i];
							break;
						}
						ry+=dy[i];
						rx+=dx[i];
						if({by,bx}==fin){
							return 1;
						}
					}
				}else if(board[by+dy[i]][bx+dx[i]]=='.' || board[by+dy[i]][bx+dx[i]]=='O'){
					by+=dy[i];
					bx+=dx[i];
					if({by,bx}==fin){
						return -1;
					}	
				}else{
					blue={by,bx};
					break;
				}
				
			}
			int ry=red.first;
			int rx=red.second;
			while(1){
				if(isRed==1){
					break;
				}
				if(!isRange(ry,rx)){
					ry-=dy[i];
					ry-=dx[i];
					break;
				}
				ry+=dy[i];
				rx+=dx[i];
				if({by,bx}==fin){
					return 1;
				}
			}
		}
		
	}
	return 0;
	
}
void board_overwrite(string a[MAX]){
	for(int i=0;i<N;++i){
		board[i]=a[i];
	}
}
int res_cnt=122232421;
string res_str="";
void dfs(string ans, int cnt){
	if(cnt>10){
		return;
	}
	string tmp_board[MAX];
	for(int i=0;i<N;++i){
		tmp_board[i]=board[i];
	}
	for(int i=0;i<4;++i){
		char dir=s[i];
		string new_string=ans+dir;
		if(m[new_string]==0){
			m[new_string]==1
			int c=Turn(dir);
			if(c==-1){
				for(int i=0;i<N;++i){
					board[i]=tmp_board[i];
				}			
			}else if(c==1){
				for(int i=0;i<N;++i){
					board[i]=tmp_board[i];
				}	
				if(res_cnt>cnt){
					res_str=new_string;
					return;
				}
			}else{
				dfs(new_string,cnt+1);
				for(int i=0;i<N;++i){
					board[i]=tmp_board[i];
				}	
			}
		}
	}
}
void solve(){
	string t="";
	dfs(t,0);
}
int main() {
	// your code goes here
	Input();
	return 0;
}
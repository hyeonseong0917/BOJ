#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int N,R;
const int MAX=128+1;
int board[MAX][MAX];
int tmp_board[MAX][MAX];
vector<pair<int,int>> v;
int M;
void Input(){
	cin>>N>>R;
	M=pow(2,N);
	for(int i=0;i<M;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
		}
	}
	for(int i=0;i<R;++i){
		int a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
}
void solve(){
	for(int i=0;i<R;++i){
		int K=v[i].first;
		int L=v[i].second;
		int ps=pow(2,L);
		if(K==1){
			for(int j=0;j<M;++j){
				for(int k=0;k<M;++k){
					tmp_board[j][k]=0;
				}
			}
			int cnt=0;
			for(int j=ps-1;j<M;j+=ps){
				for(int k=0;k<ps;++k){
					for(int p=0;p<M;++p){
						tmp_board[cnt][p]=board[j-k][p];
					}
					++cnt;
				}
			}
			for(int j=0;j<M;++j){
				for(int k=0;k<M;++k){
					board[j][k]=tmp_board[j][k];
				}
			}
		}else if(K==2){
			for(int j=0;j<M;++j){
				for(int k=0;k<M;++k){
					tmp_board[j][k]=0;
				}
			}
			int y=0, x=0;
			while(1){
				int cur_cnt=0;
				for(int i=y;i<y+ps;++i){
					for(int j=x;j<x+ps;++j){
						tmp_board[i][j]=board[i][x+ps-1-j+x];
					}
				}
				x+=ps;
				if(x>=M){
					x=0;
					y+=ps;
					if(y>=M){
						break;
					}
				}
			}
			for(int j=0;j<M;++j){
				for(int k=0;k<M;++k){
					board[j][k]=tmp_board[j][k];
				}
			}
		}else if(K==3){
			int y=0, x=0;
			while(1){
				int cnt=0;
				for(int j=x;j<x+ps;++j){
					for(int k=y+ps-1;k>=y;--k){
						tmp_board[y+(j-x)][x+(cnt%ps)]=board[k][j];
						++cnt;
					}
				}
				x+=ps;
				if(x>=M){
					x=0;
					y+=ps;
					if(y>=M){
						break;
					}
				}
			}
			for(int j=0;j<M;++j){
				for(int k=0;k<M;++k){
					board[j][k]=tmp_board[j][k];
				}
			}
		}else if(K==4){
			int y=0, x=0;
			while(1){
				int cnt=0;
				for(int j=x+ps-1;j>=x;--j){
					for(int k=y;k<y+ps;++k){
						tmp_board[y+(x+ps-1)-j][x+(cnt%ps)]=board[k][j];
						// cout<<k<<" "<<x+(cnt%ps)<<endl;
						++cnt;
					}
				}
				x+=ps;
				if(x>=M){
					x=0;
					y+=ps;
					if(y>=M){
						break;
					}
				}
			}
			for(int j=0;j<M;++j){
				for(int k=0;k<M;++k){
					board[j][k]=tmp_board[j][k];
				}
			}
		}else if(K==5){
			int y=0, x=0;
			while(1){
				int cnt=0;
				for(int j=M-(y+ps);j<M-y;++j){
					for(int k=x;k<x+ps;++k){
						// cout<<board[j][k];
						tmp_board[y+cnt][k]=board[j][k];
					}
					++cnt;
				}
				x+=ps;
				if(x>=M){
					x=0;
					y+=ps;
					if(y>=M){
						break;
					}
				}
			}
			for(int j=0;j<M;++j){
				for(int k=0;k<M;++k){
					board[j][k]=tmp_board[j][k];
				}
			}
		}else if(K==6){
			int y=0, x=0;
			while(1){
				int cnt=0;
				for(int j=y;j<y+ps;++j){
					for(int k=M-(x+ps);k<M-x;++k){
						// cout<<board[j][k];
						tmp_board[j][x+(cnt%ps)]=board[j][k];
						// cout<<board[j][k]<<" ";
						++cnt;
					}
					
				}
				x+=ps;
				if(x>=M){
					x=0;
					y+=ps;
					if(y>=M){
						break;
					}
				}
			}
			for(int j=0;j<M;++j){
				for(int k=0;k<M;++k){
					board[j][k]=tmp_board[j][k];
				}
			}
		}else if(K==7){
			int y=0, x=0;
			int ny=M-ps;
			int nx=0;
			while(1){
				for(int i=0;i<ps;++i){
					for(int j=0;j<ps;++j){
						tmp_board[y+i][x+j]=board[ny+i][nx+j];
					}
				}
				ny-=ps;
				if(ny<0){
					ny=M-ps;
					nx+=ps;
				}
				
				x+=ps;
				if(x>=M){
					x=0;
					y+=ps;
					if(y>=M){
						break;
					}
				}
			}
			for(int j=0;j<M;++j){
				for(int k=0;k<M;++k){
					board[j][k]=tmp_board[j][k];
				}
			}
		}else{
			int y=0, x=0;
			int nx=M-ps;
			int ny=0;
			while(1){
				for(int i=0;i<ps;++i){
					for(int j=0;j<ps;++j){
						tmp_board[y+i][x+j]=board[ny+i][nx+j];
					}
				}
				ny+=ps;
				if(ny==M){
					nx-=ps;
					ny=0;
				}
				
				x+=ps;
				if(x>=M){
					x=0;
					y+=ps;
					if(y>=M){
						break;
					}
				}
			}
			for(int j=0;j<M;++j){
				for(int k=0;k<M;++k){
					board[j][k]=tmp_board[j][k];
				}
			}
		}
	}
	for(int i=0;i<M;++i){
		for(int j=0;j<M;++j){
			cout<<board[i][j]<<" ";
		}cout<<"\n";
	}
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}
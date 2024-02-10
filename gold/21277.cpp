#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

const int MAX=150+1;
int board[MAX][MAX];
int N1,M1,N2,M2;
vector<vector<int>> fst_board;
vector<vector<int>> sed_board;
void Input(){
	cin>>N1>>M1;
	for(int i=0;i<N1;++i){
		vector<int> v;
		for(int j=0;j<M1;++j){
			char a;
			cin>>a;
			v.push_back(a-'0');
		}
		fst_board.push_back(v);
	}
	cin>>N2>>M2;
	for(int i=0;i<N2;++i){
		vector<int> v;
		for(int j=0;j<M2;++j){
			char a;
			cin>>a;
			v.push_back(a-'0');
		}
		sed_board.push_back(v);
	}
}
vector<vector<int>> turn(int dir){
	vector<vector<int>> turned_vector;
	if(dir==0){
		turned_vector=sed_board;
	}else if(dir==1){
		for(int i=0;i<M2;++i){
			vector<int> v;
			for(int j=N2-1;j>=0;--j){
				v.push_back(sed_board[j][i]);
			}
			turned_vector.push_back(v);
		}
	}else if(dir==2){	
		for(int i=N2-1;i>=0;--i){
			vector<int> v;
			for(int j=M2-1;j>=0;--j){
				v.push_back(sed_board[i][j]);
			}
			turned_vector.push_back(v);
		}
	}else{
		for(int i=M2-1;i>=0;--i){
			vector<int> v;
			for(int j=0;j<N2;++j){
				v.push_back(sed_board[j][i]);
			}
			turned_vector.push_back(v);
		}
	}
	return turned_vector;
}
bool visited[4][4];
int ans=1222232421;
void Init(){
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			board[i][j]=0;
		}
	}
	for(int i=0;i<fst_board.size();++i){
		for(int j=0;j<fst_board[i].size();++j){
			board[50+i][50+j]=fst_board[i][j];
		}
	}
}
void calc(int idx){
	Init();
	vector<vector<int>> cur_sed_board=turn(idx);
	for(int i=0;i+cur_sed_board.size()<MAX;++i){
		for(int j=0;j+cur_sed_board[0].size()<MAX;++j){
			// i,j에 cur_sed_board[0][0]를 끼울 수 있는지?
			bool flag=0;
			int x1=200, y1=200, y2=-1, x2=-1;
			for(int k=0;k<cur_sed_board.size();++k){
				for(int p=0;p<cur_sed_board[0].size();++p){
					if(board[i+k][j+p]==1 && cur_sed_board[k][p]==1){
						flag=1;
						break;
					}

				}
				if(flag){
					break;
				}
			}
			if(!flag){
				y1=min(i,50);
				x1=min(j,50);
				y2=max(i+cur_sed_board.size(),50+fst_board.size());
				x2=max(j+cur_sed_board[0].size(),50+fst_board[0].size());
				ans=min(ans,(y2-y1)*(x2-x1));
			}
		}
	}
}
void solve(){
	calc(0);
	calc(1);
	calc(2);
	calc(3);
	cout<<ans;

	// vector<vector<int>> a=turn(1,2);
	// for(int i=0;i<a.size();++i){
	// 	for(int j=0;j<a[i].size();++j){
	// 		cout<<a[i][j]<<" ";
	// 	}cout<<endl;
	// }
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
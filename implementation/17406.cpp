#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N,M,K;
const int MAX=50+1;
int board[MAX][MAX];
int tmp[MAX][MAX];
int new_board[MAX][MAX];
int origin_board[MAX][MAX];
bool visited[MAX][MAX];
bool check[6+1];

vector<pair<pair<int,int>,int>> p;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
void Input(){
	cin>>N>>M>>K;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
			origin_board[i][j]=board[i][j];
		}
	}
	for(int i=0;i<K;++i){
		int a,b,c;
		cin>>a>>b>>c;
		p.push_back({{a-1,b-1},c});
	}
}
void turn(int r, int c, int s){
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			tmp[i][j]=0;
			new_board[i][j]=0;
			visited[i][j]=0;
		}
	}
	for(int i=r-s;i<=r+s;++i){
		for(int j=c-s;j<=c+s;++j){
			tmp[i-(r-s)][j-(c-s)]=board[i][j];
		}
	}
	// cout<<s*2<<endl;
	// for(int i=0;i<=s*2;++i){
	// 	for(int j=0;j<=s*2;++j){
	// 		cout<<tmp[i][j]<<" ";
	// 	}cout<<endl;
	// }
	int y=0, x=0;
	int cy=0, cx=0;
	
	while(1){
		if(visited[y][x]){
			break;
		}
		new_board[y][x]=tmp[y][x];
		if(y==s && x==s){
			break;
		}
		cy=y;
		cx=x;
		//(1)
		while(1){
			new_board[cy][cx+1]=tmp[cy][cx];
			visited[cy][cx+1]=1;
			++cx;
			if(cx==s*2){
				// cout<<"he";
				break;
			}
			if(visited[cy][cx+1]==1){
				break;
			}
		}
		// //(2)
		while(1){
			
			new_board[cy+1][cx]=tmp[cy][cx];
			visited[cy+1][cx]=1;
			++cy;
			
			if(cy==s*2){
				break;
			}
			if(visited[cy+1][cx]==1){
				break;
			}
		}
		
		//(3)
		while(1){
			new_board[cy][cx-1]=tmp[cy][cx];
			visited[cy][cx-1]=1;
			--cx;
			
			if(cx==x){
				break;
			}
			if(visited[cy][cx-1]==1){
				break;
			}
		}
		
		//(4)
		while(1){
			new_board[cy-1][cx]=tmp[cy][cx];
			visited[cy-1][cx]=1;
			--cy;
			
			if(cy==y){
				break;
			}
			if(visited[cy-1][cx]==1){
				break;
			}
		}
		
		++y;
		++x;
		
		// break;
		
	}
	// cout<<endl;
	// for(int i=0;i<=s*2;++i){
	// 	for(int j=0;j<=s*2;++j){
	// 		cout<<new_board[i][j]<<" ";
	// 	}cout<<endl;
	// }
	for(int i=r-s;i<=r+s;++i){
		for(int j=c-s;j<=c+s;++j){
			board[i][j]=new_board[i-(r-s)][j-(c-s)];
		}
	}
	// for(int i=0;i<N;++i){
	// 	for(int j=0;j<M;++j){
	// 		cout<<board[i][j]<<" ";
	// 	}cout<<endl;
	// }
	// cout<<endl;
}
vector<int> cur_pick;
int minNum=122232421;
void pick(int idx, int cnt){
	if(cnt==K){
		
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				board[i][j]=origin_board[i][j];
			}
		}
		for(int i=0;i<cnt;++i){
			int cur_idx=cur_pick[i];
			// cout<<cur_idx<<" ";
			int r=p[cur_idx].first.first;
			int c=p[cur_idx].first.second;
			int s=p[cur_idx].second;
			turn(r,c,s);
		}
		// cout<<endl;
		for(int i=0;i<N;++i){
			int curSum=0;
			for(int j=0;j<M;++j){
				curSum+=board[i][j];
			}
			// cout<<curSum<<endl;
			minNum=min(minNum,curSum);
		}
	
		return;
		
	}
	if(idx>=K){
		return;
	}
	for(int i=0;i<K;++i){
		if(!check[i]){
			check[i]=1;
			cur_pick.push_back(i);
			pick(i,cnt+1);
			cur_pick.pop_back();
			check[i]=0;
		}
	}
}

int main() {
	// your code goes here
	Input();
	pick(0,0);
	cout<<minNum;
	return 0;
}
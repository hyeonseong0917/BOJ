#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

// 1221
// 1245
string board[12];
void Input(){
	for(int i=0;i<12;++i){
		cin>>board[i];
	}
}
void Down(){
	for(int i=0;i<6;++i){
		for(int j=10;j>=0;--j){
			if(board[j][i]!='.'){
				char c=board[j][i];
				int y=j;
				while(1){
					if(y>=11) break;
					if(board[y+1][i]=='.'){
						board[y+1][i]=c;
						board[y][i]='.';
						++y;
					}else{
						break;
					}
				}
			}
		}
	}
}
int visited[12][6];
vector<pair<int,int>> tmp;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<12 && x<12);
}
void dfs(int y, int x){
	for(int i=0;i<4;++i){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(!isRange(ny,nx)) continue;
		if(visited[ny][nx]) continue;
		if(board[ny][nx]!=board[y][x]) continue;
		visited[ny][nx]=1;
		tmp.push_back({ny,nx});
		dfs(ny,nx);
	}
}
void solve(){
	int ans=0;
	while(1){
		// 현재 터지는 뿌요가 있는지?
		// 동시에 터지는 뿌요도 생각해야함
		for(int i=0;i<12;++i){
			for(int j=0;j<6;++j){
				visited[i][j]=0;
			}
		}
		bool flag=0;
		while(1){
			// 현재 상태에서 터지는 뿌요 있는지
			bool cur_flag=0;
			for(int i=0;i<12;++i){
				for(int j=0;j<6;++j){
					if(board[i][j]!='.'){
						// 4개 이상 연결되어 있는지?
						visited[i][j]=1;
						tmp.clear();
						tmp.push_back({i,j});
						dfs(i,j);
						int ts=tmp.size();
						if(ts>=4){
							flag=1;
							cur_flag=1;
							for(int k=0;k<ts;++k){
								int y=tmp[k].first;
								int x=tmp[k].second;
								board[y][x]='.';
							}
						}
					}
				}
			}
			if(!cur_flag) break;
		}
		// cout<<"\n";
		// for(int i=0;i<12;++i){
		// 	for(int j=0;j<6;++j){
		// 		cout<<board[i][j];
		// 	}cout<<"\n";
		// }
		// 뿌요 터지는거 없음
		if(!flag) break;
		// 떨어짐 => 밑에부터 보면서, 본인 밑에 '.' 이라면 계속 떨어짐
		Down();
		// cout<<"after down \n";
		// for(int i=0;i<12;++i){
		// 	for(int j=0;j<6;++j){
		// 		cout<<board[i][j];
		// 	}cout<<"\n";
		// }
		++ans;
	}
	cout<<ans;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	for(ll o=1;o<=1;++o){
		Input();
		solve();
	}
	return 0;
}
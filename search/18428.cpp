	#include <iostream>
	#include <vector>
	#include <algorithm>
	using namespace std;
	
	int N=0;
	const int MAX=6+1;
	char board[MAX][MAX];
	vector<pair<int,int>> S,T,B;
	vector<bool> visited;
	int dy[4]={-1,0,1,0};
	int dx[4]={0,1,0,-1};
	bool isRange(int y, int x){
		return (y>=0 && x>=0 && y<N && x<N);
	}
	void Input(){
		cin>>N;
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				cin>>board[i][j];
				if(board[i][j]=='S'){
					S.push_back({i,j});
				}else if(board[i][j]=='T'){
					T.push_back({i,j});
				}else{
					B.push_back({i,j});
					visited.push_back(0);
				}
			}
		}
	}
	bool isClear=0;
	void dfs(int cnt, int idx){
		if(cnt==0){
			for(int i=0;i<T.size();++i){
				int y=T[i].first;
				int x=T[i].second;
				for(int j=0;j<4;++j){
					int cy=y;
					int cx=x;
					while(1){
						cy+=dy[j];
						cx+=dx[j];
						if(!isRange(cy,cx) || board[cy][cx]=='O'){
							break;
						}
						if(board[cy][cx]=='S'){
							return;
						}
					}	
				}
			}
			isClear=1;
			return;
		}
		for(int i=idx;i<B.size();++i){
			
			if(!visited[i]){
				int cy=B[i].first;
				int cx=B[i].second;
				visited[i]=1;
				board[cy][cx]='O';
				dfs(cnt-1,i);
				visited[i]=0;
				board[cy][cx]='X';
			}
		}
		
	}
	void solve(){
		dfs(3,0);
		if(isClear){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
	}
	int main() {
		// your code goes here
		Input();
		solve();
		
		// cout<<board[0][1];
		return 0;
	}
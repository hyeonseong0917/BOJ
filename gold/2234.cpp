#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

int N,M;
const int MAX=50+1;
int board[MAX][MAX];
bool visited[MAX][MAX];
bool check[MAX][MAX][4];
int dy[4]={0,-1,0,1};
int dx[4]={-1,0,1,0};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<M && x<N);
}

void Input(){
	cin>>N>>M;
	for(int i=0;i<M;++i){
		for(int j=0;j<N;++j){
			int num=0;
			cin>>num;
			bool flag=0;
			for(int a=0;a<2;++a){
				for(int b=0;b<2;++b){
					for(int c=0;c<2;++c){
						for(int d=0;d<2;++d){
							if((int)pow(1,a)*a+(int)pow(2,b)*b+(int)pow(4,c)*c+(int)pow(8,d)*d==num && !flag){
								// cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
								flag=1;
								check[i][j][0]=a;
								check[i][j][1]=b;
								check[i][j][2]=c;
								check[i][j][3]=d;
							}
						}
					}
				}
			}
		}
	}
}
int BFS(int cy, int cx){
	queue<pair<int,int>> q;
	int cnt=1;
	q.push({cy,cx});
	visited[cy][cx]=1;
	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
		q.pop();
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(!isRange(ny,nx)) continue;
			if(visited[ny][nx]) continue;
			if(!check[y][x][i] && !check[ny][nx][(i+2)%4]){
				visited[ny][nx]=1;
				q.push({ny,nx});
				++cnt;
			}
		}
	}
	return cnt;
}
int room_cnt=0;
int max_room_size=0;
int new_room_size=0;
void solve(){
	for(int i=0;i<M;++i){
		for(int j=0;j<N;++j){
			if(!visited[i][j]){
				++room_cnt;
				max_room_size=max(max_room_size,BFS(i,j));
			}
		}
	}
	for(int i=0;i<M;++i){
		for(int j=0;j<N;++j){
			for(int k=0;k<4;++k){
				for(int a=0;a<M;++a){
					for(int b=0;b<N;++b){
						visited[a][b]=0;
					}
				}
				if(check[i][j][k] && isRange(i+dy[k],j+dx[k])){
					check[i][j][k]=0;
					check[i+dy[k]][j+dx[k]][(k+2)%4]=0;
					new_room_size=max(new_room_size,BFS(i,j));
					check[i][j][k]=1;
					check[i+dy[k]][j+dx[k]][(k+2)%4]=1;
				}
			}
		}
	}
	cout<<room_cnt<<"\n";
	cout<<max_room_size<<"\n";
	cout<<new_room_size<<"\n";
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
#include <iostream>
#include <vector>
using namespace std;

int N,M;
int map[9][9];
int copyMap[9][9];
bool visited[9][9][4];
vector<pair<int,int>> camera;
vector<int> angle;
int result=0;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}

void copy(){
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			copyMap[i][j]=map[i][j];
		}
	}
}
int numOfSpot(){
	int cnt=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(copyMap[i][j]==0){
				cnt++;
			}
		}
	}
	return cnt;
}

void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>map[i][j];
			if(1<=map[i][j] && map[i][j]<=5){
				camera.push_back({i,j});
				
			}
			switch(map[i][j]){
		case 1:
				visited[i][j][0]=1;
				break;
		case 2:
				visited[i][j][0]=1;
				visited[i][j][2]=1;
				break;
		case 3:
				visited[i][j][0]=1;
				visited[i][j][1]=1;
				break;
		case 4:
				visited[i][j][0]=1;
				visited[i][j][1]=1;
				visited[i][j][2]=1;
				break;
		case 5:
				visited[i][j][0]=1;
				visited[i][j][1]=1;
				visited[i][j][2]=1;
				visited[i][j][3]=1;
				break;
	}
		}
	}
	
}
void dfs(int cnt){
	if(cnt==camera.size()){
		for(int i=0;i<camera.size();++i){
			int y=camera[i].first;
			int x=camera[i].second;
			for(int j=0;j<4;++j){
				if(visited[y][x][j]){
				int ny=y+dy[(j+angle[i])%4];
				int nx=x+dx[(j+angle[i])%4];
				while(1){
					if(copyMap[ny][nx]==6){
						break;
					}
					if(!isRange(ny,nx)){
						break;
					}
					if(copyMap[ny][nx]==0){
						copyMap[ny][nx]=-1;
					}
					ny+=dy[(j+angle[i])%4];
					nx+=dx[(j+angle[i])%4];
				}
			}
			}
		}
		
		result=min(result,numOfSpot());
		copy();
		return;
	}
	for(int i=0;i<4;++i){
		angle.push_back(i);
		dfs(cnt+1);
		angle.pop_back();
	}
}


int main() {
	Input();
	result=122232421;
	copy();
	dfs(0);
	cout<<result;
}
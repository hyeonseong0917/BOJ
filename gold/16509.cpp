#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

int py,px,ky,kx;

bool isRange(int y, int x){
	return (y>=0 && y<=9 && x>=0 && x<=8);
}
bool visited[10+1][9+1];
void Input(){
	cin>>py>>px;
	cin>>ky>>kx;
}
int dy[8]={-3,-3,-2,2,3,3,-2,2};
int dx[8]={2,-2,3,3,2,-2,-3,-3};
int BFS(int start_y, int start_x, int fin_y, int fin_x){
	queue<pair<pair<int,int>,int>> q;
	q.push({{start_y, start_x},0});
	visited[start_y][start_x]=1;
	while(!q.empty()){
		int y=q.front().first.first;
		int x=q.front().first.second;
		int cnt=q.front().second;
		if(y==fin_y && x==fin_x) return cnt;
		q.pop();
		for(int i=0;i<8;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(!isRange(ny,nx)) continue;
			if(visited[ny][nx]) continue;
			// y,x에서 ny,nx까지 아무 기물 없는지?
			bool flag=0;
			int cy=y;
			int cx=x;
			vector<pair<int,int>> pos;
			if(i==0){
				// -3,2
				cy-=1;
				pos.push_back({cy,cx});
				cy-=1;
				cx+=1;
				pos.push_back({cy,cx});
				// cy-=1;
				// cx+=1;
				// pos.push_back({cy,cx});
			}else if(i==1){
				// -3,-2
				cy-=1;
				pos.push_back({cy,cx});
				cy-=1;
				cx-=1;
				pos.push_back({cy,cx});
				// cy-=1;
				// cx-=1;
				// pos.push_back({cy,cx});
			}else if(i==2){
				// -2,3
				cx+=1;
				pos.push_back({cy,cx});
				cy-=1;
				cx+=1;
				pos.push_back({cy,cx});
				// cy-=1;
				// cx+=1;
				// pos.push_back({cy,cx});
			}else if(i==3){
				// 2,3
				cx+=1;
				pos.push_back({cy,cx});
				cy+=1;
				cx+=1;
				pos.push_back({cy,cx});
				// cy+=1;
				// cx+=1;
				// pos.push_back({cy,cx});
			}else if(i==4){
				// 3,2
				cy+=1;
				pos.push_back({cy,cx});
				cy+=1;
				cx+=1;
				pos.push_back({cy,cx});
				// cy+=1;
				// cx+=1;
				// pos.push_back({cy,cx});
			}else if(i==5){
				// 3,-2
				cy+=1;
				pos.push_back({cy,cx});
				cy+=1;
				cx-=1;
				pos.push_back({cy,cx});
				// cy+=1;
				// cx-=1;
				// pos.push_back({cy,cx});
			}else if(i==6){
				// -2,-3
				cx-=1;
				pos.push_back({cy,cx});
				cy-=1;
				cx-=1;
				pos.push_back({cy,cx});
				// cy-=1;
				// cx-=1;
				// pos.push_back({cy,cx});
			}else if(i==7){
				// -2,-3
				cx-=1;
				pos.push_back({cy,cx});
				cy+=1;
				cx-=1;
				pos.push_back({cy,cx});
				// cy+=1;
				// cx-=1;
				// pos.push_back({cy,cx});
			}
			for(int j=0;j<pos.size();++j){
				if(pos[j].first==fin_y && pos[j].second==fin_x){
					flag=1;
					break;
				}
			}
			if(!flag){
				visited[ny][nx]=1;
				q.push({{ny,nx},cnt+1});	
			}
			
		}

	}
	return -1;
}
void solve(){
	int ans=BFS(py,px,ky,kx);
	cout<<ans;
}

int main() {
	// your code goes here
	Input();
	solve();

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MAX=100+1;
bool visited[MAX][MAX];
int N,M;
int shop_num;
pair<int,int> p;
vector<pair<int,int>> v;
vector<int> dist_save;

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<=M && x<=N);
}
void Input(){
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			visited[i][j]=0;
		}
	}
	cin>>N>>M;
	cin>>shop_num;
	
	for(int i=0;i<shop_num+1;++i){
		int d,num;
		cin>>d>>num;
		if(d==1){
			if(i==shop_num){
				p=make_pair(0,num);
			}
			v.push_back({0,num});
		}else if(d==2){
			if(i==shop_num){
				p=make_pair(M,num);
			}
			v.push_back({M,num});
		}else if(d==3){
			if(i==shop_num){
				p=make_pair(num,0);
			}
			v.push_back({num,0});
		}else{
			if(i==shop_num){
				p=make_pair(num,N);
			}
			v.push_back({num,N});
		}
	}

}

void dfs(int cy, int cx, int fin_idx, int cnt){
	if(cy==v[fin_idx].first && cx==v[fin_idx].second){
		visited[cy][cx]=0;
		// cout<<cy<<" "<<cx;
		dist_save.push_back(cnt);
		return;
	}
	for(int i=0;i<4;++i){
		int ny=cy+dy[i];
		int nx=cx+dx[i];
		if(!isRange(ny,nx)) continue;
		if(visited[ny][nx]) continue;
		if(ny==0 || nx==0 || ny==M || nx==N){
			visited[ny][nx]=1;
			dfs(ny,nx,fin_idx,cnt+1);
			// visited[ny][nx]=0;
		}
	}
}


void solve(){
	int dist=0;
	// cout<<v[0].first;

	for(int i=0;i<shop_num;++i){
		//p에서 v[i]까지의 거리
		for(int j=0;j<=M;++j){
			for(int k=0;k<=N;++k){
				visited[j][k]=0;
			}
		}
		dist_save.clear();
		visited[p.first][p.second]=1;
		dfs(p.first,p.second,i,0);
		dist+=min(dist_save[0],dist_save[1]);
	}
	cout<<dist;
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;




int N;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
const int MAX=125;
int board[MAX][MAX];
int dist[MAX][MAX];
int INF=122232421;
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
int dijkstra(){
	priority_queue<pair<int,pair<int,int>>> pq;
	pq.push({0,{0,0}});
	while(!pq.empty()){
		int cnt=pq.top().first*-1;
		int y=pq.top().second.first;
		int x=pq.top().second.second;
		if(y==N-1 && x==N-1){
			return cnt;
		}
		pq.pop();
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(!isRange(ny,nx)) continue;
			if(dist[ny][nx]>dist[y][x]+board[ny][nx]){
				dist[ny][nx]=dist[y][x]+board[ny][nx];
				pq.push({dist[ny][nx]*-1,{ny,nx}});
			}
		}
	}
	return -1;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int cnt=1;
	while(1){
		cin>>N;
		if(N==0){
			break;
		}
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				cin>>board[i][j];
				dist[i][j]=INF;
			}
		}
		dist[0][0]=board[0][0];
		cout<<"Problem "<<cnt<<": "<<dijkstra()<<"\n";
		++cnt;
	}
	
	return 0;
}
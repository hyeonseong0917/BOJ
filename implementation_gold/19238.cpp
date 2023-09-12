#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

const int MAX=20+5;
int N,M;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int board[MAX][MAX];
bool visited[MAX];
int INF=122232421;
pair<pair<int,int>,int> taxi;
vector<pair<int,int>> people_start_pos;
vector<pair<int,int>> people_finish_pos;
vector<pair<pair<int,int>,pair<int,int>>> people_dist;
//{{사람번호,거리},{y,x}}

bool isRange(int y,int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
void Input(){
	int oil=0;
	cin>>N>>M>>oil;
	taxi.second=oil;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
		}
	}
	int y,x;
	cin>>y>>x;
	taxi.first=make_pair(y-1,x-1);
	for(int i=0;i<M;++i){
		int cy,cx,fy,fx;
		cin>>cy>>cx>>fy>>fx;
		people_start_pos.push_back({cy-1,cx-1});
		people_finish_pos.push_back({fy-1,fx-1});
	}
}
bool comp(pair<pair<int,int>,pair<int,int>> a, pair<pair<int,int>,pair<int,int>> b){
	if(a.first.second==b.first.second){
		if(a.second.first==b.second.first){
			return a.second.second<b.second.second;
		}
		return a.second.first<b.second.first;
	}
	return a.first.second<b.first.second;
}

int BFS(int cur_people, bool flag){
	//flag=0 택시->사람
	//flag=1 택시->목적지
	bool check[MAX][MAX];
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			check[i][j]=0;
		}
	}
	queue<pair<pair<int,int>,int>> q;
	q.push({{taxi.first.first, taxi.first.second},0});
	check[taxi.first.first][taxi.first.second]=1;
	while(!q.empty()){
		int y=q.front().first.first;
		int x=q.front().first.second;
		int cnt=q.front().second;
		q.pop();
		if(y==people_start_pos[cur_people].first && x==people_start_pos[cur_people].second && !flag){
			return cnt;
		}
		if(y==people_finish_pos[cur_people].first && x==people_finish_pos[cur_people].second && flag){
			return cnt;
		}
		for(int i=0;i<4;++i){
			int ny=y+dy[i];
			int nx=x+dx[i];
			// cout<<ny<<" "<<nx<<" "<<isRange(ny,nx)<<" "<<board[ny][nx]<<" "<<check[ny][nx]<<endl;
			if(!isRange(ny,nx)) continue;
			if(board[ny][nx]) continue;
			if(check[ny][nx]) continue;
			check[ny][nx]=1;
			q.push({{ny,nx},cnt+1});
		}
	}
	return -1;
}

void solve(){
	while(people_start_pos.size()){
		people_dist.clear();
		
		//현재 택시의 위치에서 승객 간 모든 거리를 구해 people_dist에
		int minDist=INF;
		int minNum=-1;
		bool flag=0;
		for(int i=0;i<people_start_pos.size();++i){
			//현재 택시의 위치에서 i번째 손님까지의 거리
			int cur_dist=BFS(i,0);
			people_dist.push_back({{i,cur_dist},{people_start_pos[i]}});
			if(cur_dist==-1){
				//갈 수 없다
				flag=1;
				break;
			}
		}
		
		if(flag==1){
			cout<<-1;
			return;
		}
		
		sort(people_dist.begin(),people_dist.end(),comp);
		minNum=people_dist[0].first.first;
		minDist=people_dist[0].first.second;
		if(minDist>taxi.second){
			cout<<-1;
			return;
		}
		//현재 택시의 위치에서 승객 위치까지 이동
		taxi.first.first=people_start_pos[minNum].first;
		taxi.first.second=people_start_pos[minNum].second;;
		taxi.second-=minDist;
		
		//승객 위치에서 목적지까지 이동
		int finish_dist=BFS(minNum,1);
		if(finish_dist>taxi.second || finish_dist==-1){
			cout<<-1;
			return;
		}
		taxi.second+=finish_dist;
		taxi.first.first=people_finish_pos[minNum].first;
		taxi.first.second=people_finish_pos[minNum].second;
		
		//minNum번째 승객을 삭제
		people_start_pos.erase(people_start_pos.begin()+minNum);
		people_finish_pos.erase(people_finish_pos.begin()+minNum);
	}
	cout<<taxi.second;
}



int main() {
	// your code goes here
	Input();
	solve();
	// cout<<bfs(v);
	return 0;
}
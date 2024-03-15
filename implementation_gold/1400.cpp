#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int N,M;
const int MAX=20+1;
char board[MAX][MAX];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int INF=1222232421;
int dist[MAX][MAX];
vector<pair<char,pair<int,int>>> v;
int tl=0;
int cy,cx;
int fy,fx;
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
// cur_traffic_num번째 교차로에서 현재 cur_time기준 언제 가장 빨리 다음 진입할 수 있는지
int get_light_time(int cur_time, int cur_traffic_num, int dir){
	char init_light=v[cur_traffic_num].first;
	int fst_num=v[cur_traffic_num].second.first;
	int sed_num=v[cur_traffic_num].second.second;
	int new_time=(cur_time+1)%(fst_num+sed_num);
	++new_time;
	++cur_time;
	if(dir==0 || dir==2){
		if(init_light=='-'){
			if(new_time<=fst_num){
				cur_time+=fst_num-new_time+1;
			}
		}else if(init_light=='|'){
			if(1+sed_num<=new_time){
				cur_time+=fst_num+sed_num-new_time+1;
			}
		}
	}else{
		if(init_light=='|'){
			if(new_time<=sed_num){
				cur_time+=sed_num-new_time+1;
			}
		}else if(init_light=='-'){
			if(1+fst_num<=new_time){
				cur_time+=fst_num+sed_num-new_time+1;
			}
		}
	}
	return cur_time;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	while(1){
		cin>>N>>M;
		if(N==0 && M==0){
			break;
		}
		tl=-1;
		v.clear();
		int cnt=0;
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				cin>>board[i][j];
				if('0'<=board[i][j] && board[i][j]<='9'){
					tl=max(tl,board[i][j]-'0');
				}
				if(board[i][j]=='A'){
					cy=i;
					cx=j;
				}
				if(board[i][j]=='B'){
					fy=i;
					fx=j;
				}
				dist[i][j]=INF;
			}
		}
		// cout<<tl<<"\n";
		// break;
		if(tl==-1){
			priority_queue<pair<int,pair<int,int>>> nq;
			nq.push({-1,{cy,cx}});
			dist[cy][cx]=0;
			while(!nq.empty()){
				int cnt=nq.top().first*-1;
				int y=nq.top().second.first;
				int x=nq.top().second.second;
				if(board[y][x]=='B'){
					break;
				}
				nq.pop();
				for(int i=0;i<4;++i){
					int ny=y+dy[i];
					int nx=x+dx[i];
					if(!isRange(ny,nx)) continue;
					if(board[ny][nx]=='#' || board[ny][nx]=='B'){
						if(dist[ny][nx]>dist[y][x]+1){
							dist[ny][nx]=dist[y][x]+1;
							nq.push({(cnt+1)*-1,{ny,nx}});
						}
					}
				}
			}
			if(dist[fy][fx]==INF){
				cout<<"impossible"<<"\n";
			}else{
				cout<<dist[fy][fx]<<"\n";
			}
			continue;
		}
		if(tl!=-1){
			++tl;
			for(int i=0;i<tl;++i){
				int a,c,d;
				char b;
				cin>>a>>b>>c>>d;
				v.push_back({b,{c,d}});
			}	
		}
		
		priority_queue<pair<int,pair<pair<int,int>,int>>> pq;
		pq.push({-1,{{cy,cx},-1}});
		dist[cy][cx]=1;

		while(!pq.empty()){
			int cur_time=pq.top().first*-1;
			int y=pq.top().second.first.first;
			int x=pq.top().second.first.second;
			cout<<y<<" "<<x<<" "<<dist[y][x]<<"\n";
			int pre_num=pq.top().second.second;
			if(board[y][x]=='B'){
				break;
			}
			pq.pop();
			for(int i=0;i<4;++i){
				int ny=y+dy[i];
				int nx=x+dx[i];
				if(!isRange(ny,nx)) continue;
				if(board[ny][nx]=='.') continue;
				if(board[ny][nx]=='#' || board[ny][nx]=='B'){
					if(dist[ny][nx]>dist[y][x]+1){
						dist[ny][nx]=dist[y][x]+1;
						pq.push({(cur_time+1)*-1, {{ny,nx},pre_num}});
					}
					continue;
				}
				if('0'<=board[ny][nx] && board[ny][nx]<='9'){
					int cur_traffic=board[ny][nx]-'0';
					int next_time=get_light_time(cur_time, cur_traffic, i);
					if(pre_num!=-1){
						int pre_time=get_light_time(cur_time, pre_num, i);
						next_time=min(next_time,pre_time);
					}
					if(dist[ny][nx]>next_time){
						dist[ny][nx]=next_time;
						pq.push({next_time*-1, {{ny,nx},cur_traffic}});
					}
					
				}
			}
		}
		// cout<<dist[2][4]<<"\n";
		if(dist[fy][fx]==INF){
			cout<<"impossible"<<"\n";
		}else{
			cout<<dist[fy][fx]<<"\n";
		}
	}
	
	return 0;
}
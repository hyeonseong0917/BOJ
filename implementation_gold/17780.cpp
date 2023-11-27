#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int N,K;
const int MAX=12+1;
int board[MAX][MAX];
int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};
vector<int> p[MAX]; //p[i]={j,k}: i번째 말 위에 뭐있는지
vector<pair<pair<int,int>,int>> pos; //pos[i]: i번째 말의 위치와 방향
int under_num[MAX][MAX]; // under_num[i][j]: board[i][j]의 가장 아래에 있는 num

bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}

void Input(){
	cin>>N>>K;
	// 0:흰 1:빨 2:파
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>board[i][j];
		}
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			under_num[i][j]=-1;
		}
		p[i].clear();
	}
	for(int i=0;i<K;++i){
		int y,x,d;
		cin>>y>>x>>d;
		p[i].push_back(i);
		pos.push_back({{y-1,x-1},d-1});
		under_num[y-1][x-1]=i;
	}
}
int turn=1;
void solve(){
	
	while(1){
		// cout<<turn<<endl;
		for(int i=0;i<K;++i){
			if(p[i].size()==0) continue;
			if(p[i].size()>=4) return;

			int y=pos[i].first.first;
			int x=pos[i].first.second;
			int d=pos[i].second;

			int ny=y+dy[d];
			int nx=x+dx[d];

			// blue
			// p,pos,under_num
			bool flag=0;
			if(!isRange(ny,nx) || board[ny][nx]==2){
				if(d==0){
					d=1;
				}else if(d==1){
					d=0;
				}else if(d==2){
					d=3;
				}else if(d==3){
					d=2;
				}
				ny=y+dy[d];
				nx=x+dx[d];
				
				if(!isRange(ny,nx) || board[ny][nx]==2){
					pos[i].second=d;
					continue;
				}
			}
			
			// 0
			if(board[ny][nx]==0){
				int cur_under_num=under_num[ny][nx];
				if(cur_under_num==-1){
					// 새로 이동한 칸에 아무 말도 없는 경우
					for(int j=0;j<p[i].size();++j){
						pos[p[i][j]].first.first=ny;
						pos[p[i][j]].first.second=nx;
					}
					pos[i].first.first=ny;
					pos[i].first.second=nx;
					pos[i].second=d;
					under_num[y][x]=-1;
					under_num[ny][nx]=i;

				}else{
					// 새로 이동한 칸에 말 존재하는 경우
					// cout<<i<<" "<<cur_under_num<<" "<<p[i].size()<<" ";
					// cout<<pos[i].first.first<<" "<<pos[i].first.second;
					// if(turn==2) return;		
					for(int j=0;j<p[i].size();++j){
						// cout<<cur_under_num<<" "<<p[i][j]<<" ";
						p[cur_under_num].push_back(p[i][j]);	
						pos[p[i][j]].first.first=ny;
						pos[p[i][j]].first.second=nx;
					}

					if(p[cur_under_num].size()>=4){
						return;
					}
					p[i].clear();
					
					// for(int j=0;j<p[i].size();++j){
					// 	cout<<p[i][j]<<" ";
					// }cout<<endl;
					pos[i].first.first=ny;
					pos[i].first.second=nx;
					pos[i].second=d;
					under_num[y][x]=-1;
				}
				continue;
			}

			// 1
			if(board[ny][nx]==1){
				int cur_under_num=under_num[ny][nx];
				if(cur_under_num==-1){
					// 새로 이동한 칸에 아무 말도 없는 경우
					vector<int> tmp;
					tmp.clear();
					for(int j=0;j<p[i].size();++j){
						pos[p[i][j]].first.first=ny;
						pos[p[i][j]].first.second=nx;
						tmp.push_back(p[i][j]);
					}
					pos[i].first.first=ny;
					pos[i].first.second=nx;
					pos[i].second=d;
					
					reverse(p[i].begin(),p[i].end());
					reverse(tmp.begin(),tmp.end());
					int reversed_under_num=p[i][0];
					if(reversed_under_num==i){
						under_num[y][x]=-1;
						under_num[ny][nx]=reversed_under_num;
						continue;
					}
					// cout<<i<<" "<<p[i].size()<<" "<<reversed_under_num<<endl;
					// return;
					for(int j=0;j<tmp.size();++j){
						p[reversed_under_num].push_back(tmp[j]);
					}
					if(p[reversed_under_num].size()>=4){
						return;
					}
					// for(int j=0;j<p[reversed_under_num].size();++j){
					// 	cout<<p[reversed_under_num][j]<<" ";
					// }
					// return;
					p[i].clear();
					
					under_num[y][x]=-1;
					under_num[ny][nx]=reversed_under_num;
				}else{
					// 새로 이동한 칸에 말 존재하는 경우
					reverse(p[i].begin(),p[i].end());
					for(int j=0;j<p[i].size();++j){
						p[cur_under_num].push_back(p[i][j]);	
						pos[p[i][j]].first.first=ny;
						pos[p[i][j]].first.second=nx;
					}
					if(p[cur_under_num].size()>=4){
						return;
					}
					p[i].clear();
					pos[i].first.first=ny;
					pos[i].first.second=nx;
					pos[i].second=d;
					under_num[y][x]=-1;
				}
				continue;
			}
		}
		++turn;
		
		// for(int i=0;i<K;++i){
		// 	cout<<i<<" ";
		// 	for(int j=0;j<p[i].size();++j){
		// 		cout<<p[i][j]<<" ";
		// 	}cout<<endl;
		// }cout<<endl;
		// for(int i=0;i<K;++i){
		// 	cout<<i<<" "<<pos[i].first.first<<" "<<pos[i].first.second<<" "<<pos[i].second<<endl;
		// }cout<<endl;
		// cout<<turn<<endl;
		// return;
		// if(turn==10){
		// 	break;
		// }
		if(turn>1000){
			return;
		}
	}
}

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	Input();
	solve();
	if(turn>1000){
		cout<<-1;
	}else{
		cout<<turn;
	}
	return 0;
}

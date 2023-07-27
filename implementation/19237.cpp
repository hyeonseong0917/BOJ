#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N,M,K;
const int MAX=20+1;
vector<pair<pair<int,int>,pair<int,int>>> shark; // {{y,x},{상어번호,방향}}
map<pair<int,int>,pair<int,int>> board; // board[{y,x}]={m,n} => {y,x}에 m번 상어의 냄새 n만큼
map<pair<int,int>,vector<int>> prior_dir; //i번 상어의 j번 방향일 때 우선순위
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
void Input(){
	cin>>N>>M>>K;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			int a=0;
			cin>>a;
			if(a>0){
				shark.push_back({{i,j},{a,0}});
			}
		}
	}
	for(int i=1;i<=M;++i){
		int a=0;
		cin>>a;
		for(int j=0;j<M;++j){
			if(shark[j].second.first==i){
				shark[j].second.second=a-1;
			}
		}
	}
	for(int i=1;i<=M;++i){
		for(int j=0;j<4;++j){
			for(int k=0;k<4;++k){
				int a=0;
				cin>>a;
				prior_dir[{i,j}].push_back(a-1);
			}
		}
	}
}
bool comp(pair<pair<int,int>,pair<int,int>> a,pair<pair<int,int>,pair<int,int>> b){
	return a.second.first<b.second.first;
}
void Spread(){
	for(int i=0;i<shark.size();++i){
		int y=shark[i].first.first;
		int x=shark[i].first.second;
		int num=shark[i].second.first;
		board[{y,x}]={num,K};
	}
}
void Move(){
	//아무 냄새가 없는 칸이 있는지?
	for(int i=0;i<shark.size();++i){
		int y=shark[i].first.first;
		int x=shark[i].first.second;
		int num=shark[i].second.first;
		int dir=shark[i].second.second;
		int cnt=0;
		for(int j=0;j<4;++j){
			int ny=y+dy[j];
			int nx=x+dx[j];
			if(isRange(ny,nx) && board[{ny,nx}]==make_pair(0,0)){
				++cnt;
			}
		}
		if(cnt>=1){
			//냄새가 없는 칸이 있는 경우
			vector<int> cur_dir;
				for(int j=0;j<4;++j){
					int ny=y+dy[j];
					int nx=x+dx[j];
					if(isRange(ny,nx) && board[{ny,nx}]==make_pair(0,0)){
						cur_dir.push_back(j);
					}		
				}
				vector<int> cur_prior;
				cur_prior=prior_dir[{num,dir}];
				for(int j=0;j<cur_prior.size();++j){
					bool flag=0;
					for(int k=0;k<cur_dir.size();++k){
						if(cur_prior[j]==cur_dir[k]){
							flag=1;
							shark[i].first.first=y+dy[cur_prior[j]];
							shark[i].first.second=x+dx[cur_prior[j]];
							shark[i].second.second=cur_prior[j];
							break;
						}
					}
					if(flag==1){
						break;
					}
				}
		}else{
			//본인 냄새 칸을 찾는다
			vector<int> cur_dir;
			for(int j=0;j<4;++j){
				int ny=y+dy[j];
				int nx=x+dx[j];
				if(isRange(ny,nx) && board[{ny,nx}].first==num){
					cur_dir.push_back(j);
				}
			}
			vector<int> cur_prior=prior_dir[{num,dir}];
			for(int j=0;j<4;++j){
				bool flag=0;
				for(int k=0;k<cur_dir.size();++k){
					if(cur_prior[j]==cur_dir[k]){
						shark[i].first.first=y+dy[cur_prior[j]];
						shark[i].first.second=x+dx[cur_prior[j]];
						shark[i].second.second=cur_prior[j];
						flag=1;
						break;
					}
				}
				if(flag==1){
					break;
				}
			}
		}
	}
	bool visited[MAX][MAX];
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			visited[i][j]=0;
		}
	}
	vector<pair<pair<int,int>,pair<int,int>>> tmp_shark;
	sort(shark.begin(),shark.end(),comp);
	for(int i=0;i<shark.size();++i){
		int y=shark[i].first.first;
		int x=shark[i].first.second;
		if(!visited[y][x]){
			visited[y][x]=1;
			tmp_shark.push_back(shark[i]);
		}
	}
	shark.clear();
	shark=tmp_shark;
}
void solve(){
	int cnt=0;
	while(1){
		if(cnt>1000){
			cnt=-1;
			break;
		}
		if(shark.size()==1){
			break;
		}
		Spread();
		Move();
		++cnt;
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				if(board[{i,j}].second>0){
					--board[{i,j}].second;
					if(board[{i,j}].second==0){
						board[{i,j}].first=0;
					}
				}
			}
		}
	}
	cout<<cnt;
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//0132
int N=0;
const int MAX=20+1;
vector<int> relation[MAX*MAX];
vector<int> student;
int board[MAX][MAX];
void Input(){
	cin>>N;
	for(int i=0;i<N*N;++i){
		int a=0;
		cin>>a;
		student.push_back(a);
		for(int j=0;j<4;++j){
			int b=0;
			cin>>b;
			relation[a].push_back(b);	
		}
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			board[i][j]=0;
		}
	}
	
}

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
	if(a.second==b.second){
		if(a.first.first==b.first.first){
			return a.first.second<b.first.second;
		}
		return a.first.first<b.first.first;
	}
	return a.second>b.second;
}
void solve(){
	for(int i=0;i<N*N;++i){
		int cur_student=student[i]; //현재 학생
		// cout<<cur_student<<endl;
		vector<int> cur_like; //현재 학생의 좋아하는 사람들
		for(int j=0;j<4;++j){
			cur_like.push_back(relation[cur_student][j]);
		}
		// 어떤 칸이 인접한 칸에 좋아하는 사람이 가장 많을까?
		// 현재 칸을 기준으로 
		vector<pair<pair<int,int>,int>> p;
		for(int j=0;j<N;++j){
			for(int k=0;k<N;++k){
				if(board[j][k]!=0){
					continue;
				}
				int cnt=0;
				for(int m=0;m<4;++m){
					int ny=j+dy[m];
					int nx=k+dx[m];
					if(isRange(ny,nx)){
						for(int n=0;n<4;++n){
							if(board[ny][nx]==cur_like[n]){
								++cnt;
								break;
							}
						}
					}
					// p.push_back({{ny,nx},cnt});
				}
				p.push_back({{j,k},cnt});
			}
		}
		sort(p.begin(),p.end(),comp);
		vector<pair<pair<int,int>,int>> first_filter;
		int maxCnt=p[0].second;
		for(int j=0;j<p.size();++j){
			if(p[j].second==maxCnt){
				first_filter.push_back(p[j]);
			}
		}
		if(first_filter.size()==1){
			board[first_filter[0].first.first][first_filter[0].first.second]=cur_student;
			continue;
		}else{
			vector<pair<pair<int,int>,int>> p2;
			for(int j=0;j<first_filter.size();++j){
				int y=first_filter[j].first.first;
				int x=first_filter[j].first.second;
				int zero_cnt=0;
				for(int k=0;k<4;++k){
					int ny=y+dy[k];
					int nx=x+dx[k];
					if(board[ny][nx]==0 && isRange(ny,nx)){
						++zero_cnt;
					}
				}
				p2.push_back({{y,x},zero_cnt});
			}
			sort(p2.begin(),p2.end(),comp);
			int zero_max_cnt=p2[0].second;
			vector<pair<pair<int,int>,int>> second_filter;
			for(int j=0;j<p2.size();++j){
				if(zero_max_cnt==p2[j].second){
					second_filter.push_back(p2[j]);
				}
			}
			if(second_filter.size()==1){
				board[second_filter[0].first.first][second_filter[0].first.second]=cur_student;
				continue;
			}else{
				sort(second_filter.begin(),second_filter.end(),comp);
				board[second_filter[0].first.first][second_filter[0].first.second]=cur_student;
			}
		}
	}
}
int main() {
	// your code goes here
	Input();
	solve();
	int sum=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			int cur_student=board[i][j];
			int cnt=0;
			for(int k=0;k<4;++k){
				int ny=i+dy[k];
				int nx=j+dx[k];
				if(isRange(ny,nx)){
					for(int n=0;n<4;++n){
						if(board[ny][nx]==relation[cur_student][n]){
							++cnt;
						}
					}
				}
			}
			if(cnt==1){
				sum+=1;
			}else if(cnt==2){
				sum+=10;
			}else if(cnt==3){
				sum+=100;
			}else if(cnt==4){
				sum+=1000;
			}
		}
	}
	cout<<sum;
	return 0;
}
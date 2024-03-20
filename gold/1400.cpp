#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;


int N,M;
int cnt=0;
map<int,vector<vector<char>>> m;
map<int,vector<pair<pair<int,char>,pair<int,int>>>> t;
vector<pair<int,int>> pos(10,{0,0});
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
void traffic(int new_time){
	vector<vector<char>> pre_board=m[new_time-1];
	vector<pair<pair<int,char>,pair<int,int>>> pre_t=t[new_time-1];
	// cout<<pre_t.size()<<"\n";
	for(int i=0;i<pre_t.size();++i){
		int cur_num=pre_t[i].first.first;
		char dir=pre_t[i].first.second;
		int fst_num=pre_t[i].second.first;
		int sed_num=pre_t[i].second.second;
		int y=pos[cur_num].first;
		int x=pos[cur_num].second;
		if(dir=='-'){
			int cur_time=new_time%(fst_num+sed_num+1);
			if(cur_time==fst_num+1){
				pre_t[i].first.second='|';
				
				int ny=y+dy[0];
				int nx=x+dx[0];
				while(1){
					if(!isRange(ny,nx) || pre_board[ny][nx]!='#'){
						break;
					}
					pre_board[ny][nx]='x';
					ny+=dy[0];
					nx+=dx[0];
				}
				ny=y+dy[2];
				nx=x+dx[2];
				while(1){
					if(!isRange(ny,nx) || pre_board[ny][nx]!='#'){
						break;
					}
					pre_board[ny][nx]='x';
					ny+=dy[2];
					nx+=dx[2];
				}
				ny=y+dy[1];
				nx=x+dx[1];
				while(1){
					if(!isRange(ny,nx) || pre_board[ny][nx]!='x'){
						break;
					}
					pre_board[ny][nx]='#';
					ny+=dy[1];
					nx+=dx[1];
				}
				ny=y+dy[3];
				nx=x+dx[3];
				while(1){
					if(!isRange(ny,nx) || pre_board[ny][nx]!='x'){
						break;
					}
					pre_board[ny][nx]='#';
					ny+=dy[3];
					nx+=dx[3];
				}
			}else{
				int ny=y+dy[1];
				int nx=x+dx[1];
				while(1){
					if(!isRange(ny,nx) || pre_board[ny][nx]!='#'){
						break;
					}
					pre_board[ny][nx]='x';
					ny+=dy[1];
					nx+=dx[1];
				}
				ny=y+dy[3];
				nx=x+dx[3];
				while(1){
					if(!isRange(ny,nx) || pre_board[ny][nx]!='#'){
						break;
					}
					pre_board[ny][nx]='x';
					ny+=dy[3];
					nx+=dx[3];
				}
			}
		}else{
			int cur_time=new_time%(fst_num+sed_num+1);
			if(cur_time==sed_num+1){
				pre_t[i].first.second='-';
				int y=pos[cur_num].first;
				int x=pos[cur_num].second;
			
				int ny=y+dy[1];
				int nx=x+dx[1];
				while(1){
					if(!isRange(ny,nx) || pre_board[ny][nx]!='#'){
						break;
					}
					pre_board[ny][nx]='x';
					ny+=dy[1];
					nx+=dx[1];
				}
				ny=y+dy[3];
				nx=x+dx[3];
				while(1){
					if(!isRange(ny,nx) || pre_board[ny][nx]!='#'){
						break;
					}
					pre_board[ny][nx]='x';
					ny+=dy[3];
					nx+=dx[3];
				}
				ny=y+dy[0];
				nx=x+dx[0];
				while(1){
					if(!isRange(ny,nx) || pre_board[ny][nx]!='x'){
						break;
					}
					pre_board[ny][nx]='#';
					ny+=dy[0];
					nx+=dx[0];
				}
				ny=y+dy[2];
				nx=x+dx[2];
				while(1){
					if(!isRange(ny,nx) || pre_board[ny][nx]!='x'){
						break;
					}
					pre_board[ny][nx]='#';
					ny+=dy[2];
					nx+=dx[2];
				}	
			}else{
				int ny=y+dy[0];
				int nx=x+dx[0];
				while(1){
					if(!isRange(ny,nx) || pre_board[ny][nx]!='#'){
						break;
					}
					pre_board[ny][nx]='x';
					ny+=dy[0];
					nx+=dx[0];
				}
				ny=y+dy[2];
				nx=x+dx[2];
				while(1){
					if(!isRange(ny,nx) || pre_board[ny][nx]!='#'){
						break;
					}
					pre_board[ny][nx]='x';
					ny+=dy[2];
					nx+=dx[2];
				}	
			}
		}
	}
	m[new_time]=pre_board;
	t[new_time]=pre_t;
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
		vector<vector<char>> board;
		cnt=0;
		for(int i=0;i<N;++i){
			vector<char> tmp;
			for(int j=0;j<M;++j){
				char a=0;
				cin>>a;
				if('0'<=a && a<='9'){
					++cnt;
					pos[a-'0']={i,j};
				}
				tmp.push_back(a);
			}
			board.push_back(tmp);
		}
		m[0]=board;
		vector<pair<pair<int,char>,pair<int,int>>> cur_t;
		for(int i=0;i<cnt;++i){
			int a,b,c;
			char d;
			cin>>a>>d>>b>>c;
			cur_t.push_back({{a,d},{b,c}});
		}
		// cout<<cur_t.size()<<"\n";
		t[0]=cur_t;
		// traffic(1);
		for(int i=1;i<=6;++i){
			traffic(i);
			vector<vector<char>> a=m[i];
			cout<<i<<"\n";
			for(int j=0;j<N;++j){
				for(int k=0;k<M;++k){
					cout<<a[j][k];
				}cout<<"\n";
			}cout<<"\n";
		}
	}
	return 0;
}
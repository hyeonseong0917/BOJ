#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

#define ll long long


int R,C;
const int MAX=100+1;
string board[MAX];
char ans[MAX][MAX];
int dy[9]={1,1,1,0,0,0,-1,-1,-1};
int dx[9]={-1,0,1,-1,0,1,-1,0,1};
pair<int,int> pos;
vector<pair<int,int>> r_pos;
vector<int> dir;
void Input(){
	cin>>R>>C;
	for(int i=0;i<R;++i){
		cin>>board[i];
		for(int j=0;j<C;++j){
			if(board[i][j]=='I'){
				pos={i,j};
			}
			if(board[i][j]=='R'){
				r_pos.push_back({i,j});
			}
		}
	}
	string s;
	cin>>s;
	for(int i=0;i<s.size();++i){
		char c=s[i];
		dir.push_back((c-'0')-1);
	}
	// for(int i=0;i<dir.size();++i){
	// 	cout<<dir[i]<<" ";
	// }
}
int taxi_dist(int y1, int x1, int y2, int x2){
	return (abs(y1-y2)+abs(x1-x2));
}
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<R && x<C);
}
map<pair<int,int>,int> m;
vector<pair<int,int>> new_r_pos;
void solve(){
	bool flag=0;
	int cnt=0;
	for(int i=0;i<dir.size();++i){
		++cnt;
		// i움직이기
		int cur_dir=dir[i];
		int py=pos.first+dy[cur_dir];
		int px=pos.second+dx[cur_dir];
		pos.first=py;
		pos.second=px;
		// R움직이기
		m.clear();
		new_r_pos.clear();		
		for(int j=0;j<r_pos.size();++j){
			int ry=r_pos[j].first;
			int rx=r_pos[j].second;
			int cur_dist=122232421;
			int ty=-1;
			int tx=-1;
			for(int k=0;k<9;++k){
				int nry=ry+dy[k];
				int nrx=rx+dx[k];
				if(!isRange(nry, nrx)) continue;
				if(cur_dist>=taxi_dist(py, px, nry, nrx)){
					cur_dist=taxi_dist(py, px, nry, nrx);
					ty=nry;
					tx=nrx;
				}
			}
			if(ty==-1 && tx==-1) continue;
			if(ty==pos.first && tx==pos.second){
				flag=1;
				break;
			}
			++m[{ty,tx}];
			new_r_pos.push_back({ty,tx});
		}
		if(flag){
			break;
		}
		
		r_pos.clear();
		for(int j=0;j<new_r_pos.size();++j){
			if(m[new_r_pos[j]]==1){
				r_pos.push_back(new_r_pos[j]);	
			}
			
		}
		// for(int i=0;i<r_pos.size();++i){
		// 	cout<<r_pos[i].first<<" "<<r_pos[i].second<<endl;
		// }

	}
	if(flag){
		cout<<"kraj "<<cnt;
	}else{
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				ans[i][j]='.';
			}
		}
		// cout<<pos.first<<" "<<pos.second<<endl;
		ans[pos.first][pos.second]='I';
		for(int i=0;i<r_pos.size();++i){
			int y=r_pos[i].first;
			int x=r_pos[i].second;
			ans[y][x]='R';
		}
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				cout<<ans[i][j];
			}cout<<"\n";
		}
	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	

	return 0;
}
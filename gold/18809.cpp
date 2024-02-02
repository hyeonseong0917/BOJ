#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int N,M,G,R;
const int MAX=50+1;
int board[MAX][MAX];
vector<string> rgcomb;
map<string,int> rgmap;
vector<pair<int,int>> seed_pos;
int seed_size=0;
void Input(){
	cin>>N>>M>>G>>R;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
			if(board[i][j]==2){
				seed_pos.push_back({i,j});
			}
		}
	}
	seed_size=seed_pos.size();
}
void rg_generate(int g, int r, string s){
	if(g==0 && r==0){
		if(!rgmap[s]){
			rgmap[s]=1;
			rgcomb.push_back(s);
		}
		return;
	}
	if(g>0){
		rg_generate(g-1,r,s+'g');
		
	}
	if(r>0){
		rg_generate(g,r-1,s+'r');
	}
}
vector<int> seed_idx;
bool visited[10+1];
char seed_board[MAX][MAX];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
int max_flower(){
	queue<pair<int,int>> q;
	for(int j=0;j<seed_idx.size();++j){
		q.push({seed_pos[seed_idx[j]].first, seed_pos[seed_idx[j]].second});
	}
	int cnt=0;
	// for(int i=0;i<N;++i){
	// 	for(int j=0;j<M;++j){
	// 		cout<<seed_board[i][j];
	// 	}cout<<endl;
	// }
	// cout<<"-----------------"<<endl;
	while(!q.empty()){
		int qs=q.size();
		map<pair<int,int>,int> m;
		vector<pair<int,int>> v;
		v.clear();
		for(int i=0;i<qs;++i){
			int y=q.front().first;
			int x=q.front().second;
			char c=seed_board[y][x];
			// if(c==' '){
			// 	cout<<"FENIFOWENFIOEWNFIOEWNFO";
			// }
			q.pop();
			for(int j=0;j<4;++j){
				int ny=y+dy[j];
				int nx=x+dx[j];
				if(!isRange(ny,nx)) continue;
				if(board[ny][nx]==0) continue;
				if(seed_board[ny][nx]=='f') continue;
				if(board[ny][nx]==1 || board[ny][nx]==2){
					if(seed_board[ny][nx]==' '){
						seed_board[ny][nx]=c;
						v.push_back({ny,nx});
						m[{ny,nx}]=1;
					}else{
						if(seed_board[ny][nx]!=c && m[{ny,nx}]==1){
							// seed_board[ny][nx]가 따끈따끈한 상태인지 어떻게 알까?
							seed_board[ny][nx]='f';
							m[{ny,nx}]=2;
						}
					}
					continue;
				}
			}
		}
		for(int i=0;i<v.size();++i){
			int y=v[i].first;
			int x=v[i].second;

			if(m[{y,x}]==1){
				q.push({y,x});
			}
		}
		// cout<<v.size()<<endl;
		// for(int i=0;i<N;++i){
		// 	for(int j=0;j<M;++j){
		// 		cout<<seed_board[i][j];
		// 	}cout<<endl;
		// }
		// cout<<"-------------"<<endl;
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(seed_board[i][j]=='f'){
				++cnt;
			}
		}
	}
	// cout<<cnt<<endl;
	return cnt;
}
int ans=0;
void pick(int idx, int cnt){
	if(cnt==(G+R)){
		// for(int i=0;i<cnt;++i){
		// 	cout<<seed_idx[i]<<" ";
		// }cout<<endl;
		for(int i=0;i<rgcomb.size();++i){
			string cur_str=rgcomb[i];
			for(int j=0;j<N;++j){
				for(int k=0;k<M;++k){
					seed_board[j][k]=' ';
				}
			}
			for(int j=0;j<cnt;++j){
				// cur_str[j]와 seed_pos[seed_idx]를 매칭
				int y=seed_pos[seed_idx[j]].first;
				int x=seed_pos[seed_idx[j]].second;
				char c=cur_str[j];
				seed_board[y][x]=c;
			}	

			// for(int j=0;j<N;++j){
			// 	for(int k=0;k<M;++k){
			// 		cout<<seed_board[j][k];
			// 	}cout<<endl;
			// }
			ans=max(ans,max_flower());
		}
		
		return;
	}
	if(idx==seed_size){
		return;
	}
	for(int i=idx;i<seed_size;++i){
		if(!visited[i]){
			visited[i]=1;
			seed_idx.push_back(i);
			pick(i+1,cnt+1);
			seed_idx.pop_back();
			visited[i]=0;
		}
	}
}
void solve(){
	rg_generate(G,R,"");
	pick(0,0);
	cout<<ans;
}



int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	// cout<<rgcomb.size()<<endl;
	// for(int i=0;i<rgcomb.size();++i){
	// 	cout<<rgcomb[i]<<endl;
	// }

	return 0;
}
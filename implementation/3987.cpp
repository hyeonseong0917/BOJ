#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
const int MAX=500+1;
char board[MAX][MAX];
bool visited[MAX][MAX][4];
pair<int,int> origin_pos;
pair<int,int> cur_pos;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y ,int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
		}
	}
	int y=0,x=0;
	cin>>y>>x;
	origin_pos=make_pair(y-1,x-1);
}
int get_time(int dir){
	int cnt=1;
	int y=origin_pos.first;
	int x=origin_pos.second;
	int ny=y;
	int nx=x;
	visited[ny][nx][dir]=1;
	// cout<<"DIR"<<endl;
	// cout<<dir<<endl;
	while(1){
		ny+=dy[dir];
		nx+=dx[dir];
		// cout<<ny<<" "<<nx<<endl;
		
		if(!isRange(ny,nx) || board[ny][nx]=='C'){
			return cnt;
		}
		// cout<<visited[ny][nx]<<endl;
		if(visited[ny][nx][dir] && (board[ny][nx]=='/' || board[ny][nx]=='\\')){
			
			return 1222324211;
		}
		visited[ny][nx][dir]=1;
		++cnt;
		if(board[ny][nx]=='/'){
			if(dir==0){
				dir=1;
			}else if(dir==1){
				dir=0;
			}else if(dir==2){
				dir=3;
			}else if(dir==3){
				dir=2;
			}
		}
		if(board[ny][nx]=='\\'){
			if(dir==0){
				dir=3;
			}else if(dir==1){
				dir=2;
			}else if(dir==2){
				dir=1;
			}else if(dir==3){
				dir=0;
			}
		}
		
	}
	
}
bool comp(pair<int,int> a, pair<int,int> b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second>b.second;
}
void solve(){
	int ans=0;
	vector<pair<int,int>> v;
	bool flag=0;
	for(int i=0;i<4;++i){
		for(int j=0;j<MAX;++j){
			for(int k=0;k<MAX;++k){
				for(int p=0;p<4;++p){
					visited[j][k][p]=0;	
				}
				
			}
		}
		cur_pos=origin_pos;
		int curNum=get_time(i);
		v.push_back({i,curNum});
		// cout<<curNum<<endl;
	}
	sort(v.begin(),v.end(),comp);
	char DIR[4]={'U','R','D','L'};
	if(v[0].second==1222324211){
		cout<<DIR[v[0].first]<<endl;
		cout<<"Voyager";	
	}else{
		cout<<DIR[v[0].first]<<endl;
		cout<<v[0].second;	
	}
	
	
}


int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}
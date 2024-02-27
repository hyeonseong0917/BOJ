#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

#define ll long long

int N,M,R;
const int MAX=100+1;
int board[MAX][MAX];
vector<pair<pair<int,int>,int>> atk;
vector<pair<int,int>> def;
bool check[MAX][MAX];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<M);
}
void Input(){
	cin>>N>>M>>R;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
		}
	}
	for(int i=0;i<R*2;++i){
		if(i%2==0){
			int a,b,dir;
			char c;
			cin>>a>>b>>c;
			if(c=='N'){
				dir=0;
			}else if(c=='E'){
				dir=1;
			}else if(c=='S'){
				dir=2;
			}else{
				dir=3;
			}
			atk.push_back({{a-1,b-1},dir});
		}else{
			int a,b;
			cin>>a>>b;
			def.push_back({a-1,b-1});
		}
	}
}
void solve(){
	int sum=0;
	
	for(int i=0;i<R;++i){
		// i번째 라운드 시작
		int y=atk[i].first.first;
		int x=atk[i].first.second;
		int dir=atk[i].second;
		int K=board[y][x];
		if(check[y][x]) continue; // 이미 넘어져 있음
		check[y][x]=1;
		queue<pair<int,int>> cur_domi;
		cur_domi.push({y,x});
		int cnt=1;
		while(!cur_domi.empty()){
			int ny=cur_domi.front().first;
			int nx=cur_domi.front().second;
			int cur_size=board[ny][nx];
			cur_domi.pop();
			for(int j=0;j<cur_size-1;++j){
				ny+=dy[dir];
				nx+=dx[dir];
				if(!isRange(ny,nx)) break;
				if(check[ny][nx]) continue;
				check[ny][nx]=1;
				cur_domi.push({ny,nx});
				++cnt;
			}	
		}
		sum+=cnt;
		int dy=def[i].first;
		int dx=def[i].second;
		check[dy][dx]=0;
	}
	cout<<sum<<"\n";
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(check[i][j]){
				cout<<"F";
			}else{
				cout<<"S";
			}
			if(j!=M-1){
				cout<<" ";
			}
		}
		cout<<"\n";
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
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int N=0,K=0;
const int MAX=100+1;
int board[MAX][MAX]={0,};
int L=0;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
deque<pair<int,int>> dq;
int dir=3;
bool flag=0;
pair<int,char> p[100+1];
void Input(){
	cin>>N;
	cin>>K;
	for(int i=0;i<K;++i){
		int a,b=0;
		cin>>a>>b;
		board[a-1][b-1]=-1;
	}
	cin>>L;
	dq.push_front({0,0});
	board[0][0]=1;
	for(int i=0;i<L;++i){
		cin>>p[i].first>>p[i].second;
	}
}
bool isRange(int y, int x){
	return (y>=0 && x>=0 && y<N && x<N);
}
int curTime=0;
void simulation(int t, char c){ //t초가 지난  후 c 방향으로 변환
	for(int i=curTime;i<t;++i){
		int ny=dq.front().first+dy[dir];
		int nx=dq.front().second+dx[dir];
		++curTime;
		// cout<<ny<<" "<<nx<<" "<<curTime<<endl;
		// cout<<curTime<<endl;
		if(!isRange(ny,nx)){
			flag=1;
			break;
		}
		if(board[ny][nx]==-1){
			dq.push_front({ny,nx});
			board[ny][nx]=1;
		}else if(board[ny][nx]==0){
			dq.push_front({ny,nx});
			board[ny][nx]=1;
			int preY=dq.back().first;
			int preX=dq.back().second;
			board[preY][preX]=0;
			dq.pop_back();
		}else if(board[ny][nx]==1){
			flag=1;
			break;
		}
		
	}
	
	if(flag==1){
		
		return;
	}
	if(c=='X'){
		return;
	}
	if(c=='L'){
		if(dir==0){
			dir=2;
		}else if(dir==1){
			dir=3;
		}else if(dir==2){
			dir=1;
		}else if(dir==3){
			dir=0;
		}
		return;
	}
	if(c=='D'){
		if(dir==0){
			dir=3;
		}else if(dir==1){
			dir=2;
		}else if(dir==2){
			dir=0;
		}else if(dir==3){
			dir=1;
		}
	}
}

void solve(){
	for(int i=0;i<L;++i){
		int a=p[i].first;
		char c=p[i].second;
		simulation(a,c);
		if(flag==1){
			break;
		}
	}
	if(flag==1){
		cout<<curTime;
	}else{
		while(flag==0){
			simulation(20001,'X');
		}
		cout<<curTime;
	}
	
	// simulation(3,'D');
	// simulation(15,'L');
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}